// 给你一个数组 time ，其中 time[i] 表示第 i 辆公交车完成 一趟旅途 所需要花费的时间。

// 每辆公交车可以 连续 完成多趟旅途，也就是说，一辆公交车当前旅途完成后，可以 立马开始 下一趟旅途。每辆公交车 独立 运行，也就是说可以同时有多辆公交车在运行且互不影响。

// 给你一个整数 totalTrips ，表示所有公交车 总共 需要完成的旅途数目。请你返回完成 至少 totalTrips 趟旅途需要花费的 最少 时间。

// #define MIN(a, b) ((b) < (a) ? (b) : (a))
// #define MAX(a, b) ((b) > (a) ? (b) : (a))

// bool check(long long x, int* time, int timeSize, int totalTrips) {
//     long long sum = 0;
//     for (int i = 0; i < timeSize; i++) {
//         sum += x / time[i];
//         if (sum >= totalTrips) {
//             return true;
//         }
//     }
//     return false;
// }

// long long minimumTime(int* time, int timeSize, int totalTrips) {
//     int min_t = INT_MAX, max_t = 0;
//     for (int i = 0; i < timeSize; i++) {
//         min_t = MIN(min_t, time[i]);
//         max_t = MAX(max_t, time[i]);
//     }

//     int avg = (totalTrips - 1) / timeSize + 1;
//     // 循环不变量：check(left) 恒为 false
//     long long left = (long long) min_t * avg - 1;
//     // 循环不变量：check(right) 恒为 true
//     long long right = MIN((long long) max_t * avg, (long long) min_t * totalTrips);

//     // 开区间 (left, right) 不为空
//     while (left + 1 < right) {
//         long long mid = (left + right) / 2;
//         if (check(mid, time, timeSize, totalTrips)) {
//             // 缩小二分区间为 (left, mid)
//             right = mid;
//         } else {
//             // 缩小二分区间为 (mid, right)
//             left = mid;
//         }
//     }

//     // 此时 left 等于 right-1
//     // check(left) = false 且 check(right) = true，所以答案是 right
//     return right; // 最小的 true
// }

#define MIN(a,b) ((b) < (a) ? (b) : (a))
#define MAX(a,b) ((b) > (a) ? (b) : (a))

bool check(long long mid, int* time, int timeSize,int totalTrips)
{
    long long sum = 0;
    for (int i = 0; i < timeSize; i++)
    {
        sum += mid / time[i];
        if (sum >= totalTrips)
        {
            return true;
        }
    }
    return false;
}

long long minimumTime(int* time, int timeSize, int totalTrips) {
    int min_t = INT_MAX;
    int max_t = 0;

    for (int i = 0; i < timeSize; i++)
    {
        min_t = MIN(min_t, time[i]);
        max_t = MAX(max_t, time[i]);
    }

    int avg = (totalTrips - 1)/timeSize + 1;
    long long left = (long long)min_t * avg - 1;
    long long right = MIN((long long)max_t *avg,(long long)min_t*totalTrips);

    while (left + 1 < right)
    {
        long long mid = (left + right) / 2;
        if (check(mid,time,timeSize,totalTrips))
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
