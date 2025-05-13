/*
   Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

  The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

  For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
  
  Runtime: 288ms
  Memory: 57.5MB
*/


typedef struct stockSpanner_{
    int prices[10000];
    int stack[10000];
    int index;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner * base = (StockSpanner *)malloc(sizeof(StockSpanner));
    if (base != NULL) base->index = -1;
    return base;
}

int stockSpannerNext(StockSpanner* obj, int price) { 
    obj->index += 1;
    int index = obj->index;
    obj->prices[index] = price;
    if (index == 0) {obj->stack[index] = 1; return 1;}
    
    int counter = 1, i = index - 1;
    while (i >= 0 && price >= obj->prices[i]) 
    {
        int diff = obj->stack[i]; 
        counter+=diff; 
        i-= diff;
    }
    obj->stack[index] = counter;
    return counter;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/
