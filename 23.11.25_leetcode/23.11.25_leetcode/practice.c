#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2023.11.25力扣刷题
//3的幂——递归、数学——简单
//给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
//整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3^x
//示例 1：
//输入：n = 27
//输出：true
//示例 2：
//输入：n = 0
//输出：false
//示例 3：
//输入：n = 9
//输出：true
//示例 4：
//输入：n = 45
//输出：false
//提示：
//- 2^31 <= n <= 2^31 - 1
//进阶：你能不使用循环或者递归来完成本题吗？

//判断3的倍数
bool isPowerOfThree1(int n) {
	while ((n >= 2) || (n <= 0))
	{
		if ((0 != n % 3) || (0 == n))
		{
			return false;
		}
		n >>= 1;
	}
	if (n == 1)
		return true;
}
//判断3的阶乘
bool isPowerOfThree(int n) {
	while ((n >= 2) || (n <= 0))
	{
		if ((0 != n % 3) || (0 == n))
		{
			return false;
		}
		n /= 3;
	}
	return true;
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		int ret = isPowerOfThree(n);
		printf("%d\n", ret);
	}
	return 0;
}
//3——0011
//9——1001
//27——0001 1011