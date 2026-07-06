int smallestSubarraySum(int arr[], int n) {
    int minEndingHere = arr[0];
    int minSoFar = arr[0];
    
    for (int i = 1; i < n; i++) {
        minEndingHere = min(arr[i], minEndingHere + arr[i]);
        minSoFar = min(minSoFar, minEndingHere);
    }
    
    return minSoFar;
}
