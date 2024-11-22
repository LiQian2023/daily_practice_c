#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

//2024.11.22力扣网刷题
//统计不是特殊数字的数字数量——数组、数学、数论——中等
//给你两个 正整数 l 和 r。对于任何数字 x，x 的所有正因数（除了 x 本身）被称为 x 的 真因数。
//如果一个数字恰好仅有两个 真因数，则称该数字为 特殊数字。例如：
//数字 4 是 特殊数字，因为它的真因数为 1 和 2。
//数字 6 不是 特殊数字，因为它的真因数为 1、2 和 3。
//返回区间[l, r] 内 不是 特殊数字 的数字数量。
//示例 1：
//输入： l = 5, r = 7
//输出： 3
//解释：
//区间[5, 7] 内不存在特殊数字。
//示例 2：
//输入： l = 4, r = 16
//输出： 11
//解释：
//区间[4, 16] 内的特殊数字为 4 和 9。
//提示：
//1 <= l <= r <= 10^9

//方法一：试除法——超时
bool Count(int n) {
	int ans = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (0 == n % i) {
			ans += 1;
			if (n / i != i)
				ans += 1;
		}
		if (ans > 2)
			break;
	}
	return ans == 2;
}

int nonSpecialCount1(int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; i++) {
		if (!Count(i)) {
			ans += 1;
		}
	}
	return ans;
}

//方法二：埃氏筛
int nonSpecialCount(int l, int r) {
	int base = (int)sqrt(r);
	bool* isprime = (bool*)calloc(base + 1, sizeof(bool));
	assert(isprime);
	int ans = r - l + 1;
	for (int i = 2; i <= base; i++) {
		if (isprime[i] == 0) {
			if (i * i >= l && i * i <= r)
				ans -= 1;
			for (int j = i * 2; j <= base; j += i) {
				isprime[j] = 1;
			}
		}
	}
	return ans;
}
//方法三：线性筛
int nonSpecialCount(int l, int r) {
	int base = (int)sqrt(r);
	bool* isprime = (bool*)calloc(base + 1, sizeof(bool));
	assert(isprime);
	int* prime = (int*)calloc(base + 1, sizeof(int));
	assert(prime);
	int primeSize = 0;
	int ans = r - l + 1;
	for (int i = 2; i <= base; i++) {
		if (isprime[i] == 0) {
			prime[primeSize++] = i;
			if (i * i >= l && i * i <= r)
				ans -= 1;
		}
		for (int j = 0; j < primeSize && i * prime[j] <= base; j++) {
			isprime[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
	free(isprime);
	free(prime);
	return ans;
}