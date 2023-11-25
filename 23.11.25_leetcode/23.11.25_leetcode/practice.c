#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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
//判断3的阶乘——迭代求解
bool isPowerOfThree2(int n) {
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
//判断3的阶乘——递归求解
bool isPowerOfThree3(int n) {
	bool a = true;
	if ((n >= 2) || (n <= 0))
	{
		if ((0 != n % 3) || (0 == n))
			return false;
		a= isPowerOfThree3(n /= 3);
	}
	return a;
}
//判断3的阶乘——试除法
bool isPowerOfThree4(int n) {
	int a = pow(3, 19);
	for (a; a > 0; a /= 3)
	{
		if (a == n)
			return true;
	}
	return false;
}
//判断3的阶乘——枚举法
bool isPowerOfThree(int n) {
	int a[20] = { 1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467 };
	for (int i=0; i <20; i++)
	{
		if (a[i] == n)
			return true;
	}
	return false;
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
//81——0101 0001