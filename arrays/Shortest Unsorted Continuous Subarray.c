int findUnsortedSubarray(int* nums, int numsSize) {
    int max_seen = INT_MIN;
    int min_seen = INT_MAX;
    int left = 0, right = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_seen) max_seen = nums[i];
        if (nums[i] < max_seen) right = i;
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] < min_seen) min_seen = nums[i];
        if (nums[i] > min_seen) left = i;
    }

    return right == -1 ? 0 : right - left + 1;
}
