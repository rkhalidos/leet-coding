/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Runtime: 44 ms
Memory: 10.2 MB
Top 85.71% of all C submissions
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b)
{
    int *peopleA = *(int **)a;
    int *peopleB = *(int **)b;
    return (peopleA[0] == peopleB[0] ? peopleA[1] - peopleB[1] : peopleB[0] - peopleA[0]);
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes)
{
    if (peopleSize == 0)
    {
        *returnSize = 0;
        return people;
    }
    
    qsort(people, peopleSize, sizeof(int *), compare);
    int **result = calloc(peopleSize, sizeof(int *));

    for (int i = 0; i < peopleSize; i++)
    {     
        int *replace = people[i];
        int index = people[i][1];
        while (result[index] != NULL)
        {
            int *temp = result[index];    
            result[index] = replace;
            replace = temp;
            index++;
        }
        result[index] = replace;
    }
    
    *returnColumnSizes = malloc(sizeof(int)*peopleSize);        
    for (int i = 0; i < peopleSize; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = peopleSize;
    return result;
}

