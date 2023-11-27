#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2023.11.27力扣网刷题
// 丑数——数学——简单
//丑数 就是只包含质因数 2、3 和 5 的正整数。
//给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。
//示例 1：
//输入：n = 6
//输出：true
//解释：6 = 2 × 3
//示例 2：
//输入：n = 1
//输出：true
//解释：1 没有质因数，因此它的全部质因数是{ 2, 3, 5 } 的空集。习惯上将其视作第一个丑数。
//示例 3：
//输入：n = 14
//输出：false
//解释：14 不是丑数，因为它包含了另外一个质因数 7 。
//提示：
//- 2^31 <= n <= 2^31 - 1
//方法一——试除法
bool isUgly(int n) {
	if (n >= 1)
	{
		if (n % 2 == 0)
		{
			for (n; n > 1; n /= 2)
			{
				if (0 != n % 2)
					break;
			}
		}
		if (n % 3 == 0)
		{
			for (n; n > 1; n /= 3)
			{
				if (0 != n % 3)
					break;
			}
		}
		if (n % 5 == 0)
		{
			for (n; n > 1; n /= 5)
			{
				if (0 != n % 5)
					break;
			}
		}
		if (n == 1)
			return 1;
	}
	return 0;
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		printf("%s\n", (isUgly(n) ? "true" : "false"));
	}
	return 0;
}