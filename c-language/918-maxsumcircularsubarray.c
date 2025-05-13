/*
  Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
  
  Runtime: 56ms
  Memory: 8.2MB
  Top 88.32% of C submissions
*/

int max (int a, int b);
int kadane(int* A, int ASize);

int maxSubarraySumCircular(int* A, int ASize){
    int sum1 = kadane(A, ASize);
    int arraySum = 0;
    for (int i = 0; i < ASize; i++)
    {
        arraySum += A[i];
        A[i] = -A[i];
    }
    int maxNegative = kadane(A, ASize);
    int sum2 = arraySum + maxNegative;
    if (sum2 == 0) sum2 = INT_MIN;
    return max(sum1, sum2);
}

int max (int a, int b)
{
    return (a > b)? a : b;
}

int kadane(int* A, int ASize)
{
    if (ASize == 1) return A[0];
    int running_sum = A[0], max_sum = INT_MIN;
    for (int j = 1; j < ASize; j++)
    {
        int prev_running_sum = running_sum;
        running_sum = max(running_sum + A[j], A[j]);
        max_sum = max(running_sum, max_sum);
    }
    return max_sum;
}
