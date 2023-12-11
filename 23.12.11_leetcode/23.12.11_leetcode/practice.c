#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.11力扣网刷题
//x 的平方根——数学、二分查找——简单
//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x** 0.5 。
//示例 1：
//输入：x = 4
//输出：2
//示例 2：
//输入：x = 8
//输出：2
//解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
//提示：
//0 <= x <= 2^31 - 1
int mySqrt(int x) {
	double n = 1.0, m = 0;
	do
	{
		n = (x / n + n) * 0.5;
		m = n * n - x;
	} while ((m >= 0 ? m : (-m)) > 0.0001);
	return n;
}
int main()
{
	int x = 0;
	while (scanf("%d", &x) == 1)
	{
		printf("%d\n", mySqrt(x));
	}
	return 0;
}