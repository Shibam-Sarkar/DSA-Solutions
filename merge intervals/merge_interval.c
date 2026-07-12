int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    int count = 0;
    int currentStart = intervals[0][0];
    int currentEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (start <= currentEnd) {
            if (end > currentEnd) {
                currentEnd = end;
            }
        } else {
            result[count] = (int*)malloc(sizeof(int) * 2);
            result[count][0] = currentStart;
            result[count][1] = currentEnd;
            (*returnColumnSizes)[count] = 2;
            count++;

            currentStart = start;
            currentEnd = end;
        }
    }

    result[count] = (int*)malloc(sizeof(int) * 2);
    result[count][0] = currentStart;
    result[count][1] = currentEnd;
    (*returnColumnSizes)[count] = 2;
    count++;

    *returnSize = count;
    return result;
}

}
