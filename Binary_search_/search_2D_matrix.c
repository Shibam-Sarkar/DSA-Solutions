bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = matrixColSize[0];
    
    int lo = 0, hi = m * n - 1;
    
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int row = mid / n;
        int col = mid % n;
        int val = matrix[row][col];
        
        if (val == target) {
            return true;
        } else if (val < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    return false;
}
