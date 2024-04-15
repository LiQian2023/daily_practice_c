#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.03.16力扣网刷题
// Pow(x, n)——递归、数学——中等
// 2024.04.15完成解题——解题方法：折半递归
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
double myPow1(double x, int n) {
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
double myPow2(double x, int n) {
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

//法三：递归——栈溢出
double myPow3(double x, int n) {
	if (x == 1 || n == 0)
		return 1;
	if (n < 0)
		return 1 / (x * myPow3(x,++n));
	return x * myPow3(x, --n);
}

int count = 0;
//法四：折半递归——超出时间限制
double myPow4(double x, int n) {
	count++;
	if (x == 1.0 || n == 0.0)
		return 1;
	if (n == 1 || n == -1)
		return x;
	if (n == 2 || n == -2)
		return x * x;
	int a = n;
	double f1 = 0.0, f2 = 0.0;
	if (n < 0) {
		f1 = x * myPow4(x, -(a / 2));
		f2 = x * myPow4(x, -(a / 2 + a % 2));
	}
	else {
		f1 = x * myPow4(x, a / 2);
		f2 = x * myPow4(x, a / 2 + a % 2);
	}
	if (n < 0)
		return 1 / (f1 * f2);
	return f1 * f2;
}
//法五：折半递归——优化
double myPow(double x, int n) {
	if (x == 1 || n == 0)
		return 1;
	if (n == 1 )
		return x;
	if (n == -1)
		return 1 / x;
	if (n == 2)
		return x * x;
	if (n == -2)
		return 1 / (x * x);
	int a = n / 2;
	if (n < 0)
		a = -a;
	double mul = myPow(x, a);
	if (n % 2) {
		mul = mul * mul * x;
	}
	else {
		mul *= mul;
	}
	if (n < 0)
		return 1 / mul;
	return mul;
}


void test() {
	double x = 0;
	int n = 0;
	while(scanf("%lf%d", &x, &n) == 2) {
		printf("%lf\n", myPow(x, n));
		printf("%d\n", count);
	}
}

int main() {
	test();
	return 0;
}