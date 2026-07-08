nt maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    int curMax = 0, maxSum = INT_MIN;
    int curMin = 0, minSum = INT_MAX;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        
        curMax = (curMax + num > num) ? curMax + num : num;
        maxSum = (maxSum > curMax) ? maxSum : curMax;
        
        curMin = (curMin + num < num) ? curMin + num : num;
        minSum = (minSum < curMin) ? minSum : curMin;
        
        total += num;
    }
    
    if (maxSum < 0) {
        return maxSum;
    }

    int wrapSum = total - minSum;
    return (maxSum > wrapSum) ? maxSum : wrapSum;
}
