int maximumCandies(int* candies, int candiesSize, long long k) {
    long long sum = 0;
    int maxVal = 0;
    for (int i = 0; i < candiesSize; i++) {
        sum += candies[i];
        if (candies[i] > maxVal) maxVal = candies[i];
    }
    
    if (sum < k) return 0;
    
    long long lo = 1, hi = maxVal;
    long long ans = 0;
    
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long total = 0;
        int feasible = 0;
        
        for (int i = 0; i < candiesSize; i++) {
            total += candies[i] / mid;
            if (total >= k) {
                feasible = 1;
                break;  
            }
        }
        
        if (feasible) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    return (int)ans;
}
