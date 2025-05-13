/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Runtime: 4 ms
Memory: 5.8 MB
Top 89.56% of all C submissions
*/

int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) right = mid - 1;
        else if (nums[mid] < target) left = mid + 1;
    }
    return left;
}
