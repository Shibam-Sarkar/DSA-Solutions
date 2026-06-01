void reverse_arr(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    if (k == 0) return;  // ← no rotation needed

    reverse_arr(nums, 0, numsSize - 1);  // reverse whole
    reverse_arr(nums, 0, k - 1);         // reverse first k
    reverse_arr(nums, k, numsSize - 1);  // reverse rest
}
