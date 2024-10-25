#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.10.25力扣网刷题
//执行操作可获得的最大总奖励 I——数组、动态规划——中等
//给你一个整数数组 rewardValues，长度为 n，代表奖励的值。
//最初，你的总奖励 x 为 0，所有下标都是 未标记 的。你可以执行以下操作 任意次 ：
//从区间[0, n - 1] 中选择一个 未标记 的下标 i。
//如果 rewardValues[i] 大于 你当前的总奖励 x，则将 rewardValues[i] 加到 x 上（即 x = x + rewardValues[i]），并 标记 下标 i。
//以整数形式返回执行最优操作能够获得的 最大 总奖励。
//示例 1：
//输入：rewardValues = [1, 1, 3, 3]
//输出：4
//解释：
//依次标记下标 0 和 2，总奖励为 4，这是可获得的最大值。
//示例 2：
//输入：rewardValues = [1, 6, 4, 3, 2]
//输出：11
//解释：
//依次标记下标 0、2 和 1。总奖励为 11，这是可获得的最大值。
//提示：
//1 <= rewardValues.length <= 2000
//1 <= rewardValues[i] <= 2000

//方法一：动态规划
void CountSort(int* a, int len, int* size) {
	int max = a[0], min = a[0];
	int nums[2001] = { 0 };
	for (int i = 0; i < len; i++) {
		nums[a[i]] += 1;
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	for (int i = min; i <= max; i++) {
		if (nums[i]) {
			a[*size] = i;
			*size += 1;
			nums[i] -= 1;
		}
	}
}
int maxTotalReward(int* rewardValues, int rewardValuesSize) {
	int size = 0;
	CountSort(rewardValues, rewardValuesSize, &size);
	int max = rewardValues[size - 1];
	int* dp = (int*)calloc(2 * max, sizeof(int));
	assert(dp);
	dp[0] = 1;
	for (int i = 0; i < size; i++) {
		int x = rewardValues[i];
		for (int k = 2 * x - 1; k >= x; k--) {
			if (dp[k - x] == 1)
				dp[k] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 2 * max; i++) {
		if (dp[i])
			ans = i;
	}
	free(dp);
	return ans;
}