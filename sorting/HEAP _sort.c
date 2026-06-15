#include <stdio.h>

void insertHeap(int A[], int *n, int value) {
    *n = *n + 1;
    A[*n] = value;

    int i = *n;

    while (i > 1) {
        int parent = i / 2;

        if (A[parent] < A[i]) {
            int temp = A[parent];
            A[parent] = A[i];
            A[i] = temp;

            i = parent;
        }
        else {
            return;
        }
    }
}

void heapifyDown(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && A[left] > A[largest])
        largest = left;

    if (right <= n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapifyDown(A, n, largest);
    }
}

int deleteRoot(int A[], int *n) {
    int maxValue = A[1];
    A[1] = A[*n];
    *n = *n - 1;

    heapifyDown(A, *n, 1);
    return maxValue;
}

int main() {
    int A[100];
    int n = 0;

    int count;
    printf("Enter number of elements: ");
    scanf("%d", &count);

    printf("Enter %d values:\n", count);
    for (int i = 0; i < count; i++) {
        int value;
        scanf("%d", &value);
        insertHeap(A, &n, value);   
    }

    int sorted[100];
    int s = 0;

    while (n > 0) {
        sorted[s++] = deleteRoot(A, &n);
    }

    printf("\nSorted array:\n");
    for (int i = s - 1; i >= 0; i--) {  
        printf("%d ", sorted[i]);
    }

    return 0;
}
