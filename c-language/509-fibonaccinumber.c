/*
 The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.

Given N, calculate F(N).

Runtime: 4 ms
Memory: 5 MB
Top 45.7% of all C solutions

Note: Solution was implemented with memoization.
*/

#define n 30
int cache[n + 1] = {[0 ... n] = -1};

int fib(int N){
    cache[0] = 0; cache[1] = 1;
    if (cache[N] != -1) return cache[N];
    else
    {
        cache[N] = fib(N - 1) + fib(N - 2);
        return cache[N];
    }
}
