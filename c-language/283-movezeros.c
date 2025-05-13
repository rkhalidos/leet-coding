/*
  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
  
  Runtime: 12ms
  Memory: 7.2MB
  Top 85.65% of C submissions
*/

void moveZeroes(int* nums, int numsSize){
    int lastZero = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[lastZero++] = nums[i];
        }
    }
    for (int i = lastZero; i < numsSize; i++)
    {
        nums[i] = 0;
    }
}
