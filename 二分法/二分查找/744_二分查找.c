// 给你一个字符数组 letters，该数组按非递减顺序排序，以及一个字符 target。letters 里至少有两个不同的字符。

// 返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的第一个字符。

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = -1;
    int right = lettersSize;
    int mid = 0;

    while(left + 1 < right)
    {
        mid = left + (right - left) / 2;
        if (letters[mid] > target)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    if (left + 1 < lettersSize)
    {
        return letters[left + 1];
    }
    else
    {
        return letters[0];
    }
}