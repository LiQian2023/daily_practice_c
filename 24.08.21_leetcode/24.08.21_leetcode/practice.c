#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//2024.08.21力扣网刷题
//与对应负数同时存在的最大正整数——数组、哈希表、双指针、排序——简单
//给你一个 不包含 任何零的整数数组 nums ，找出自身与对应的负数都在数组中存在的最大正整数 k 。
//返回正整数 k ，如果不存在这样的整数，返回 - 1 。
//示例 1：
//输入：nums = [-1, 2, -3, 3]
//输出：3
//解释：3 是数组中唯一一个满足题目要求的 k 。
//示例 2：
//输入：nums = [-1, 10, 6, 7, -7, 1]
//输出：7
//解释：数组中存在 1 和 7 对应的负数，7 的值更大。
//示例 3：
//输入：nums = [-10, 8, 6, 7, -2, -3]
//输出： - 1
//解释：不存在满足题目要求的 k ，返回 - 1 。
//提示：
//1 <= nums.length <= 1000
//- 1000 <= nums[i] <= 1000
//nums[i] != 0

//计数排序
void CountSort(int* a, int n) {
	int count[2001] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < n; i++) {
		count[a[i] - min] += 1;
	}
	n = 0;
	for (int i = min; i <= max; i++) {
		while (count[i - min]) {
			a[n] = i;
			n += 1;
			count[i - min] -= 1;
		}
	}
}
int findMaxK(int* nums, int numsSize) {
	int ans = -1;
	CountSort(nums, numsSize);
	int l = 0, r = numsSize - 1;
	if (nums[r] >= 0 && nums[l] < 0) {
		while (l < r) {
			if (-nums[l] > nums[r])
				l += 1;
			else if (-nums[l] < nums[r])
				r -= 1;
			else{
				ans = nums[r];
				break;
			}
		}
	}
	return ans;
}