#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
//2023.11.23力扣网刷题
// 整数各位的积和之差——数学——简单
//给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。
//示例 1：
//输入：n = 234
//输出：15
//解释：
//各位数之积 = 2 * 3 * 4 = 24
//各位数之和 = 2 + 3 + 4 = 9
//结果 = 24 - 9 = 15
//示例 2：
//输入：n = 4421
//输出：21
//解释：
//各位数之积 = 4 * 4 * 2 * 1 = 32
//各位数之和 = 4 + 4 + 2 + 1 = 11
//结果 = 32 - 11 = 21
//提示：
//1 <= n <= 10 ^ 5
int subtractProductAndSum(int n) {
	int sum = 0;
	int mul = 1;
	for (n; n > 0; n /= 10)
	{
		sum += n % 10;
		mul *= n % 10;
	}
	return mul - sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = subtractProductAndSum(n);
	printf("%d\n", ret);
	return 0;
}


#if 0
////转换成小写字母——字符串——简单
////给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。
////示例 1：
////输入：s = "Hello"
////输出："hello"
////示例 2：
////输入：s = "here"
////输出："here"
////示例 3：
////输入：s = "LOVELY"
////输出："lovely"
////提示：
////1 <= s.length <= 100
////s 由 ASCII 字符集中的可打印字符组成
//char* toLowerCase(char* s) {
//	char* a = s;
//	for (int i = 0; s[i]; i++)
//	{
//		if (isupper(s[i]))
//			a[i] = tolower(s[i]);
//	}
//	return a;
//}
//int main()
//{
//	char ch[] = "Hello";
//	char ch1[100] = { 0 };
//	ch1 = toLowerCase(ch);
//	printf("%s\n", ch1);
//	return 0;
//}
#endif