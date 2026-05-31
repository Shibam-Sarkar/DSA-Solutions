void nextPermutation(int* nums, int numsSize) {
    int pivot = -1;

    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
    if (pivot != -1) {
        for (int j = numsSize - 1; j > pivot; j--) {
            if (nums[j] > nums[pivot]) {
                int tmp = nums[pivot];
                nums[pivot] = nums[j];
                nums[j] = tmp;
                break;
            }
        }
    }
    int left = pivot + 1, right = numsSize - 1;
    while (left < right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
