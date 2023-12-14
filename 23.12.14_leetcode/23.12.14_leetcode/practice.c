#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.14力扣网刷题
// 寻找比目标字母大的最小字母——数组、二分查找——简单
//给你一个字符数组 letters，该数组按非递减顺序排序，以及一个字符 target。letters 里至少有两个不同的字符。
//返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的第一个字符。
//示例 1：
//输入 : letters = ["c", "f", "j"]，target = "a"
//输出 : "c"
//解释：letters 中字典上比 'a' 大的最小字符是 'c'。
//示例 2 :
//	输入 : letters = ["c", "f", "j"], target = "c"
//	输出 : "f"
//	解释：letters 中字典顺序上大于 'c' 的最小字符是 'f'。
//	示例 3 :
//	输入 : letters = ["x", "x", "y", "y"], target = "z"
//	输出 : "x"
//	解释：letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。
//	提示：
//	2 <= letters.length <= 104
//	letters[i] 是一个小写字母
//	letters 按非递减顺序排序
//	letters 最少包含两个不同的字母
//	target 是一个小写字母

//法一：二分查找
char nextGreatestLetter1(char* letters, int lettersSize, char target) {
	int L = 0, R = lettersSize - 1, M = 0;
	while (L <= R)
	{
		M = (L + R) / 2;
		if (letters[M] == target)
		{
			if (letters[M + 1] > target && M < lettersSize - 1)
				return letters[M + 1];
			else
				L = M + 1;
		}
		if (letters[M] > target)
		{
			if (letters[M - 1] <= target && M > 0)
				return letters[M];
			else
				R = M - 1;
		}
		if (letters[M] < target)
		{
			if (letters[M + 1] > target && M < lettersSize - 1)
				return letters[M + 1];
			else
				L = M + 1;
		}
	}
	return letters[0];
}
//法二：循序查找
char nextGreatestLetter2(char* letters, int lettersSize, char target) {
	char* start = letters;
	for (int i = 0; i < lettersSize; i++)
	{
		if (*start <= target)
			start++;
		else
			return *start;
	}
	return *letters;
}
//法三：二分查找——优化
char nextGreatestLetter(char* letters, int lettersSize, char target) {
	int l = 0, r = lettersSize - 1, m = 0;
	if (letters[r] <= target)
		return letters[0];
	else
	{
		while (l < r)
		{
			m = (l + r) / 2;
			if (letters[m] <= target)
				l = m + 1;
			if (letters[m] > target)
				r = m;
		}
	}
	return letters[l];
}
int main()
{
	char ch[10000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		getchar();
		for (int i = 0; i < n; i++)
			scanf("%c", &ch[i]);
		getchar();
		char k = 0;
		scanf("%c", &k);
		char ret = nextGreatestLetter(ch, n, k);
		printf("%c\n", ret);
	}
	return 0;
}