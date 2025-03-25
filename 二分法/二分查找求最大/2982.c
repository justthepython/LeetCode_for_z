
// 给你一个仅由小写英文字母组成的字符串 s 。

// 如果一个字符串仅由单一字符组成，那么它被称为 特殊 字符串。例如，字符串 "abc" 不是特殊字符串，
// 而字符串 "ddd"、"zz" 和 "f" 是特殊字符串。

// 返回在 s 中出现 至少三次 的 最长特殊子字符串 的长度，如果不存在出现至少三次的特殊子字符串，则返回 -1 。

// 子字符串 是字符串中的一个连续 非空 字符序列。


int check(char* s, int mid, int len) {
    int arr[26] = {0};
    for (int i = 0; i < len;) {
        int j = i;
        while (j < len && s[j] == s[i]) {
            j++;
        }
        arr[s[i] - 'a'] += fmax(0, j - i - mid + 1);
        i = j;
    }
    for (int i = 0; i < 26; ++i) {
        if (arr[i] >= 3)
            return 1;
    }
    return 0;
}
int maximumLength(char* s) {
    int len = strlen(s);
    int left = -1;
    int right = len;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(s, mid, len))
            left = mid;
        else
            right = mid;
    }
    return left > 0 ? left : -1;
}
