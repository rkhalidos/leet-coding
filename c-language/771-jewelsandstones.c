/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Runtime: 0ms
Memory: 5.1MB
Top 100% of C submissions
*/

int numJewelsInStones(char * J, char * S){
    short JCharacters[52] ={0};
    short count = 0;
    for (char c = *J; *J != '\0'; J++)
    {
        c = *J;
        if (c >= 97 && c <= 122) JCharacters[26 + c - 97]++;
        else JCharacters[c - 65]++;
    }
    for (char c = *S; *S != '\0'; S++)
    {
        c = *S;
        short index;
        if (c >= 97 && c <= 122) index = 26 + c - 97;
        else index = c - 65;
        if (JCharacters[index] > 0)
        {
            count++;
        }
    }
    return count;
}
