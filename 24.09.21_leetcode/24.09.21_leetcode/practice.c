#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
//2024.09.21力扣网刷题
//最接近的三数之和——数组、双指针、排序——中等
//给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
//返回这三个数的和。
//假定每组输入只存在恰好一个解。
//示例 1：
//输入：nums = [-1, 2, 1, -4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
//示例 2：
//输入：nums = [0, 0, 0], target = 1
//输出：0
//解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
//提示：
//3 <= nums.length <= 1000
//- 1000 <= nums[i] <= 1000
//- 10^4 <= target <= 10^4

void CountSort(int* a, int n) {
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	int nums[2001] = { 0 };
	for (int i = 0; i < n; i++) {
		nums[a[i] - min] += 1;
	}
	n = 0;
	for (int i = min; i <= max; i++) {
		while (nums[i - min]) {
			a[n++] = i;
			nums[i - min] -= 1;
		}
	}
}
//方法一：双指针
int threeSumClosest(int* nums, int numsSize, int target) {
	CountSort(nums, numsSize);
	int min = target - (nums[0] + nums[1] + nums[2]);
	for (int i = 0; i < numsSize; i++) {
		if (i && nums[i] == nums[i - 1])
			continue;
		int l = i + 1, r = numsSize - 1;
		while (l < r) {
			int tmp = nums[i] + nums[l] + nums[r];
			if (abs(min) > abs(target - tmp))
				min = target - tmp;
			if (tmp == target) {
				break;
			}
			else if (tmp > target)
				r -= 1;
			else
				l += 1;
		}
	}
	return target - min;
}