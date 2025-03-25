// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
//写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

int search(int* nums, int numsSize, int target) {
    int left = -1;
    int right = numsSize;
    int mid = 0;

    while(left + 1 < right)
    {
        mid = left + (right - left) / 2;

        if (nums[mid] < target)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    if((right < numsSize)&&(nums[right] == target))
    {
        return right;
    }
    else
    {
        return -1;
    }
}
