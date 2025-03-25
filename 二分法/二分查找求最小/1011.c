// 传送带上的包裹必须在 days 天内从一个港口运送到另一个港口。

// 传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量（weights）的顺序往传送带上装载包裹。
//我们装载的重量不会超过船的最大运载重量。

// 返回能在 days 天内将传送带上的所有包裹送达的船的最低运载能力。

#define MIN(a,b) ((b) > (a) ? (a) : (b))
#define MAX(a,b) ((b) < (a) ? (a) : (b))

bool check(long long weight, int* weights, int weightsSize, int days)
{
    int weight_sum = 0;
    int day_sum = 0;

    for (int i = 0; i < weightsSize; i++)
    {
        weight_sum += weights[i];

        if (((i < weightsSize - 1) && (weight_sum + weights[i+1] > weight))
        || ((i == weightsSize - 1) && (weight_sum <= weight)))
        {
            day_sum += 1;
            weight_sum = 0;
        }
    }

    if (day_sum > days)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int max_t = 0;
    long long sum = 0;

    for (int i = 0; i < weightsSize; i++)
    {
        max_t = MAX(weights[i],max_t);
        sum += (long long)weights[i];
    }

    long long  left = (long long)max_t - 1;
    long long right = sum;

    while (left + 1 < right)
    {
        long long mid = (long long)((left+right) / 2);
        if (check(mid,weights,weightsSize,days))
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