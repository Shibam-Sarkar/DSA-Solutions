#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    return intervalA[0] - intervalB[0];
}

int doIntervalsIntersect(int arr[][2], int n) {
    int *ptrs[n];
    for (int i = 0; i < n; i++)
        ptrs[i] = arr[i];

    qsort(ptrs, n, sizeof(int *), compare);

    for (int i = 1; i < n; i++) {
        if (ptrs[i][0] < ptrs[i - 1][1]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int arr[n][2];
    for (int i = 0; i < n; i++) {
        printf("Enter start and end for interval %d: ", i + 1);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    printf("%s\n", doIntervalsIntersect(arr, n) ? "True" : "False");

    return 0;
}
