/*
 Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest  possible.

  Note:
  The length of num is less than 10002 and will be ≥ k.
  The given num does not contain any leading zero.
  
 Runtime: 0ms
 Memory: 5.8MB
 Top 100% of C submissions
*/

#include <string.h>

char * removeKdigits(char * num, int k){
    int length = strlen(num);
    if (length == k) return "0\0";
    if (k == 0) return num;
    
    int newLength = length - k + 1;
    char *result = (char *)malloc(sizeof(char) * length);

    int eliminated = 0, i, index = 0; result[index] = num[0];
    for (i = 1, index = 0; i < length && eliminated != k; i++)
    {
        if (num[i] >= num[i - 1])
        {
            result[index] = num[i - 1];
            index++;
            result[index] = num[i];
        }
        else
        {
            while (index >= 0 && result[index] > num[i] && eliminated != k)
            {
                result[index] = num[i];
                index--;
                eliminated++;
            }
            index++;
        }
    }
    for (i; i < length; i++)
    {
        index++;
        result[index] = num[i];
    }
    result[newLength - 1] = '\0';

    int leadingZeros = 0;
    for(int i = 0; result[i] == '0'; i++)
    {
        leadingZeros++;
    }
    
    char *final = (char *)malloc(sizeof(char)* (strlen(result) - leadingZeros + 1));
    strcpy(final, result + leadingZeros);
    if (strcmp(final, "") == 0) final = "0\0";
    return final;
}
