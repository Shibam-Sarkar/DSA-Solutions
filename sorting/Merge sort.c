#include <stdio.h>

void Merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;

    int b[1000];

    while (i <= mid && j <= ub) {

        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        while (j <= ub) {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else {
        while (i <= mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for (int x = lb; x <= ub; x++) {
        a[x] = b[x];
    }
}

void MergeSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        MergeSort(a, lb, mid);
        MergeSort(a, mid + 1, ub);
        Merge(a, lb, mid, ub);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    MergeSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
