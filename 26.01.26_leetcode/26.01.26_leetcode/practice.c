#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
//2026.01.26力扣网刷题
//LCR 088. 使用最小花费爬楼梯——数组、动态规划——简单
//数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
//每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。
//请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
//示例 1：
//输入：cost = [10, 15, 20]
//输出：15
//解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。
//示例 2：
//输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//输出：6
//解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
//提示：
//2 <= cost.length <= 1000
//0 <= cost[i] <= 999
//注意：本题与主站 746 题相同： https ://leetcode.cn/problems/min-cost-climbing-stairs/

int minCostClimbingStairs1(int* cost, int costSize) {
	int* dp = (int*)calloc(costSize, sizeof(int));
	assert(dp);
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < costSize; i++) {
		int a = dp[i - 2] + cost[i];
		int b = dp[i - 1] + cost[i];
		dp[i] = a < b ? a : b;
	}
	int ans = dp[costSize - 1] < dp[costSize - 2] ? dp[costSize - 1] : dp[costSize - 2];
	free(dp);
	return ans;
}

int minCostClimbingStairs2(int* cost, int costSize) {
	int first = cost[0], second = cost[1];
	for (int i = 2; i < costSize; i++) {
		if (i % 2 == 0) {
			first = fmin(first, second) + cost[i];
		}
		else {
			second = fmin(first, second) + cost[i];
		}
	}
	return fmin(first, second);
}