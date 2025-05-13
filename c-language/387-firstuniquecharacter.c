/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Runtime: 8ms
Memory: 6.6MB
Top 88.63% of C submissions
*/

int firstUniqChar(char * s){
    int index[] = { [0 ... 25] = -1 };
    int unique = INT_MAX;
    char *firstLetter = s;
    while(*s != '\0')
    {   
        if (index[*s - 97] == -1) index[*s - 97] = (s - firstLetter);
        else index[*s - 97] = -2;
        s++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (index[i] != -1 && index[i] != -2)
        {
            if (unique > index[i]) unique = index[i];
        }
    }
    if (unique != INT_MAX)
        return unique;
    else 
        return -1;
}
