#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.10.01力扣网刷题
//494. 目标和——数组、动态规划、回溯、背包问题、0-1背包——中等
//给你一个非负整数数组 nums 和一个整数 target 。
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//示例 1：
//输入：nums = [1, 1, 1, 1, 1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//示例 2：
//输入：nums = [1], target = 1
//输出：1
//提示：
//1 <= nums.length <= 20
//0 <= nums[i] <= 1000
//0 <= sum(nums[i]) <= 1000
//- 1000 <= target <= 1000

int dfs(int* nums, int len, int target, int num, int start) {
	if (start == len) {
		if (num == target) {
			return 1;
		}
		return 0;
	}
	int l = dfs(nums, len, target, num + nums[start], start + 1);
	int r = dfs(nums, len, target, num - nums[start], start + 1);
	return l + r;
}

int findTargetSumWays1(int* nums, int numsSize, int target) {
	return dfs(nums, numsSize, target, 0, 0);
}
