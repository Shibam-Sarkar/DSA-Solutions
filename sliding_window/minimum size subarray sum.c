int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0;
    int current_sum = 0;
    int min_length = numsSize + 1;
    int right, window;

    for (right = 0; right < numsSize; right++) {
        current_sum += nums[right];

        while (current_sum >= target) {
            window = right - left + 1;
            if (window < min_length)
                min_length = window;
            current_sum -= nums[left];
            left++;
        }
    }

    return min_length == numsSize + 1 ? 0 : min_length;
}
