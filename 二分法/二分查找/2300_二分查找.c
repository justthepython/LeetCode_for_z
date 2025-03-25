// 给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。
// 同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。
// 请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// 返回 nums 中的第一个大于 target 的元素下标
int upperBound(int* nums, int numsSize, int target) {
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int* ans = malloc(spellsSize * sizeof(int));
    qsort(potions, potionsSize, sizeof(int), cmp);

    for(int i = 0; i < spellsSize; i++)
    {
        long long target = (success - 1) / spells[i] + 1;
        if (target < potions[potionsSize - 1])
        {
            ans[i] = potionsSize - upperBound(potions,potionsSize,target);
        }
        else
        {
            ans[i] = 0;
        }
    }

    *returnSize = spellsSize;
    return ans;
}