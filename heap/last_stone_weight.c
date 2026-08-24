int lastStoneWeight(int* stones, int stonesSize) {
    while (stonesSize > 1) {
        int max1 = 0, max2 = 0;
        int idx1 = 0, idx2 = 0;

        for (int i = 0; i < stonesSize; i++) {
            if (stones[i] > max1) {
                max1 = stones[i];
                idx1 = i;
            }
        }

        stones[idx1] = stones[stonesSize - 1];
        stonesSize--;

        for (int i = 0; i < stonesSize; i++) {
            if (stones[i] > max2) {
                max2 = stones[i];
                idx2 = i;
            }
        }

        stones[idx2] = stones[stonesSize - 1];
        stonesSize--;

        if (max1 != max2) {
            stones[stonesSize] = max1 - max2;
            stonesSize++;
        }
    }

    return stonesSize == 1 ? stones[0] : 0;
}
