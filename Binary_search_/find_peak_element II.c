
int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize) {
    int m = matSize;
    int n = matColSize[0];
    
    int left = 0, right = n - 1;
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        
        int bestRow = 0;
        for (int r = 1; r < m; r++) {
            if (mat[r][mid] > mat[bestRow][mid]) {
                bestRow = r;
            }
        }
        
        int cur = mat[bestRow][mid];
        int leftVal = (mid - 1 >= 0) ? mat[bestRow][mid - 1] : -1;
        int rightVal = (mid + 1 < n) ? mat[bestRow][mid + 1] : -1;
        
        if (cur > leftVal && cur > rightVal) {
            result[0] = bestRow;
            result[1] = mid;
            return result;
        } else if (leftVal > cur) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    result[0] = 0;
    result[1] = 0;
    return result;
}
