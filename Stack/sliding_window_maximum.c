nt* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int* deque = (int*)malloc(sizeof(int) * numsSize);
    int front = 0, back = -1;
    
    int resultCount = numsSize - k + 1;
    int* result = (int*)malloc(sizeof(int) * resultCount);
    int ri = 0;
    
    for (int i = 0; i < numsSize; i++) {
        while (front <= back && deque[front] <= i - k) {
            front++;
        }
        
        while (front <= back && nums[deque[back]] < nums[i]) {
            back--;
        }
        
        deque[++back] = i;
        
        if (i >= k - 1) {
            result[ri++] = nums[deque[front]];
        }
    }
    
    free(deque);
    *returnSize = resultCount;
    return result;
}
