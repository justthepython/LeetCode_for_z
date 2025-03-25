// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 请必须使用时间复杂度为 O(log n) 的算法。

int searchInsert(int* nums, int numsSize, int target) {
    int left = -1;
    int right = numsSize;

    while (left + 1 < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return right;
}