/*
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Runtime: 96 ms
Memory: 28.4 MB
Top 100% of all C submissions
*/

#include <stdlib.h>

typedef struct Solution{
    int sum;
    int wSize;
}Solution;


Solution* solutionCreate(int* w, int wSize) {
    struct Solution *cummulativeSum = (struct Solution *)malloc(wSize * sizeof(struct Solution));
    for (int i = 0; i < wSize; i++)
    {
        if (i == 0)
        {
            cummulativeSum[i].wSize = wSize;
            cummulativeSum[i].sum = w[i];
            continue;
        }
        cummulativeSum[i].sum = w[i] + cummulativeSum[i-1].sum;
    }
    return cummulativeSum;
}

int solutionPickIndex(Solution* obj) {
    int wSize = obj[0].wSize, maxNumber = obj[wSize - 1].sum, randomIndex = (rand() % (maxNumber)) + 1;
    
    int left = 0, right = wSize - 1, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (obj[mid].sum < randomIndex) left = mid + 1;
        else right = mid;
    }
    return right;
}


void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/
