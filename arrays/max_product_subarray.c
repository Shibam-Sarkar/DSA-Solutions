int maxProduct(int* nums, int numsSize) {
    int max_prod = nums[0];
    int min_prod = nums[0];
    int result   = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];

        if (num < 0) 
            int tmp  = max_prod;
            max_prod = min_prod;
            min_prod = tmp;
        }

        max_prod = fmax(num, max_prod * num);
        min_prod = fmin(num, min_prod * num);

        if (max_prod > result)
            result = max_prod;
    }

    return result;
}
