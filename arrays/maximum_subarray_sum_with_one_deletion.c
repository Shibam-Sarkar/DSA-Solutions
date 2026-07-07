int maximumSum(int* arr, int arrSize) {
    int noDel = arr[0];
    int oneDel = arr[0];
    int ans = arr[0];
    
    for (int i = 1; i < arrSize; i++) {
        int n = arr[i];
        
        int newOneDel = (noDel > oneDel + n) ? noDel : (oneDel + n);
        
        int newNoDel = (n > noDel + n) ? n : (noDel + n);
        
        noDel = newNoDel;
        oneDel = newOneDel;
        
        if (noDel > ans) ans = noDel;
        if (oneDel > ans) ans = oneDel;
    }
    
    return ans;
}
