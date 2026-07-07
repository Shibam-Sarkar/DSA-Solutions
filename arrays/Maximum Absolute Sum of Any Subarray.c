int maxAbsoluteSum(int* nums, int numsSize) {
    int curMax = 0, curMin = 0;
    int maxSum = 0, minSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        
        curMax = (curMax > 0 ? curMax : 0) + n;
        curMin = (curMin < 0 ? curMin : 0) + n;
        
        if (curMax > maxSum) maxSum = curMax;
        if (curMin < minSum) minSum = curMin;
    }
    
    int negMinSum = -minSum;
    return maxSum > negMinSum ? maxSum : negMinSum;
}
