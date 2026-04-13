#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
//2024.03.24力扣网刷题
//反转字符串——双指针、字符串——简单
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//示例 1：
//输入：s = ["h", "e", "l", "l", "o"]
//输出：["o", "l", "l", "e", "h"]
//示例 2：
//输入：s = ["H", "a", "n", "n", "a", "h"]
//输出：["h", "a", "n", "n", "a", "H"]
//提示：
//1 <= s.length <= 105
//s[i] 都是 ASCII 码表中的可打印字符
void reverseString(char* s, int sSize) {
	int l = 0, r = sSize - 1;
	while (l < r) {
		char tmp = s[l];
		s[l] = s[r];
		s[r] = tmp;
		l++, r--;
	}
}

//2024.03.24力扣网刷题
//2026.04.14完成解答并通过力扣所有测试用例
//零钱兑换——广度优先搜索、数组、动态规划——中等
//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 - 1 。
//你可以认为每种硬币的数量是无限的。
//示例 1：
//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1
//示例 2：
//输入：coins = [2], amount = 3
//输出： - 1
//示例 3：
//输入：coins = [1], amount = 0
//输出：0
//提示：
//1 <= coins.length <= 12
//1 <= coins[i] <= 2^31 - 1
//0 <= amount <= 10^4


int coinChange(int* coins, int coinsSize, int amount) {
	long long* dp = (long long*)calloc(amount + 1, sizeof(long long));
	assert(dp);
	for (int i = 1; i <= amount; i++) {
		dp[i] = INT_MAX;
	}
	for (int i = 0; i <= amount; i++) {
		for (int j = 0; j < coinsSize; j++) {
			int tmp = i - coins[j];
			dp[i] = (tmp >= 0 ? min(dp[i], dp[tmp] + 1) : dp[i]);
		}
	}
	int ans = dp[amount] == INT_MAX ? -1 : dp[amount];
	free(dp);
	return ans;
}
// 状态转移方程
// [ 3,   5, 7] =11
// [ 4,   3, ]
// dp[0],dp[1]
// [0,-1,-1,1,-1,1,2,]
// 7->4
// 5->6->3->3
// dp[n] = dp[n - 1] + amount - dp[n - 1]
// 