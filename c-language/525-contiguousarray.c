/*
  Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
  
  Runtime: 80ms
  Memory: 16.1MB
  Top 99.44% of all C submissions.
*/


struct runningSum
{
    int firstIndex;
};

int findMaxLength(int* nums, int numsSize){
    int countSize = numsSize + 1;
    struct runningSum* count = malloc((countSize) * sizeof(struct runningSum));
    memset(count, -1, countSize * sizeof(struct runningSum));
    count[0].firstIndex = 0;
    
    int length = 0, running_sum = 0, maxLength = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0) running_sum--;
        else running_sum++;
        
        int index = (running_sum >= 0)? running_sum % countSize : (countSize + running_sum) % countSize;
        if (count[index].firstIndex == -1) count[index].firstIndex = i + 1;
        else
        {
            length = i - count[index].firstIndex + 1;
            if (length > maxLength) maxLength = length;
        }
    }
    free(count);
    return maxLength;
}
