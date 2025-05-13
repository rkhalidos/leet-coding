/*
  There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

  Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
  
  Runtime: 0 ms
  Memory: 5.9MB
  Top 100% of all C submissions
*/

#include <stdlib.h>

struct person
{
    int index;
    int difference;
};

int compare (const void * a, const void * b)
{
  struct person *person1 = (struct person *)a;
  struct person *person2 = (struct person *)b;
  return (person2->difference - person1->difference);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    struct person *interviewees = malloc(costsSize * sizeof(struct person));
    for (int i = 0; i < costsSize; i++)
    {
        interviewees[i].index = i;
        interviewees[i].difference = abs(costs[i][0] - costs[i][1]);
    }
    qsort(interviewees, costsSize, sizeof(struct person), compare);
    
    int minCost = 0, cityA = 0, cityB = 0, N = costsSize/2;
    for (int i = 0; i < costsSize; i++)
    {
        int index = interviewees[i].index;
        if (cityA == N || (costs[index][1] <= costs[index][0] && cityB < N))
        {
            cityB++;
            minCost += costs[index][1];
        }
        else
        {
            cityA++;
            minCost += costs[index][0];
        }
    }
    free(interviewees);
    return minCost;
}
