#include <stdlib.h>
#include <string.h>

typedef struct {
    const char* key; 
    int count;
    int used;
} Entry;

static unsigned int hash_key(const char* key, int len, unsigned int capacity) {
    unsigned int h = 2166136261u;
    for (int i = 0; i < len; i++) {
        h ^= (unsigned char)key[i];
        h *= 16777619u;
    }
    return h & (capacity - 1);
}

static int find_slot(Entry* table, unsigned int capacity, const char* key, int len) {
    unsigned int idx = hash_key(key, len, capacity);
    while (table[idx].used) {
        if (memcmp(table[idx].key, key, len) == 0) {
            return (int)idx;
        }
        idx = (idx + 1) & (capacity - 1);
    }
    return (int)idx;
}

static unsigned int next_pow2(unsigned int n) {
    unsigned int p = 1;
    while (p < n) p <<= 1;
    return p;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if (s == NULL || wordsSize == 0) return NULL;

    int wordLen   = (int)strlen(words[0]);
    int numWords  = wordsSize;
    int totalLen  = wordLen * numWords;
    int n         = (int)strlen(s);

    if (wordLen == 0 || totalLen > n) return NULL;

    unsigned int capacity = next_pow2((unsigned int)(numWords * 2 < 16 ? 16 : numWords * 2));

    Entry* wordCount = (Entry*)calloc(capacity, sizeof(Entry));
    Entry* window    = (Entry*)calloc(capacity, sizeof(Entry));
    if (!wordCount || !window) { free(wordCount); free(window); return NULL; }

    for (int i = 0; i < numWords; i++) {
        int idx = find_slot(wordCount, capacity, words[i], wordLen);
        if (wordCount[idx].used) {
            wordCount[idx].count++;
        } else {
            wordCount[idx].key   = words[i];
            wordCount[idx].count = 1;
            wordCount[idx].used  = 1;
        }
    }

    int  capacityResult = 16;
    int* result = (int*)malloc(sizeof(int) * capacityResult);
    int  resultSize = 0;

    for (int offset = 0; offset < wordLen; offset++) {
        memset(window, 0, sizeof(Entry) * capacity);

        int left  = offset;
        int count = 0;

        for (int right = offset; right <= n - wordLen; right += wordLen) {
            const char* word = s + right;
            int wcIdx = find_slot(wordCount, capacity, word, wordLen);

            if (wordCount[wcIdx].used) {
                int winIdx = find_slot(window, capacity, word, wordLen);
                if (window[winIdx].used) {
                    window[winIdx].count++;
                } else {
                    window[winIdx].key   = word;
                    window[winIdx].count = 1;
                    window[winIdx].used  = 1;
                }
                count++;

                while (window[winIdx].count > wordCount[wcIdx].count) {
                    const char* leftWord = s + left;
                    int lwIdx = find_slot(window, capacity, leftWord, wordLen);
                    window[lwIdx].count--;
                    count--;
                    left += wordLen;
                }

                if (count == numWords) {
                    if (resultSize == capacityResult) {
                        capacityResult *= 2;
                        result = (int*)realloc(result, sizeof(int) * capacityResult);
                    }
                    result[resultSize++] = left;

                    const char* leftWord = s + left;
                    int lwIdx = find_slot(window, capacity, leftWord, wordLen);
                    window[lwIdx].count--;
                    count--;
                    left += wordLen;
                }
            } else {
                memset(window, 0, sizeof(Entry) * capacity);
                count = 0;
                left = right + wordLen;
            }
        }
    }

    free(wordCount);
    free(window);

    *returnSize = resultSize;
    return result;
}
