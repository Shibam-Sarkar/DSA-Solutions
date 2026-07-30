
int findBound(int* nums, int numsSize, int target, int isFirst) {
    int lo = 0, hi = numsSize - 1;
    int result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            result = mid;
            if (isFirst) {
                hi = mid - 1;  
            } else {
                lo = mid + 1;  
            }
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return result;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    int first = findBound(nums, numsSize, target, 1);
    if (first == -1) {
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    int last = findBound(nums, numsSize, target, 0);
    result[0] = first;
    result[1] = last;
    return result;
}
