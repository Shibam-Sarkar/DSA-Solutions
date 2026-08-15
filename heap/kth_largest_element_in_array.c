int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int pivot = nums[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }

        int temp = nums[i];
        nums[i] = nums[right];
        nums[right] = temp;

        if (i == target) {
            return nums[i];
        } 
        else if (i < target) {
            left = i + 1;
        } 
        else {
            right = i - 1;
        }
    }

    return -1;
}
