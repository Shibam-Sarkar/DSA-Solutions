int shipWithinDays(int* weights, int weightsSize, int days) {
    int lo = 0, hi = 0;
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > lo) lo = weights[i];
        hi += weights[i];
    }
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        int totalDays = 1;
        int currentLoad = 0;
        for (int i = 0; i < weightsSize; i++) {
            if (currentLoad + weights[i] > mid) {
                totalDays++;
                currentLoad = 0;
            }
            currentLoad += weights[i];
        }
        
        if (totalDays <= days) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    return lo;
}
