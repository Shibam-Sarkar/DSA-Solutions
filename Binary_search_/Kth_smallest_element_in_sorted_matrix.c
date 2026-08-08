int countLessEqual(int** matrix, int n, int x) {
    int count = 0;
    int row = n - 1, col = 0;
    while (row >= 0 && col < n) {
        if (matrix[row][col] <= x) {
            count += row + 1;
            col++;
        } else {
            row--;
        }
    }
    return count;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int n = matrixSize;
    int lo = matrix[0][0];
    int hi = matrix[n - 1][n - 1];

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (countLessEqual(matrix, n, mid) < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return lo;
}
