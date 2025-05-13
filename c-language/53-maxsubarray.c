/*
  Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
  
  Runtime: 4ms
  Memory: 6MB
  Top 96.64% of C submissions
*/
int max(int num1, int num2);

int maxSubArray(int* nums, int numsSize){
    int running_sum = nums[0], max_sum = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        running_sum = max(running_sum + nums[i], nums[i]);
        max_sum = max(max_sum, running_sum);
    }
    return max_sum;
}

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
