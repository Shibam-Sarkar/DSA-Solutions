int findMaxLength(int* nums, int numsSize) {
    int size = 2 * numsSize + 1;
    int* firstIndex = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        firstIndex[i] = -2; 
    }

    int sum = 0;
    int maxLen = 0;
    firstIndex[numsSize] = -1; 

    for (int i = 0; i < numsSize; i++) {
        sum += (nums[i] == 0) ? -1 : 1;
        int idx = sum + numsSize; 

        if (firstIndex[idx] == -2) {
            firstIndex[idx] = i; 
        } else {
            int len = i - firstIndex[idx];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    free(firstIndex);
    return maxLen;
}
