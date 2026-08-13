typedef struct {
    int* prices;
    int* spans;
    int top;
    int capacity;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->capacity = 10000;
    obj->prices = (int*)malloc(sizeof(int) * obj->capacity);
    obj->spans = (int*)malloc(sizeof(int) * obj->capacity);
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while (obj->top >= 0 && obj->prices[obj->top] <= price) {
        span += obj->spans[obj->top];
        obj->top--;
    }
    obj->top++;
    obj->prices[obj->top] = price;
    obj->spans[obj->top] = span;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->prices);
    free(obj->spans);
    free(obj);
}
