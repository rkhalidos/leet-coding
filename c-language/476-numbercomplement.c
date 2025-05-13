/*
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

Runtime: 0ms
Memory: 5.1MB
Top 100% of C submissions
*/

int findComplement(int num){
    int binaryDigit = 1, complement = 0;
    while (num / 2 != 0)
    {
        if (!(num % 2))
        {
            complement += binaryDigit * 1;
        }
        binaryDigit *= 2;
        num = num / 2;
    }
    return complement;
}
