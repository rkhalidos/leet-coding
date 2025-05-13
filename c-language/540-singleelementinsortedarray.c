/*
  You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears    exactly once. Find this single element that appears only once.
  
  Runtime: 8ms
  Memory: 6.3MB
  Top 75.66% of C submissions
*/

int singleNonDuplicate(int* nums, int numsSize){  
    for (int i = 0; i < numsSize - 1; i+=2)
    {
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}
