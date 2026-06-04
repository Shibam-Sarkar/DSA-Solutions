int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int pos = 0, neg = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[pos] = nums[i];
            pos += 2;
        } else {
            result[neg] = nums[i];
            neg += 2;
        }
    }

    return result;
}
