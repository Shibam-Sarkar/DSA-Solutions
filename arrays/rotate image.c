void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            int tmp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = tmp;
            left++;
            right--;
        }
    }
}
