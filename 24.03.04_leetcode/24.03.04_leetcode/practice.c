#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//2024.03.04力扣网刷题
// 斐波那契数——递归、记忆化搜索、数学、动态规划——简单
//斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
//F(0) = 0，F(1) = 1
//F(n) = F(n - 1) + F(n - 2)，其中 n > 1
//给定 n ，请计算 F(n) 。
//示例 1：
//输入：n = 2
//输出：1
//解释：F(2) = F(1) + F(0) = 1 + 0 = 1
//示例 2：
//输入：n = 3
//输出：2
//解释：F(3) = F(2) + F(1) = 1 + 1 = 2
//示例 3：
//输入：n = 4
//输出：3
//解释：F(4) = F(3) + F(2) = 2 + 1 = 3
//提示：
//0 <= n <= 30

int fib1(int n) {
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	return fib(n - 1) + fib(n - 2);
}

int fib2(int n) {
	if (n == 0)
		return 0;
	int a = 1, b = 1, c = 1;
	for (int i = 3; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}