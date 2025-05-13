/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Runtime: 16ms
Memory: 7.5MB
Top 94.74% of C submissions
*/


int majorityElement(int* nums, int numsSize){
    int distinct[] = { [0 ... 100] = 0 }; 
    int count[] = { [0 ... 100] = 0 };
    int elements = 0;
    
    if (numsSize == 1)
        return *nums;
    
    for(int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j <= elements; j++)
        {
            if (*nums == distinct[j])
            {
                count[j]++;
                if (count[j] > numsSize / 2)
                    return distinct[j];
                break;
            }
            else if (j == elements)
            {
                distinct[j] = *nums;
                count[j]++;
                elements++;
                break;
            }
        }
        nums++;
    }
    return -1;
}
