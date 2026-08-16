#include <stdlib.h>

typedef struct {
    int num;
    int freq;
} Pair;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Pair heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent].freq <= heap[index].freq)
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(Pair heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size &&
            heap[left].freq < heap[smallest].freq)
            smallest = left;

        if (right < size &&
            heap[right].freq < heap[smallest].freq)
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int freq[20001] = {0};

    // Count frequency
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 10000]++;
    }

    Pair *heap = malloc(k * sizeof(Pair));
    int size = 0;

    // Build min heap of size k
    for (int i = 0; i < 20001; i++) {
        if (freq[i] == 0)
            continue;

        Pair p;
        p.num = i - 10000;
        p.freq = freq[i];

        if (size < k) {
            heap[size] = p;
            heapifyUp(heap, size);
            size++;
        }
        else if (p.freq > heap[0].freq) {
            heap[0] = p;
            heapifyDown(heap, size, 0);
        }
    }

    int *result = malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        result[i] = heap[i].num;
    }

    *returnSize = k;

    free(heap);

    return result;
}
