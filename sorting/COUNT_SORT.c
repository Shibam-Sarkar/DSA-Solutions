#include <stdio.h>

void countSort(int a[], int n, int k) {
    int count[k + 1];
    int b[n];

    for (int i = 0; i <= k; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        b[--count[a[i]]] = a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements (non-negative integers):\n");
    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > maxVal) {
            maxVal = a[i];
        }
    }
    k = maxVal;

    countSort(a, n, k);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
