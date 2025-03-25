// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。


// lowerBound 返回最小的满足 nums[i] >= target 的下标 i
// 如果数组为空，或者所有数都 < target，则返回 numsSize
// 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]
int lowerBound(int* nums, int numsSize, int target) {
    int left = -1, right = numsSize; // 开区间 (left, right)
    while (left + 1 < right) { // 区间不为空
        // 循环不变量：
        // nums[left] < target
        // nums[right] >= target
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid; // 范围缩小到 (left, mid)
        } else {
            left = mid; // 范围缩小到 (mid, right)
        }
    }
    // 循环结束后 left+1 = right
    // 此时 nums[left] < target 而 nums[right] >= target
    // 所以 right 就是第一个 >= target 的元素下标
    return right;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = malloc(2 * sizeof(int));
    *returnSize = 2;

    int start = lowerBound(nums, numsSize, target);
    if (start == numsSize || nums[start] != target) {
        ans[0] = -1; // nums 中没有 target
        ans[1] = -1;
        return ans;
    }

    // 如果 start 存在，那么 end 必定存在
    int end = lowerBound(nums, numsSize, target + 1) - 1;
    ans[0] = start;
    ans[1] = end;
    return ans;
}
