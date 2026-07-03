#include <stdlib.h>
#include <string.h>

typedef struct {
    const char* key; 
    int count;
    int used;
} Entry;

static unsigned long hashWord(const char* str, int len) {
    unsigned long hash = 14695981039346656037UL; // FNV-1a
    for (int i = 0; i < len; i++) {
        hash ^= (unsigned char)str[i];
        hash *= 1099511628211UL;
    }
    return hash;
}

static int findSlot(Entry* table, int cap, int wl, const char* key) {
    unsigned long h = hashWord(key, wl);
    int idx = (int)(h & (cap - 1));
    while (table[idx].used && strncmp(table[idx].key, key, wl) != 0) {
        idx = (idx + 1) & (cap - 1);
    }
    return idx;
}

static int nextPow2(int x) {
    int p = 1;
    while (p < x) p <<= 1;
    return p;
}
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    int n = strlen(s);
    if (wordsSize == 0 || n == 0) return NULL;

    int wl = strlen(words[0]);
    int totalLen = wl * wordsSize;
    if (wl == 0 || totalLen > n) return NULL;

    int cap = nextPow2(wordsSize * 4 + 1);
    Entry* need = (Entry*)calloc(cap, sizeof(Entry));
    Entry* window = (Entry*)calloc(cap, sizeof(Entry));

    
    for (int i = 0; i < wordsSize; i++) {
        int idx = findSlot(need, cap, wl, words[i]);
        if (!need[idx].used) {
            need[idx].used = 1;
            need[idx].key = words[i];
            need[idx].count = 1;
        } else {
            need[idx].count++;
        }
    }

    int* result = (int*)malloc(sizeof(int) * n); 
    int resSize = 0;

    for (int offset = 0; offset < wl; offset++) {
        memset(window, 0, sizeof(Entry) * cap);
        int left = offset;
        int count = 0;

        for (int right = offset; right + wl <= n; right += wl) {
            const char* word = s + right;
            int needIdx = findSlot(need, cap, wl, word);

            if (need[needIdx].used) {
                int winIdx = findSlot(window, cap, wl, word);
                if (!window[winIdx].used) {
                    window[winIdx].used = 1;
                    window[winIdx].key = word;
                    window[winIdx].count = 1;
                } else {
                    window[winIdx].count++;
                }
                count++;

                while (window[winIdx].count > need[needIdx].count) {
                    const char* leftWord = s + left;
                    int lwinIdx = findSlot(window, cap, wl, leftWord);
                    window[lwinIdx].count--;
                    left += wl;
                    count--;
                }

                if (count == wordsSize) {
                    result[resSize++] = left;
                    const char* leftWord = s + left;
                    int lwinIdx = findSlot(window, cap, wl, leftWord);
                    window[lwinIdx].count--;
                    left += wl;
                    count--;
                }
            } else {
                memset(window, 0, sizeof(Entry) * cap);
                count = 0;
                left = right + wl;
            }
        }
    }

    free(need);
    free(window);

    *returnSize = resSize;
    if (resSize == 0) {
        free(result);
        return NULL;
    }
    return result;
}
