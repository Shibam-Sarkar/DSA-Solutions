#include <limits.h>
static int canSplit(int* nums, int numsSize, int k, long long maxSum) {
    int count = 1;
    long long current = 0;
    for (int i = 0; i < numsSize; i++) {
        if (current + nums[i] > maxSum) {
            count++;
            current = nums[i];
            if (count > k) return 0;
        } else {
            current += nums[i];
        }
    }
    return 1;
}

int splitArray(int* nums, int numsSize, int k) {
    long long lo = 0, hi = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > lo) lo = nums[i];  // lo = max element
        hi += nums[i];                    // hi = total sum
    }
    
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canSplit(nums, numsSize, k, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    return (int)lo;
}
