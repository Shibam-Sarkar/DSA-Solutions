int hIndex(int* citations, int citationsSize) {
    int n = citationsSize;
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int papersAtLeast = n - mid;

        if (citations[mid] >= papersAtLeast) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return n - lo;
}
