#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.22力扣网刷题
//排列硬币——数学、二分查找——简单
//你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
//给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。
//示例 1：
//1
//11
//110
//输入：n = 5
//输出：2
//解释：因为第三行不完整，所以返回 2 。
//示例 2：
//1
//11
//111
//1100
//输入：n = 8
//输出：3
//解释：因为第四行不完整，所以返回 3 。
//提示：
//1 <= n <= 2^31 - 1
//法一：暴力求解
int arrangeCoins1(int n) {
	for (int i = 1; n > 0; i++)
	{
		if (n - i < 0)
			return i - 1;
		else if (n - i == 0)
			return i;
		else
			n = n - i;
	}
	return 1;
}
//法二：等差数列求和公式Sn=(a1+an)*n/2、n=(an-a1)/(a2-a1)+1——整型溢出风险
int arrangeCoins2(int n) {
	int i = 1;
	for (i = 1; i * (i + 1) <= 2 * n; i++)
	{
		if (i * (i + 1) == 2 * n)
			return i;
	}
	return i - 1;
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		int ret = arrangeCoins(n);
		printf("%d\n", ret);
	}
	return 0;
}