/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

Runtime: 0ms
Memory: 5.5MB
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int getNumber(int row, int column);
 
__int128 factorial(int n){
    if (n == 0) return 1;
    return n * factorial (n-1);
}

int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int *returnArray = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i <= (rowIndex + 1) / 2; i++)
    {
        returnArray[i] = factorial(rowIndex) / (factorial(i) * factorial(rowIndex-i));
        returnArray[rowIndex - i] = returnArray[i];
    }
    return returnArray;
}
