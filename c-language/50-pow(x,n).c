/*
Implement pow(x, n), which calculates x raised to the power n (x^n).
Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
    
Runtime: 0 ms
Memory: 5.2 MB
Top 100% of all C submissions
*/

double myPow(double x, int n){
    if (n == 0) return 1;
    double temp = myPow(x, n/2);
    if (n % 2 == 0) return temp * temp;
    else
    {
        if (n > 0) return x * temp * temp;
        else return (temp * temp) / x;
    }
}
