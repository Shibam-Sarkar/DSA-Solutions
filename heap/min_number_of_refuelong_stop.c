int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize) {
    long long fuel = startFuel;
    int stops = 0;
    int prev = 0;

    // Max heap
    int *heap = (int*)malloc(sizeof(int) * (stationsSize + 1));
    int heapSize = 0;

    for (int i = 0; i <= stationsSize; i++) {
        int pos, stationFuel = 0;

        if (i == stationsSize) {
            pos = target;
        } else {
            pos = stations[i][0];
            stationFuel = stations[i][1];
        }

        // Travel to current position
        fuel -= (long long)(pos - prev);

        // If fuel is insufficient, use largest previous fuel
        while (fuel < 0 && heapSize > 0) {
            fuel += heap[0];
            stops++;

            // Remove max from heap
            heap[0] = heap[--heapSize];

            // Heapify down
            int j = 0;
            while (1) {
                int left = 2 * j + 1;
                int right = 2 * j + 2;
                int largest = j;

                if (left < heapSize && heap[left] > heap[largest])
                    largest = left;

                if (right < heapSize && heap[right] > heap[largest])
                    largest = right;

                if (largest == j)
                    break;

                int temp = heap[j];
                heap[j] = heap[largest];
                heap[largest] = temp;

                j = largest;
            }
        }

        // Still cannot reach this position
        if (fuel < 0) {
            free(heap);
            return -1;
        }

        // Add current station's fuel to max heap
        if (i < stationsSize) {
            int j = heapSize++;
            heap[j] = stationFuel;

            // Heapify up
            while (j > 0) {
                int parent = (j - 1) / 2;

                if (heap[parent] >= heap[j])
                    break;

                int temp = heap[parent];
                heap[parent] = heap[j];
                heap[j] = temp;

                j = parent;
            }
        }

        prev = pos;
    }

    free(heap);
    return stops;
}
