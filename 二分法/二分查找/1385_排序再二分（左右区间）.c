// 给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。
// 「距离值」 定义为符合此距离要求的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d 。

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

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

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    qsort(arr2, arr2Size, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < arr1Size; i++) {
        int x = arr1[i];
        int j = lowerBound(arr2, arr2Size, x - d);
        if (j == arr2Size || arr2[j] > x + d) {
            ans++;
        }
    }
    return ans;
}
