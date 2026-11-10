#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

//2026.11.10力扣网刷题
//3693. 爬楼梯 II——高级工程师、第166场双周赛——中等
//你正在爬一个有 n + 1 级台阶的楼梯，台阶编号从 0 到 n。
//你还得到了一个长度为 n 的 下标从 1 开始 的整数数组 costs，其中 costs[i] 是第 i 级台阶的成本。
//从第 i 级台阶，你 只能 跳到第 i + 1、i + 2 或 i + 3 级台阶。从第 i 级台阶跳到第 j 级台阶的成本定义为： costs[j] + (j - i)2
//你从第 0 级台阶开始，初始 cost = 0。
//返回到达第 n 级台阶所需的 最小 总成本。
//示例 1:
//输入：n = 4, costs = [1, 2, 3, 4]
//输出：13
//解释：
//一个最优路径是 0 → 1 → 2 → 4
//跳跃	成本计算	成本
//0 → 1	costs[1] + (1 - 0)2 = 1 + 1	2
//1 → 2	costs[2] + (2 - 1)2 = 2 + 1	3
//2 → 4	costs[4] + (4 - 2)2 = 4 + 4	8
//因此，最小总成本为 2 + 3 + 8 = 13
//示例 2:
//输入：n = 4, costs = [5, 1, 6, 2]
//输出：11
//解释：
//一个最优路径是 0 → 2 → 4
//跳跃	成本计算	成本
//0 → 2	costs[2] + (2 - 0)2 = 1 + 4	5
//2 → 4	costs[4] + (4 - 2)2 = 2 + 4	6
//因此，最小总成本为 5 + 6 = 11
//示例 3:
//输入：n = 3, costs = [9, 8, 3]
//输出：12
//解释：
//最优路径是 0 → 3，总成本 = costs[3] + (3 - 0)2 = 3 + 9 = 12
//提示:
//1 <= n == costs.length <= 10^5
//1 <= costs[i] <= 10^4

int climbStairs(int n, int* costs, int costsSize) {
	int ans = 0;
	int* dp = (int*)calloc(costsSize + 1, sizeof(int));
	assert(dp);
	for (int i = n - 1; i >= 0; i--) {
		int a = INT_MAX, b = INT_MAX, c = INT_MAX;
		if (i + 1 <= n) {
			a = costs[i] + 1 + dp[i + 1];
		}
		if (i + 2 <= n) {
			b = costs[i + 1] + 4 + dp[i + 2];
		}
		if (i + 3 <= n) {
			c = costs[i + 2] + 9 + dp[i + 3];
		}
		if (a > b) {
			dp[i] = b < c ? b : c;
		}
		else {
			dp[i] = a < c ? a : c;
		}
	}
	ans = dp[0];
	free(dp);
	return ans;
}