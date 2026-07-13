int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    
    int count = 0;
    int i = 0;
    int start = newInterval[0];
    int end = newInterval[1];
    
    while (i < intervalsSize && intervals[i][1] < start) {
        result[count] = (int*)malloc(sizeof(int) * 2);
        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }
    
    while (i < intervalsSize && intervals[i][0] <= end) {
        if (intervals[i][0] < start) start = intervals[i][0];
        if (intervals[i][1] > end) end = intervals[i][1];
        i++;
    }
    result[count] = (int*)malloc(sizeof(int) * 2);
    result[count][0] = start;
    result[count][1] = end;
    (*returnColumnSizes)[count] = 2;
    count++;
    
    while (i < intervalsSize) {
        result[count] = (int*)malloc(sizeof(int) * 2);
        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }
    
    *returnSize = count;
    return result;
}
