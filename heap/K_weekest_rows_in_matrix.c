
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    
    int m = matSize;
    
    int count[100];
    
    // Count soldiers in each row
    for (int i = 0; i < m; i++) {
        count[i] = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1)
                count[i]++;
            else
                break;
        }
    }
    
    int* ans = (int*)malloc(k * sizeof(int));
    
    for (int x = 0; x < k; x++) {
        int weakest = -1;
        
        for (int i = 0; i < m; i++) {
            if (count[i] == -1)
                continue;
            
            if (weakest == -1 ||
                count[i] < count[weakest] ||
                (count[i] == count[weakest] && i < weakest)) {
                weakest = i;
            }
        }
        
        ans[x] = weakest;
        count[weakest] = -1;
    }
    
    *returnSize = k;
    return ans;
}
