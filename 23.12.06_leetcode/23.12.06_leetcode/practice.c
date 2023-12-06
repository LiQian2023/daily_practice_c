#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//2023.12.06力扣网刷题
//统计范围内的元音字符串数——数组、字符串——简单
//给你一个下标从 0 开始的字符串数组 words 和两个整数：left 和 right 。
//如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串 ，其中元音字母是 'a'、'e'、'i'、'o'、'u' 。
//返回 words[i] 是元音字符串的数目，其中 i 在闭区间[left, right] 内。
//示例 1：
//输入：words = ["are", "amy", "u"], left = 0, right = 2
//输出：2
//解释：
//- "are" 是一个元音字符串，因为它以 'a' 开头并以 'e' 结尾。
//- "amy" 不是元音字符串，因为它没有以元音字母结尾。
//- "u" 是一个元音字符串，因为它以 'u' 开头并以 'u' 结尾。
//在上述范围中的元音字符串数目为 2 。
//示例 2：
//输入：words = ["hey", "aeo", "mu", "ooo", "artro"], left = 1, right = 4
//输出：3
//解释：
//- "aeo" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
//- "mu" 不是元音字符串，因为它没有以元音字母开头。
//- "ooo" 是一个元音字符串，因为它以 'o' 开头并以 'o' 结尾。
//- "artro" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
//在上述范围中的元音字符串数目为 3 。
//提示：
//1 <= words.length <= 1000
//1 <= words[i].length <= 10
//words[i] 仅由小写英文字母组成
//0 <= left <= right < words.length
int vowelStrings(char** words, int wordsSize, int left, int right) {
	int count = 0;
	for (int i = left; i <= right; i++)
	{
		int len = strlen(words[i]);
		if ((words[i][0] == 'a') || (words[i][0] == 'e') || (words[i][0] == 'i') || (words[i][0] == 'o') || (words[i][0] == 'u'))
			if ((words[i][len-1] == 'a') || (words[i][len-1] == 'e') || (words[i][len-1] == 'i') || (words[i][len-1] == 'o') || (words[i][len-1] == 'u'))
				count++;
	}
	return count;
}
int main()
{
	char ch[100][10] = { 0 };
	int m = 0, i = 0;
	while (scanf("%d", &m) == 1)
	{
		for (i = 0; i < m; i++)
			scanf("%s", ch[i]);
		int a = 0, b = 0;
		scanf("%d%d", &a, &b);
		char* words[100] = { 0 };
		for (i = 0; i < m; i++)
			words[i] = ch[i];
		printf("%d\n", vowelStrings(words, m, a, b));
	}
	return 0;
}
//int main()
//{
//	char words[100][10] = { 0 };
//	int m = 0;
//	while (scanf("%d", &m) == 1)
//	{
//		for (int i = 0; i < m; i++)
//			scanf("%s", words[i]);
//		int left = 0, right = 0;
//		scanf("%d%d", &left, &right);
//		int count = 0;
//		for (int i = left; i <= right; i++)
//		{
//			int len = strlen(words[i]);
//			if ((words[i][0] == 'a') || (words[i][0] == 'e') || (words[i][0] == 'i') || (words[i][0] == 'o') || (words[i][0] == 'u'))
//				if ((words[i][len - 1] == 'a') || (words[i][len - 1] == 'e') || (words[i][len - 1] == 'i') || (words[i][len - 1] == 'o') || (words[i][len - 1] == 'u'))
//					count++;
//		}
//		printf("%d\n", count);
//	}
//	return 0;
//}

//void func(char** ch)
//{
//	;
//}
//int main()
//{
//	char* ch[10] = { "abd","bcd","abc" };
//	func(ch);
//	return 0;
//}

//void func(char** ch)
//{
//	;
//}
//int main()
//{
//	char* ch1[10]= { "abc","cde","des" };
//	char(*ch)[10] = &ch1;
//	func(&ch);
//	return 0;
//}