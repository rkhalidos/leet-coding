/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Runtime: 48ms
Memory: 11.9 MB
Top 66.09% of all C submissions
*/

void reverseString(char* s, int sSize){
    int loop = sSize/2;
    for (int i = 0; i < loop; i++)
    {
        char temp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = temp;
    }
}
