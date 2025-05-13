/*
  Given a string, sort it in decreasing order based on the frequency of characters.
  
  Runtime: 4ms
  Memory: 6.1MB
  Top 85% of all C submissions
*/

#include <string.h>
#define MAX_ASCII 128

int findNextMax(int frequencyCount[MAX_ASCII], int *character);

char * frequencySort(char * s){
    int frequencyCount[MAX_ASCII] = {[0 ... MAX_ASCII-1] = 0};
    int length = strlen(s) + 1;
    while (*s != '\0')
    {
        frequencyCount[*s]++;
        s++;
    }
    
    static char result[200000];
    //char *result = (char *)malloc(length*sizeof(char));
    int character = 0, count = findNextMax(frequencyCount, &character), index = 0;
    while (count != -1)
    {
        while (count > 0)
        {
            result[index++] = (char)character;
            count--;
        }
        count = findNextMax(frequencyCount, &character);
    }
    result[index] = '\0';
    return result;
}

int findNextMax(int frequencyCount[MAX_ASCII], int *character)
{
    int max = -1, index;
    for (int i = 0; i < MAX_ASCII; i++)
    {
        if (frequencyCount[i] != 0)
        {
            if (max < frequencyCount[i]) 
            {
                max = frequencyCount[i];
                *character = i;
            }
        }
    }
    if (max != -1) frequencyCount[*character] = 0;
    return max;
}
