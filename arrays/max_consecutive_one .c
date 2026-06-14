int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_count = 0;
    int curr_count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            curr_count++;
            if (curr_count > max_count)
                max_count = curr_count;
        } else {
            curr_count = 0;
        }
    }

    return max_count;
}
