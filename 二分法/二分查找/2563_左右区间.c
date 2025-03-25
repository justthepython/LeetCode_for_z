// 给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。

// 如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：

// 0 <= i < j < n，且
// lower <= nums[i] + nums[j] <= upper

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// 返回 nums 中的第一个大于 target 的元素下标
int upperBound(int* nums, int numsSize, int target) {
    int left = -1, right = numsSize; // 开区间 (left, right)
    while (left + 1 < right) { // 区间不为空
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid; // 二分范围缩小到 (left, mid)
        } else {
            left = mid; // 二分范围缩小到 (mid, right)
        }
    }
    return right;
}

// 返回 nums 中的第一个大于 target 的元素下标
int lowerBound(int* nums, int numsSize, int target) {
    int left = -1, right = numsSize; // 开区间 (left, right)
    while (left + 1 < right) { // 区间不为空
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid; // 二分范围缩小到 (left, mid)
        } else {
            left = mid; // 二分范围缩小到 (mid, right)
        }
    }
    return right;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), cmp);
    long long ans = 0;
    int i = 0;

    int r = 0;
    int l = 0;

    for (i = 0; i < numsSize; i++)
    {
        r = upperBound(nums,i,upper - nums[i]);
        l = lowerBound(nums,i,lower - nums[i]);
        ans += r - l;
    }

    return ans;
}