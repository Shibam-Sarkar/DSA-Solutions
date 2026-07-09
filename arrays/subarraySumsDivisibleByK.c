int subarraysDivByK(int* nums, int numsSize, int k) {
    int* count = (int*)calloc(k, sizeof(int));
    count[0] = 1; 

    int sum = 0;
    long long result = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int rem = ((sum % k) + k) % k;
        result += count[rem];
        count[rem]++;
    }

    free(count);
    return (int)result;
}
