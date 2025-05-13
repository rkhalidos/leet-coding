/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Runtime: 0 ms
Memory: 5.3 MB
*/

int climbStairs(int n){
    int *possibilities = calloc(n + 1, sizeof(int)); 
    possibilities[0] = 1; 
    if (n >= 1) possibilities[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        possibilities[i] = possibilities[i - 1] + possibilities[i - 2];
    }
    int result = possibilities[n];
    free(possibilities);
    return result;
}
