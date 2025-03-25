
// 给你一个 下标从 0 开始 的整数数组 candies 。数组中的每个元素表示大小为 candies[i] 的一堆糖果。
//你可以将每堆糖果分成任意数量的 子堆 ，但 无法 再将两堆合并到一起。

// 另给你一个整数 k 。你需要将这些糖果分配给 k 个小孩，使每个小孩分到 相同 数量的糖果。
//每个小孩可以拿走 至多一堆 糖果，有些糖果可能会不被分配。

// 返回每个小孩可以拿走的 最大糖果数目 。

#define MIN(a,b) ((b) > (a) ? (a) : (b))
#define MAX(a,b) ((b) < (a) ? (a) : (b))

bool check(long long candy, int* candies, int candiesSize, long long k) {

    long long k_sum = 0;

    for (int i = 0; i < candiesSize; i++)
    {
        k_sum += (long long)(candies[i] / candy);
    }

    if (k_sum < k)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int maximumCandies(int* candies, int candiesSize, long long k) {

    int max_t = 0;

    for (int i = 0; i < candiesSize; i++)
    {
        max_t = MAX(candies[i],max_t);
    }

    int left = 0;
    int right = max_t + 1;


    while (left + 1 < right)
    {
        long long mid = (left + right) / 2;

        if (check(mid,candies,candiesSize,k))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}