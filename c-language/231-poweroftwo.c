/*
Given an integer, write a function to determine if it is a power of two.

Runtime: 0 ms
Memory: 5 MB
Top 100% of all C submissions
*/

bool isPowerOfTwo(int n){
    if (n == 0) return false;
    while (n % 2 == 0)
    {
        n /= 2;
    }
    if (n == 1) return true;
    return false;
}
