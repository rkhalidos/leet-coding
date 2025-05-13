/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Runtime: 4 ms
Memory: 5.6 MB
Top 96% of all C submissions
*/

int change(int amount, int* coins, int coinsSize){
    int* possibilities = calloc(amount + 1, sizeof(int));
    possibilities[0] = 1;
    for (int i = 0; i < coinsSize; i++)
    {
        for (int j = coins[i]; j <= amount; j++)
            possibilities[j] += possibilities[j - coins[i]];
    }
    int result = possibilities[amount];
    free(possibilities);
    return result;
}
