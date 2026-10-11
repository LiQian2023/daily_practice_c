#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.10.12力扣网刷题
//101210. 连续三项斐波那契数之和——第523场周赛——简单
//给你一个整数 n。
//斐波那契数列 以 0 和 1 开始，之后的每个数都是前两个数之和。它的前几项为 0, 1, 1, 2, 3, 5, 8, 13, ...。
//如果 n 可以表示为斐波那契数列中 连续三项之和，则返回 true；否则返回 false。
//示例 1：
//输入： n = 16
//输出： true
//解释：
//连续三项 3、5 和 8 的和为 3 + 5 + 8 = 16。
//示例 2：
//输入： n = 8
//输出： false
//解释：
//虽然 1 + 2 + 5 = 8，但这三项在斐波那契数列中并不连续。不存在连续三项的和等于 8。
//示例 3：
//输入： n = 2
//输出： true
//解释：
//斐波那契数列的前三项之和为 0 + 1 + 1 = 2。
//提示：
//1 <= n <= 10^9
bool threeFibonacciSum(int n) {
	long long a = 0, b = 1, c = 1;
	long long ans = 0;
	for (int i = 2; i <= n && ans < n; i++) {
		ans = a + b + c;
		if (ans == n) {
			return true;
		}
		a = b;
		b = c;
		c = a + b;
	}
	return false;
}