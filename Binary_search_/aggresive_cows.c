#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlaceCows(int arr[], int n, int k, int dist) {
    int count = 1;          // place the first cow at arr[0]
    int lastPos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= dist) {
            count++;
            lastPos = arr[i];
            if (count >= k) return 1;
        }
    }
    return (count >= k);
}

int aggressiveCows(int arr[], int n, int k) {
    qsort(arr, n, sizeof(int), cmpfunc);

    int lo = 0;
    int hi = arr[n - 1] - arr[0];
    int ans = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (canPlaceCows(arr, n, k, mid)) {
            ans = mid;       // mid is achievable, try for a larger distance
            lo = mid + 1;
        } else {
            hi = mid - 1;    // mid too large, reduce
        }
    }

    return ans;
}
