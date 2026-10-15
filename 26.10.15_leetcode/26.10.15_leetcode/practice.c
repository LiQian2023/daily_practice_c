#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.10.15力扣网刷题
//2913. 子数组不同元素数目的平方和 I——中级工程师、树状数组、线段树、数组、哈希表、第116场双周赛——简单
//给你一个下标从 0 开始的整数数组 nums 。
//定义 nums 一个子数组的 不同计数 值如下：
//令 nums[i..j] 表示 nums 中所有下标在 i 到 j 范围内的元素构成的子数组（满足 0 <= i <= j < nums.length ），那么我们称子数组 nums[i..j] 中不同值的数目为 nums[i..j] 的不同计数。
//请你返回 nums 中所有子数组的 不同计数 的 平方 和。
//子数组指的是一个数组里面一段连续 非空 的元素序列。
//示例 1：
//输入：nums = [1, 2, 1]
//输出：15
//解释：六个子数组分别为：
//[1]: 1 个互不相同的元素。
//[2] : 1 个互不相同的元素。
//[1] : 1 个互不相同的元素。
//[1, 2] : 2 个互不相同的元素。
//[2, 1] : 2 个互不相同的元素。
//[1, 2, 1] : 2 个互不相同的元素。
//所有不同计数的平方和为 1^2 + 1^2 + 1^2 + 2^2 + 2^2 + 2^2 = 15 。
//示例 2：
//输入：nums = [2, 2]
//输出：3
//解释：三个子数组分别为：
//[2]: 1 个互不相同的元素。
//[2] : 1 个互不相同的元素。
//[2, 2] : 1 个互不相同的元素。
//所有不同计数的平方和为 1^2 + 1^2 + 1^2 = 3 。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
void DFS(int* nums, int len, bool* visited, int start, int num, int* ans) {
	*ans += num * num;
	if (start == len) {
		return;
	}
	if (!visited[nums[start]]) {
		num += 1;
	}
	visited[nums[start]] = true;
	DFS(nums, len, visited, start + 1, num, ans);
	visited[nums[start]] = false;
}
int sumCounts(int* nums, int numsSize) {
	bool* visited = (bool*)calloc(101, sizeof(bool));
	assert(visited);
	int num = 0, ans = 0;
	for (int i = 0; i < numsSize; i++) {
		DFS(nums, numsSize, visited, i, num, &ans);
	}
	free(visited);
	return ans;
}