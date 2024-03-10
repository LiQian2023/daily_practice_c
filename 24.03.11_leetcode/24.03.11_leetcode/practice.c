#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//2024.03.11力扣网刷题
//质数排列——数学——简单
//请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。
//让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。
//由于答案可能会很大，所以请你返回答案 模 mod 10 ^ 9 + 7 之后的结果即可。
//示例 1：
//输入：n = 5
//输出：12
//解释：举个例子，[1, 2, 5, 4, 3] 是一个有效的排列，但[5, 2, 3, 4, 1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
//示例 2：
//输入：n = 100
//输出：682289015
//提示：
//1 <= n <= 100

bool isprime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int numPrimeArrangements(int n) {
	int prime = 0;
	int unprime = 0;
	for (int i = 1; i <= n; i++) {
		if (isprime(i))
			prime++;
		else
			unprime++;
	}
	long mul1 = 1, mul2 = 1;
	for (int i = 1; i <= prime; i++) {
		mul1 *= i;
		mul1 %= 1000000007;
	}
	for (int i = 1; i <= unprime; i++) {
		mul2 *= i;
		mul2 %= 1000000007;
	}
	return mul1 * mul2 % 1000000007;
}

int main() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", numPrimeArrangements(n));
	}
	return 0;
}