int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int* result = (int*)malloc(n * sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int)); 
    int top = -1;

    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < 2 * n; i++) {
        int idx = i % n;
        while (top != -1 && nums[stack[top]] < nums[idx]) {
            result[stack[top]] = nums[idx];
            top--;
        }
        if (i < n) {
            stack[++top] = idx;
        }
    }

    free(stack);
    *returnSize = n;
    return result;
}
