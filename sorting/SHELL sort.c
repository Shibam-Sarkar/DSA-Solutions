#include <stdio.h>

void shellSort(int a[], int n) {
    int gap, i, j;

    for (gap = n / 2; gap >= 1; gap = gap / 2) {

        for (j = gap; j < n; j++) {

            for (i = j - gap; i >= 0; i = i - gap) {

                if (a[i] <= a[i + gap]) {
                    break;
                }
                else {
                    int temp = a[i];
                    a[i] = a[i + gap];
                    a[i + gap] = temp;
                }
            }
        }
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

    shellSort(a, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
