#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.11.25力扣网刷题
//跳跃训练——记忆化搜索、数学、动态规划——简单
//今天的有氧运动训练内容是在一个长条形的平台上跳跃。平台有 num 个小格子，每次可以选择跳 一个格子 或者 两个格子。请返回在训练过程中，学员们共有多少种不同的跳跃方式。
//结果可能过大，因此结果需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。
//示例 1：
//输入：n = 2
//输出：2
//示例 2：
//输入：n = 5
//输出：8
//提示：
//0 <= n <= 100
//注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/

//方法一：数学
#define MOD 1000000007
int trainWays(int num) {
	if (num == 0 || num == 1)
		return 1;
	int a = 1, b = 1, c = 2;
	for (int i = 3; i <= num; i++) {
		a = b % MOD;
		b = c % MOD;
		c = (a + b) % MOD;
	}
	return c;
}

//方法二：动态规划
int trainWays(int num) {
	int* dp = (int*)calloc(3, sizeof(int));
	assert(dp);
	dp[0] = 1;
	dp[1] = 1;
	int i = 2;
	for (int j = 2; j <= num; j += 1, i = (i + 1) % 3) {
		int a = (i + 1) % 3;
		int b = (i + 2) % 3;
		dp[i] = (dp[a] % MOD + dp[b] % MOD) % MOD;
	}
	i = (i + 2) % 3;
	int ans = num >= 2 ? dp[i] : 1;
	free(dp);
	return ans;
}
