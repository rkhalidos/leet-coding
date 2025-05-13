/*
  Given a positive integer num, write a function which returns True if num is a perfect square else False.

  Note: Do not use any built-in library function such as sqrt.
  
  Runtime: 0ms
  Memory: 5MB
  Top 100% of C submissions
*/

bool isPerfectSquare(int num){
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0 && num / i == i)
            return true;
        if (num / i < i)
            return false;
    }
    return false;
}
