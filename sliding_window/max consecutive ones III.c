int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int zeros = 0;
    int maxLen = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zeros++;
        }

        while (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}
