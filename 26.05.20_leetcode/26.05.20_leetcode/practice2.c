#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.20力扣网刷题
//90. 64位整数乘法——位运算——简单
//求 a 乘 b 对 p 取模的值。
//输入格式
//第一行输入整数a，第二行输入整数b，第三行输入整数p。
//输出格式
//输出一个整数，表示a * b mod p的值。
//数据范围
//1≤a, b, p≤10^18
//输入样例：
//3
//4
//5
//输出样例：
//2

long long myMul1(long long a, long long b, long long p) {
	long long ans = 0;
	for (; b; b >>= 1) {
		if (b & 1) {
			ans = (ans + a) % p;
		}
		a = a * 2 % p;
	}
	return ans;
}

long long myMul(long long a, long long b, long long p) {
	a %= p, b %= p;
	unsigned long long n = a * b;
	unsigned long long c = (long double)a * b / p;
	long long ans = (long long)n % p - (long long)c * p % p;
	return (ans + p) % p;
}

int main() {
	long long a = 0, b = 0, p = 0;
	while (scanf("%lld%lld%lld", &a, &b, &p) == 3) {
		printf("%lld", myMul(a, b, p));
	}
	return 0;
}