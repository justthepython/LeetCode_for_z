// 整数数组 nums 按升序排列，数组中的值 互不相同 。
// 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
//使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
//例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
// 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
// 你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

//1、两次二分法

// 153. 寻找旋转排序数组中的最小值（返回的是下标）
int findMin(int* nums, int numsSize) {
    int left = -1, right = numsSize - 1; // 开区间 (-1, n-1)
    while (left + 1 < right) { // 开区间不为空
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[numsSize - 1]) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

// 有序数组中找 target 的下标
int lowerBound(int* nums, int left, int right, int target) {
    while (left + 1 < right) { // 开区间不为空
        // 循环不变量：
        // nums[right] >= target
        // nums[left] < target
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid; // 范围缩小到 (left, mid)
        } else {
            left = mid; // 范围缩小到 (mid, right)
        }
    }
    return nums[right] == target ? right : -1;
}

int search(int* nums, int numsSize, int target) {
    int i = findMin(nums, numsSize);
    if (target > nums[numsSize - 1]) { // target 在第一段
        return lowerBound(nums, -1, i, target); // 开区间 (-1, i)
    }
    // target 在第二段
    return lowerBound(nums, i - 1, numsSize, target); // 开区间 (i-1, n)
}

//两次二分法

int search(int* nums, int numsSize, int target) {
    int min = 0, n = numsSize;
        for (int l = 1, r = n - 1; l <= r;) {
            int m = (l + r) / 2;
            if (nums[0] < nums[m]) l = m + 1;
            else { r = m - 1; min = m; }
        }
        for (int l = min, r = l + n - 1; l <= r;) {
            int m = (l + r) / 2, i = m % n;
            if (target < nums[i]) r = m - 1;
            else if (target > nums[i]) l = m + 1;
            else return i;
        }
        return -1;
}

//2、