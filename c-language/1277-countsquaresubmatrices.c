/*
  Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
  
  Runtime: 76ms
  Memory: 10.4MB
  Top 95.59% of all C submissions
*/

int min(int a, int b, int c);

int countSquares(int** matrix, int matrixSize, int* matrixColSize){
    int count[matrixSize][*matrixColSize], totalPerm = 0;
    
    for (int i = 0; i < matrixSize; i++) {count[i][0] = matrix[i][0];}
    for (int i = 0; i < *matrixColSize; i++) {count[0][i] = matrix[0][i];}
    for(int i = 1; i < matrixSize; i++)
    {
        for(int j = 1; j < *matrixColSize; j++)
        {
            if (matrix[i][j] == 1)
            {
                count[i][j] = min(count[i][j-1], count[i-1][j-1], count[i-1][j]) + 1;
            }
            else
            {
                count[i][j] = 0;
                continue;
            }
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            totalPerm+=count[i][j];
        }
    }
    return totalPerm;
}

int min(int a, int b, int c) 
{ 
  int m = a; 
  if (m > b)  
      m = b; 
  if (m > c)  
      m = c; 
  return m; 
} 
