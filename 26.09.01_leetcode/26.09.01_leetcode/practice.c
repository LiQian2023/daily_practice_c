#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.09.01力扣网刷题
//4000. 给定数位和的最大整数——中级工程师、贪心、数学、第512场周赛——简单
//给你两个非负整数 n 和 s。
//返回满足下述条件的 最大 整数：
//最多有 n 位数字。
//其各位数字之和等于 s 。
//如果不存在这样的整数，则返回 - 1。
//示例 1：
//输入： n = 2, s = 9
//输出： 90
//解释：
//最多由 2 位数字组成且各位数字之和为 9 的最大整数是 90。
//示例 2：
//输入： n = 2, s = 19
//输出： - 1
//解释：
//不存在最多由 2 位数字组成且各位数字之和为 19 的整数，因此答案为 - 1。
//示例 3：
//输入： n = 5, s = 0
//输出： 0
//解释：
//唯一一个各位数字之和为 0 的非负整数是 0。
//提示：
//1 <= n <= 5
//0 <= s <= 100

int largestInteger1(int n, int s) {
	int num = 0;
	while (n) {
		num *= 10;
		if (s >= 9) {
			num += 9;
			s -= 9;
		}
		else {
			num += s;
			s -= s;
		}
		n -= 1;
	}
	return s == 0 ? num : -1;
}

int largestInteger(int n, int s) {
	if (s > 9 * n) {
		return -1;
	}
	int nine = s / 9, r = s % 9;
	int p[6] = { 1, 10, 100, 1000, 10000,100000 };
	int ans = p[n] - p[n - nine];
	if (r) {
		ans += r * p[n - nine - 1];
	}
	return ans;
}