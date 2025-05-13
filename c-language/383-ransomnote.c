/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Runtime: 4ms
Memory: 6.3MB
Top 91.46% of C submissions
*/

bool canConstruct(char * ransomNote, char * magazine){
    short ransomCharacters[26] ={0}, magazineCharacters[26] = {0};
    short letters = 0, matches = 0;
    for (char c = *ransomNote; *ransomNote != '\0'; ransomNote++)
    {
        c = *ransomNote;
        ransomCharacters[c - 97]++;
        if (ransomCharacters[c - 97] == 1) letters++;
    }
    for (char c = *magazine; *magazine != '\0'; magazine++)
    {
        c = *magazine;
        magazineCharacters[c - 97]++;
        if (magazineCharacters[c - 97] == ransomCharacters[c - 97])
        {
            matches++;
        }
    }
    if (letters == matches) return true;
    else return false;
}
