#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;
    int threshold = numsSize / 3;

    int i = 0;
    while (i < numsSize) {
        int j = i;
        while (j < numsSize && nums[j] == nums[i])
            j++;

        if (j - i > threshold)
            result[(*returnSize)++] = nums[i];

        i = j; 
    }

    return result;
}
