
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。

//第一种，
int searchInsert(int* nums, int numsSize, int target) {
    int left_index = 0;
    int right_index = numsSize - 1;

    while(1)
    {
        if (target <= nums[left_index])
        {
            return left_index;
        }

        if (target > nums[right_index])
        {
            return right_index+1;
        }

        if (target < nums[(left_index+right_index)/2])
        {
            right_index = (left_index+right_index)/2;
        }
        else if (target > nums[(left_index+right_index)/2])
        {
            left_index = (left_index+right_index)/2;
        }
        else
        {
            return (left_index+right_index)/2;
        }

        if (right_index - 1 == left_index)
        {
            return left_index+1;
        }
    }
}

//第二种，二分法
int searchInsert(int* nums, int numsSize, int target) {
    int left_index = 0;
    int right_index = numsSize - 1;
    int mid = 0;

    while(left_index <= right_index)
    {
        mid = (left_index+right_index)/2;

        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            left_index = mid+1;
        }
        else
        {
            right_index = mid-1;
        }
    }
    return left_index;
}

