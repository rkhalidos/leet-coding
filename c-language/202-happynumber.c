/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Runtime: 0ms
Memory: 5MB
Top 100% of C submissions
*/

bool isHappy(int n){
    int sum = n, loops = 0, result = 0;
    int MAX_LOOPS = 20;
    
    while (sum != 1)
    {
        while (sum != 0)
        {
            result += pow(sum % 10, 2);
            sum /= 10;
        }
        
        if (result == 1) return true;
        sum = result;
        result = 0;
        loops++;
        if (loops == MAX_LOOPS) return false;
    }
    return true;
}
