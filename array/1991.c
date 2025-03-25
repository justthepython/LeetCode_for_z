
//1、采用遍历的方式
//从第一个索引开始，分别计算索引左右两边的和
//如果相等，直接返回索引
//如果不相等，则索引加一，直到索引超出数组大小

int sum(int* nums, int numsSize)
{
    if (NULL == nums)
    {
        return 0;
    }

    int result = 0;
    int i = 0;

    for(i = 0; i < numsSize; i++)
    {
        result += *(nums + i);
    }

    return result;
}

int pivotIndex(int* nums, int numsSize)
{
    int i = 0;
    int left_sum = 0;
    int right_sum = 0;

    while(i < numsSize)
    {
        left_sum = sum(nums,i);
        right_sum = sum(nums+i+1,numsSize - i - 1);

        if (left_sum == right_sum)
        {
            return i;
        }
        else if (left_sum != right_sum)
        {
            i++;
        }
    }

    return -1;
}

//2、依靠等量关系解析
//当这样的中心索引存在时，总和 = 2 * 左边和 + 中心索引对应的数值

int sum(int* nums, int numsSize)
{
    if (NULL == nums)
    {
        return 0;
    }

    int result = 0;
    int i = 0;

    for(i = 0; i < numsSize; i++)
    {
        result += *(nums + i);
    }

    return result;
}

int pivotIndex(int* nums, int numsSize)
{
    int i = 0;
    int left_sum = 0;
    int all_sum = sum(nums,numsSize);

    for(i = 0; i < numsSize; i++)
    {
        left_sum = sum(nums,i);

        if (left_sum == all_sum - left_sum*2 - nums[i])
        {
            return i;
        }
    }

    return -1;
}

//3、可以不用sum函数，那样的话，需要巧妙使用一次数组的总和
int pivotIndex(int* nums, int numsSize)
{
    int left_sum = 0;
    int all_sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        all_sum += nums[i];
    }

    for(int i = 0; i < numsSize; i++)
    {
        all_sum -= nums[i];

        if (left_sum == all_sum)
        {
            return i;
        }

        left_sum += nums[i];
    }

    return -1;
}

