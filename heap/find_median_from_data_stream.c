typedef struct {
    int *small;   
    int *large;   // min-heap - upper half
    int smallSize;
    int largeSize;
    int smallCap;
    int largeCap;
} MedianFinder;

static void smallSwap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void smallPush(MedianFinder *obj, int val) {
    if (obj->smallSize == obj->smallCap) {
        obj->smallCap *= 2;
        obj->small = realloc(obj->small, obj->smallCap * sizeof(int));
    }
    int i = obj->smallSize++;
    obj->small[i] = val;
    // sift up (max-heap)
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (obj->small[parent] < obj->small[i]) {
            smallSwap(&obj->small[parent], &obj->small[i]);
            i = parent;
        } else break;
    }
}

static int smallPop(MedianFinder *obj) {
    int top = obj->small[0];
    obj->smallSize--;
    obj->small[0] = obj->small[obj->smallSize];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < obj->smallSize && obj->small[left] > obj->small[largest]) largest = left;
        if (right < obj->smallSize && obj->small[right] > obj->small[largest]) largest = right;
        if (largest == i) break;
        smallSwap(&obj->small[i], &obj->small[largest]);
        i = largest;
    }
    return top;
}

/* ---------- helpers for min-heap (large) ---------- */
static void largeSwap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void largePush(MedianFinder *obj, int val) {
    if (obj->largeSize == obj->largeCap) {
        obj->largeCap *= 2;
        obj->large = realloc(obj->large, obj->largeCap * sizeof(int));
    }
    int i = obj->largeSize++;
    obj->large[i] = val;
    // sift up (min-heap)
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (obj->large[parent] > obj->large[i]) {
            largeSwap(&obj->large[parent], &obj->large[i]);
            i = parent;
        } else break;
    }
}

static int largePop(MedianFinder *obj) {
    int top = obj->large[0];
    obj->largeSize--;
    obj->large[0] = obj->large[obj->largeSize];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < obj->largeSize && obj->large[left] < obj->large[smallest]) smallest = left;
        if (right < obj->largeSize && obj->large[right] < obj->large[smallest]) smallest = right;
        if (smallest == i) break;
        largeSwap(&obj->large[i], &obj->large[smallest]);
        i = smallest;
    }
    return top;
}

/* ---------- MedianFinder API ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder *obj = malloc(sizeof(MedianFinder));
    obj->smallCap = 1024;
    obj->largeCap = 1024;
    obj->small = malloc(obj->smallCap * sizeof(int));
    obj->large = malloc(obj->largeCap * sizeof(int));
    obj->smallSize = 0;
    obj->largeSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // push to max-heap (small), then move its top to large
    smallPush(obj, num);
    largePush(obj, smallPop(obj));

    if (obj->largeSize > obj->smallSize) {
        smallPush(obj, largePop(obj));
    }
}
double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->smallSize > obj->largeSize) {
        return (double)obj->small[0];
    }
    return (obj->small[0] + obj->large[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->small);
    free(obj->large);
    free(obj);
}
