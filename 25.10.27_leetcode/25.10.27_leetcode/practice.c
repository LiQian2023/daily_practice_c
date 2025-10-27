#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.10.27力扣网刷题
//检查数组是否经排序和轮转得到——数组、第227场周赛——简单
//给你一个数组 nums 。nums 的源数组中，所有元素与 nums 相同，但按非递减顺序排列。
//如果 nums 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 true ；否则，返回 false 。
//源数组中可能存在 重复项 。
//注意：数组 A 在轮转 x 个位置后得到长度相同的数组 B ，使得对于每一个有效的下标 i，满足 B[i] == A[(i + x) % A.length]。
//示例 1：
//输入：nums = [3, 4, 5, 1, 2]
//输出：true
//解释：[1, 2, 3, 4, 5] 为有序的源数组。
//可以轮转 x = 2 个位置，使新数组从值为 3 的元素开始：[3, 4, 5, 1, 2] 。
//示例 2：
//输入：nums = [2, 1, 3, 4]
//输出：false
//解释：源数组无法经轮转得到 nums 。
//示例 3：
//输入：nums = [1, 2, 3]
//输出：true
//解释：[1, 2, 3] 为有序的源数组。
//可以轮转 x = 0 个位置（即不轮转）得到 nums 。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

void Count_Sort(int* nums, int len, int* nums_sort) {
	int min = nums[0], max = nums[0];
	for (int i = 0; i < len; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
		else if (nums[i] > max) {
			max = nums[i];
		}
	}
	int* hash = (int*)calloc(max - min + 1, sizeof(int));
	assert(hash);
	for (int i = 0; i < len; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
	}
	int size = 0;
	for (int i = min; i <= max; i++) {
		int key = i - min;
		while (hash[key]) {
			nums_sort[size] = i;
			hash[key] -= 1;
			size += 1;
		}
	}
	free(hash);
	hash = NULL;
}
bool check(int* nums, int numsSize) {
	int* nums_sort = (int*)calloc(numsSize, sizeof(int));
	assert(nums_sort);
	Count_Sort(nums, numsSize, nums_sort);
	int* cmp = (int*)calloc(numsSize * 2, sizeof(int));
	assert(cmp);
	int len = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numsSize; j++) {
			cmp[len] = nums[j];
			len += 1;
		}
	}
	int i = 0, j = 0;
	for (; i < len && j < numsSize;) {
		if (cmp[i] == nums_sort[j]) {
			i += 1;
			j += 1;
		}
		else {
			if (j == 0) {
				i += 1;
			}
			else {
				j = 0;
			}
		}
	}
	bool ans = j == numsSize;
	free(nums_sort);
	nums_sort = NULL;
	free(cmp);
	cmp = NULL;
	return ans;
}