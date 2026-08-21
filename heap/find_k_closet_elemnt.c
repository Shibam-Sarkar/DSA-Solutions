int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int lo = 0, hi = arrSize - k;
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        // Compare distance of arr[mid] vs arr[mid + k] from x
        if (x - arr[mid] > arr[mid + k] - x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = arr[lo + i];
    }
    
    *returnSize = k;
    return result;
}
