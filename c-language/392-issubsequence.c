/*
Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Runtime: 0 ms
Memory: 5.3 MB
Top 100% of all C submissions
*/

#include <string.h>

bool isSubsequence(char * s, char * t){
    int sLength = strlen(s), tlength = strlen(t), count = 0;
    for (int i = 0; i < tlength; i++)
    {
        if (s[count] == t[i]) count++;
    }
    if (count == sLength) return true;
    else return false;
}
