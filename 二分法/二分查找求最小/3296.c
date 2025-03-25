// 给你一个整数 mountainHeight 表示山的高度。
// 同时给你一个整数数组 workerTimes，表示工人们的工作时间（单位：秒）。
// 工人们需要 同时 进行工作以 降低 山的高度。对于工人 i :

// 山的高度降低 x，需要花费 workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x 秒。例如：
// 山的高度降低 1，需要 workerTimes[i] 秒。
// 山的高度降低 2，需要 workerTimes[i] + workerTimes[i] * 2 秒，依此类推。
// 返回一个整数，表示工人们使山的高度降低到 0 所需的 最少 秒数。

#define MIN(a,b) ((b) < (a) ? (b) : (a))
#define MAX(a,b) ((b) > (a) ? (b) : (a))

bool check(long long mid, int* time, int timeSize,int height)
{
    long long sum = 0;
    long long k = 0;

    for (int i = 0; i < timeSize; i++)
    {
        k = mid / time[i];

        sum += ((int)sqrt(1+8*k) - 1) / 2;

        if (sum >= height)
        {
            return true;
        }
    }
    return false;
}

long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize) {
    int min_t = INT_MAX;
    int max_t = 0;

    for (int i = 0; i < workerTimesSize; i++)
    {
        min_t = MIN(min_t, workerTimes[i]);
        max_t = MAX(max_t, workerTimes[i]);
    }

    long long left = 0;
    long long right = (long long)max_t*mountainHeight*(mountainHeight+1)/2;

    while (left + 1 < right)
    {
        long long mid = (left + right) / 2;
        if (check(mid,workerTimes,workerTimesSize,mountainHeight))
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

