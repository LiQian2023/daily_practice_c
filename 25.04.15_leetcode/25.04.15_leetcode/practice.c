#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.15力扣网刷题
//数组的度——数组、哈希表——简单
//给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。
//你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
//示例 1：
//输入：nums = [1, 2, 2, 3, 1]
//输出：2
//解释：
//输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
//连续子数组里面拥有相同度的有如下所示：
//[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
//最短连续子数组[2, 2] 的长度为 2 ，所以返回 2 。
//示例 2：
//输入：nums = [1, 2, 2, 3, 1, 4, 2]
//输出：6
//解释：
//数组的度是 3 ，因为元素 2 重复出现 3 次。
//所以[2, 2, 3, 1, 4, 2] 是最短子数组，因此返回 6 。
//提示：
//nums.length 在 1 到 50, 000 范围内。
//nums[i] 是一个在 0 到 49, 999 范围内的整数。


typedef struct Hash {
	int begin;
	int end;
	int num;
}Hash;
int findShortestSubArray(int* nums, int numsSize) {
	int min = nums[0], max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	int size = max - min + 1;
	Hash* hash = (Hash*)calloc(size, sizeof(Hash));
	assert(hash);
	for (int i = 0; i < size; i++) {
		hash[i].begin = -1;
		hash[i].end = 0;
		hash[i].num = 0;
	}
	int ans = numsSize;
	int count = 0;
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		if (hash[key].begin == -1) {
			hash[key].begin = i;
		}
		else {
			hash[key].end = i;
		}
		hash[key].num += 1;
		if (hash[key].num > count) {
			count = hash[key].num;
		}
	}
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		int tmp = hash[key].end - hash[key].begin + 1;
		if (hash[key].num == count && tmp > 0 && tmp < ans) {
			ans = tmp;
		}
	}
	free(hash);
	return ans;
}