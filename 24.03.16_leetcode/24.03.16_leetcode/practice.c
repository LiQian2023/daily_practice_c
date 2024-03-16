#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.03.16力扣网刷题
// Pow(x, n)——递归、数学——中等
//实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。
//示例 1：
//输入：x = 2.00000, n = 10
//输出：1024.00000
//示例 2：
//输入：x = 2.10000, n = 3
//输出：9.26100
//示例 3：
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2^ - 2 = 1 / 2^2 = 1 / 4 = 0.25
//提示：
//- 100.0 < x < 100.0
//	- 2^31 <= n <= 2^31 - 1
//	n 是一个整数
//	要么 x 不为零，要么 n > 0 。
//	- 10^4 <= x^n <= 10^4

//法一：暴力求解
double myPow(double x, int n) {
	if (x == 1 || n == 0) {
		return 1;
	}
	if (n < 0) {
		x = 1 / x;
		n = -n;
	}
	double ans = 1.0;
	while (n--) {
		ans *= x;
	}
	return ans;
}

//法二：
double myPow(double x, int n) {
	long long N = n;
	if (N < 0) {
		x = 1 / x;
		N = -N;
	}
	double tmp = x;
	for (int i = 1; i <= N; i *= 2) {
		x *= x;
		if (N % 2) {
			x *= tmp;
			N--;
		}
	}
	return x;
}