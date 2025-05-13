/*
  Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

  Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

  The order of output does not matter.
  
  Runtime: 16ms
  Memory: 9.1MB
  Top 100% of C submissions
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#include <string.h>
int primes[26] = {2, 5, 11, 17, 23, 31, 41, 47, 59, 71, 79, 89, 101, 107, 113, 131, 139, 151, 163, 173, 181, 191, 197, 211, 227, 233};

int findSum(char *string, int substringLength);

int* findAnagrams(char * s, char * p, int* returnSize){
    // error condition
    if (strlen(s) < strlen(p)) {*returnSize = 0; return NULL;}
    
    int substringLength = strlen(p), index = 0, substringSum = findSum(p, substringLength), stringLength = strlen(s);
    char *startPointer = s, *endPointer = (s + substringLength);
    int* returnArray = (int *)malloc(stringLength * sizeof(int));
    
    int currentSum = findSum(s, substringLength);
    for (int i = 0; i < stringLength - substringLength + 1; i++, startPointer++, endPointer++)
    {
        if (currentSum == substringSum)
        {
            returnArray[index] = i;
            index++;
        }
        currentSum -= primes[*startPointer - 'a'];
        if (*endPointer != '\0') currentSum += primes[*endPointer - 'a'];
        else break;
    }
    *returnSize = index;
    return returnArray;
}

int findSum(char *string, int substringLength)
{
    int sum = 0;
    for (int i = 0; i < substringLength; i++)
    {
        sum += primes[*(string + i) - 'a'];
    }
    return sum;
}
