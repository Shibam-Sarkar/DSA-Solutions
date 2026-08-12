int findKthNumber(int m, int n, int k) {
    long long lo = 1, hi = (long long)m * n;

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        long long count = 0;

        for (int i = 1; i <= m; i++) {
            long long rowCount = mid / i;
            if (rowCount > n) rowCount = n;
            count += rowCount;
            if (count >= k) {
            
            }
        }

        if (count < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return (int)lo;
}
