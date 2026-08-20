#include <stdlib.h>

int** kClosest(int** points, int pointsSize, int* pointsColSize,
               int k, int* returnSize, int** returnColumnSizes) {

    int **result = malloc(k * sizeof(int*));
    *returnColumnSizes = malloc(k * sizeof(int));
    *returnSize = k;

    int *dist = malloc(pointsSize * sizeof(int));
    int *idx = malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0];
        int y = points[i][1];

        dist[i] = x * x + y * y;
        idx[i] = i;
    }

    // Sort points by distance
    for (int i = 0; i < pointsSize - 1; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            if (dist[i] > dist[j]) {
                int temp = dist[i];
                dist[i] = dist[j];
                dist[j] = temp;

                temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        result[i] = malloc(2 * sizeof(int));

        result[i][0] = points[idx[i]][0];
        result[i][1] = points[idx[i]][1];

        (*returnColumnSizes)[i] = 2;
    }

    free(dist);
    free(idx);

    return result;
}
