int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    long long need = (long long)m * (long long)k;
    if (need > bloomDaySize) return -1;
    
    int lo = bloomDay[0], hi = bloomDay[0];
    for (int i = 1; i < bloomDaySize; i++) {
        if (bloomDay[i] < lo) lo = bloomDay[i];
        if (bloomDay[i] > hi) hi = bloomDay[i];
    }
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        int bouquets = 0, consecutive = 0;
        for (int i = 0; i < bloomDaySize; i++) {
            if (bloomDay[i] <= mid) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        
        if (bouquets >= m) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    return lo;
}
