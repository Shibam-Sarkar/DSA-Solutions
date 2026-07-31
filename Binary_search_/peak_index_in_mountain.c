int peakIndexInMountainArray(int* arr, int arrSize) {
    int lo = 0, hi = arrSize - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;  // avoids overflow
        if (arr[mid] < arr[mid + 1]) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
