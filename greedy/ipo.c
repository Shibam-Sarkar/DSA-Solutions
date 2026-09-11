#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return ((int *)a)[0] - ((int *)b)[0];
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    int n = profitsSize;

    int (*projects)[2] = malloc(n * sizeof(*projects));

    for (int i = 0; i < n; i++) {
        projects[i][0] = capital[i];
        projects[i][1] = profits[i];
    }

    qsort(projects, n, sizeof(projects[0]), cmp);

    int *heap = malloc(n * sizeof(int));
    int size = 0;
    int j = 0;

    for (int count = 0; count < k; count++) {
        while (j < n && projects[j][0] <= w) {
            int i = size++;
            heap[i] = projects[j][1];

            while (i > 0) {
                int p = (i - 1) / 2;
                if (heap[p] >= heap[i])
                    break;

                int temp = heap[p];
                heap[p] = heap[i];
                heap[i] = temp;
                i = p;
            }

            j++;
        }

        if (size == 0)
            break;

        w += heap[0];

        heap[0] = heap[--size];

        int i = 0;

        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;

            i = largest;
        }
    }

    free(projects);
    free(heap);

    return w;
}
