#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//2024.08.10力扣网刷题
//找出数组排序后的目标下标——数组、二分查找、排序
//给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。
//目标下标 是一个满足 nums[i] == target 的下标 i 。
//将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增 顺序排列。
//示例 1：
//输入：nums = [1, 2, 5, 2, 3], target = 2
//输出：[1, 2]
//解释：排序后，nums 变为[1, 2, 2, 3, 5] 。
//满足 nums[i] == 2 的下标是 1 和 2 。
//示例 2：
//输入：nums = [1, 2, 5, 2, 3], target = 3
//输出：[3]
//解释：排序后，nums 变为[1, 2, 2, 3, 5] 。
//满足 nums[i] == 3 的下标是 3 。
//示例 3：
//输入：nums = [1, 2, 5, 2, 3], target = 5
//输出：[4]
//解释：排序后，nums 变为[1, 2, 2, 3, 5] 。
//满足 nums[i] == 5 的下标是 4 。
//示例 4：
//输入：nums = [1, 2, 5, 2, 3], target = 4
//输出：[]
//解释：nums 中不含值为 4 的元素。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i], target <= 100

//方法一：计数排序+二分查找
void CountSort(int* a, int len) {
	int nums[101] = { 0 };
	int min = a[0], max = a[0];
	//计数
	for (int i = 0; i < len; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
		nums[a[i]] += 1;
	}
	//排序
	len = 0;
	for (int i = min; i <= max; i++) {
		while (nums[i]) {
			a[len++] = i;
			nums[i] -= 1;
		}
	}
}
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
	CountSort(nums, numsSize);
	int ans_l = 0, ans_r = 0;
	int left = 0, right = numsSize - 1;
	//找左边界
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (nums[mid] >= target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	ans_l = right;
	//找右边界
	left = 0, right = numsSize - 1;
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (nums[mid] <= target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	ans_r = left;
	*returnSize = ans_r - ans_l - 1;
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	for (int i = 0; i < *returnSize; i++) {
		ans[i] = ans_l + 1;
		ans_l += 1;
	}
	return ans;
}