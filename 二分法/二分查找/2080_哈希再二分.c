
// 请你设计一个数据结构，它能求出给定子数组内一个给定值的 频率 。

// 子数组中一个值的 频率 指的是这个子数组中这个值的出现次数。

// 请你实现 RangeFreqQuery 类：

// RangeFreqQuery(int[] arr) 用下标从 0 开始的整数数组 arr 构造一个类的实例。
// int query(int left, int right, int value) 返回子数组 arr[left...right] 中 value 的 频率 。
// 一个 子数组 指的是数组中一段连续的元素。arr[left...right] 指的是 nums 中包含下标 left 和 right 在内 的中间一段连续元素。


#define MIN_SIZE 64

typedef struct {
    int value;
    int *indices;
    int size;
    int capbility;
    UT_hash_handle hh;
} Occurrence;

typedef struct {
    Occurrence *occurrence_map;  // 哈希表
} RangeFreqQuery;

// 查找下界
int lower_bound(int* arr, int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// 查找上界
int upper_bound(int* arr, int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}


RangeFreqQuery* rangeFreqQueryCreate(int* arr, int arrSize) {
    RangeFreqQuery* query = (RangeFreqQuery*)malloc(sizeof(RangeFreqQuery));
    query->occurrence_map = NULL;

    // 顺序遍历数组初始化哈希表
    for (int i = 0; i < arrSize; ++i) {
        int value = arr[i];
        Occurrence *occ;
        // 查找是否已有该数字的条目
        HASH_FIND_INT(query->occurrence_map, &value, occ);
        if (!occ) {
            // 如果没有该条目，则创建一个新的
            occ = (Occurrence*)malloc(sizeof(Occurrence));
            occ->value = value;
            occ->size = 0;
            occ->capbility = MIN_SIZE;
            occ->indices = (int*)malloc(occ->capbility * sizeof(int));
            HASH_ADD_INT(query->occurrence_map, value, occ);
        }
        // 将当前的下标加入到对应数字的下标数组中
        if (occ->size >= occ->capbility) {
            occ->capbility *= 2;
            occ->indices = (int*)realloc(occ->indices, occ->capbility * sizeof(int));
        }
        occ->indices[occ->size] = i;
        occ->size++;
    }

    return query;
}

int rangeFreqQueryQuery(RangeFreqQuery* obj, int left, int right, int value) {
    Occurrence* occ;
    HASH_FIND_INT(obj->occurrence_map, &value, occ);
    if (!occ || occ->size == 0) {
        return 0;  // 没有该值
    }

    // 两次二分查找计算子数组内出现次数
    int l = lower_bound(occ->indices, occ->size, left);
    int r = upper_bound(occ->indices, occ->size, right);
    return r - l;
}

void rangeFreqQueryFree(RangeFreqQuery* obj) {
    Occurrence *current, *tmp;
    HASH_ITER(hh, obj->occurrence_map, current, tmp) {
        free(current->indices);
        HASH_DEL(obj->occurrence_map, current);
        free(current);
    }
    free(obj);
}

/**
 * Your RangeFreqQuery struct will be instantiated and called as such:
 * RangeFreqQuery* obj = rangeFreqQueryCreate(arr, arrSize);
 * int param_1 = rangeFreqQueryQuery(obj, left, right, value);

 * rangeFreqQueryFree(obj);
*/