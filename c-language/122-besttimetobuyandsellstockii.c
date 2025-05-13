/*
  Say you have an array prices for which the ith element is the price of a given stock on day i.

  Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

  Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
  
  Runtime: 4ms
  Memory: 6.5MB
  Top 88.07% of C submissions
*/

int maxProfit(int* prices, int pricesSize){
    int transactions[pricesSize];
    for (int i = 0; i < pricesSize; i++) transactions[i] = 0;
    
    transactions[0] = prices[0];
    int index = 0, buying = 1, selling = 0, number_of_transactions = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] <= transactions[index])
        {
            if (buying == 1 && selling == 0)
                transactions[index] = prices[i];
            if (buying == 0 && selling == 1)
            {
                index++;
                transactions[index] = prices[i];
                buying = 1; selling = 0;
                number_of_transactions++;
            }
        }
        else
        {
            if (buying == 1 && selling == 0)
            {
                selling = 1; buying = 0;
                transactions[index + 1] = prices[i];
                index++;
            }   
            if (buying == 0 && selling == 1)
                transactions[index] = prices[i];
        }
    }
    number_of_transactions++;
    
    int profit = 0;
    for (int i = 0, loop = 0; i < pricesSize - 1 && loop < number_of_transactions; i+=2, loop++)
    {
        if (transactions[i + 1] != 0)
            profit += -1 * transactions[i] + transactions[i + 1];
    }
    
    return profit;
}
