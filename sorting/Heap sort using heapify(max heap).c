#include <stdio.h>

// Heapify function (max-heap)
void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;   // for 0-based index
    int right = 2*i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n) {
    // Build max heap (bottom-up)
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        // Call heapify on reduced heap
        heapify(A, i, 0);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    heapSort(A, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
