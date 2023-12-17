#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.17力扣网刷题
//使用最小花费爬楼梯——数组、动态规划——简单
//给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//请你计算并返回达到楼梯顶部的最低花费。
//示例 1：
//输入：cost = [10, 15, 20]
//输出：15
//解释：你将从下标为 1 的台阶开始。
//- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
//总花费为 15 。
//示例 2：
//输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//输出：6
//解释：你将从下标为 0 的台阶开始。
//- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
//- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
//- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
//总花费为 6 。
//提示：
//2 <= cost.length <= 1000
//0 <= cost[i] <= 999

//以此求和，保证每次的和为最小值
int minCostClimbingStairs(int* cost, int costSize) {
	if (costSize == 2)
		return cost[0] < cost[1] ? cost[0] : cost[1];
	if (costSize == 3)
		return cost[0] + cost[2] > cost[1] ? cost[1] : cost[0] + cost[2];
	if (costSize == 4)
	{
		int sum1 = cost[0] + cost[2];
		int sum2 = cost[1] + cost[2];
		int sum3 = cost[1] + cost[3];
		int min = sum1;
		if (min > sum2)
			min = sum2;
		if (min > sum3)
			min = sum3;
		return min;
	}
}

//方法一：动态规划——官方题解
int minCostClimbingStairs(int* cost, int costSize) {
	int dp[costSize + 1];
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= costSize; i++) {
		dp[i] = fmin(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
	}
	return dp[costSize];
}
int main()
{
	int arr[1000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int ret = minCostClimbingStairs(arr, n);
		printf("%d\n", ret);
	}
	return 0;
}