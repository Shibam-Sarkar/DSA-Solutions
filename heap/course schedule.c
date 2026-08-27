#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(int *heap, int *size, int x) {
    int i = (*size)++;
    heap[i] = x;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

int popMax(int *heap, int *size) {
    int max = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < *size && heap[left] > heap[largest])
            largest = left;

        if (right < *size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    return max;
}

int compare(const void *a, const void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[1] - y[1];
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    
    // Sort courses by lastDay
    qsort(courses, coursesSize, sizeof(int *), compare);

    // Max heap for durations
    int *heap = malloc(coursesSize * sizeof(int));
    int heapSize = 0;

    int totalTime = 0;

    for (int i = 0; i < coursesSize; i++) {
        int duration = courses[i][0];
        int lastDay = courses[i][1];

        totalTime += duration;
        push(heap, &heapSize, duration);

        // If deadline is exceeded,
        // remove the longest course
        if (totalTime > lastDay) {
            totalTime -= popMax(heap, &heapSize);
        }
    }

    free(heap);

    return heapSize;
}
