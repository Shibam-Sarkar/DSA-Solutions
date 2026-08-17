#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} Word;

int cmpWord(const void *a, const void *b) {
    Word *x = (Word *)a;
    Word *y = (Word *)b;

    if (x->count != y->count)
        return y->count - x->count;

    return strcmp(x->word, y->word);
}

char** topKFrequent(char** words, int wordsSize, int k, int* returnSize) {
    
    Word *arr = malloc(wordsSize * sizeof(Word));
    int n = 0;

    for (int i = 0; i < wordsSize; i++) {
        int found = -1;

        for (int j = 0; j < n; j++) {
            if (strcmp(arr[j].word, words[i]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            arr[found].count++;
        } else {
            arr[n].word = words[i];
            arr[n].count = 1;
            n++;
        }
    }

    qsort(arr, n, sizeof(Word), cmpWord);

    // Create result
    char **result = malloc(k * sizeof(char *));

    for (int i = 0; i < k; i++) {
        result[i] = arr[i].word;
    }

    *returnSize = k;

    free(arr);

    return result;
}
