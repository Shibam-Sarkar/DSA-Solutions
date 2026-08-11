
int smallestDivisor(int* nums, int numsSize, int threshold) {
    int low = 1;
    int high = nums[0];

    // Find maximum element
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > high) {
            high = nums[i];
        }
    }

    // Binary search
    while (low < high) {
        int mid = low + (high - low) / 2;
        int sum = 0;

        for (int i = 0; i < numsSize; i++) {
            sum += (nums[i] + mid - 1) / mid;

            if (sum > threshold) {
                break;
            }
        }

        if (sum <= threshold) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
