#include <stdlib.h>

static void countAndMerge(long long *prefix, int left, int right, int lower, int upper, int *count) {
    if (right - left <= 1) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    countAndMerge(prefix, left, mid, lower, upper, count);
    countAndMerge(prefix, mid, right, lower, upper, count);
    
    int lo = mid, hi = mid;
    for (int i = left; i < mid; i++) {
        while (lo < right && prefix[lo] - prefix[i] < lower) lo++;
        while (hi < right && prefix[hi] - prefix[i] <= upper) hi++;
        *count += (hi - lo);
    }
    
    long long *merged = (long long *)malloc((right - left) * sizeof(long long));
    int p1 = left, p2 = mid, idx = 0;
    while (p1 < mid && p2 < right) {
        if (prefix[p1] <= prefix[p2]) {
            merged[idx++] = prefix[p1++];
        } else {
            merged[idx++] = prefix[p2++];
        }
    }
    while (p1 < mid) merged[idx++] = prefix[p1++];
    while (p2 < right) merged[idx++] = prefix[p2++];
    
    for (int i = 0; i < idx; i++) {
        prefix[left + i] = merged[i];
    }
    
    free(merged);
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    int n = numsSize;
    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    int count = 0;
    countAndMerge(prefix, 0, n + 1, lower, upper, &count);
    
    free(prefix);
    
    return count;
}
