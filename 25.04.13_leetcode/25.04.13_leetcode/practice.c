#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.13力扣网刷题
//在长度 2N 的数组中找出重复 N 次的元素——数组、哈希表——简单
//给你一个整数数组 nums ，该数组具有以下属性：
//nums.length == 2 * n.
//nums 包含 n + 1 个 不同的 元素
//nums 中恰有一个元素重复 n 次
//找出并返回重复了 n 次的那个元素。
//示例 1：
//输入：nums = [1, 2, 3, 3]
//输出：3
//示例 2：
//输入：nums = [2, 1, 2, 5, 3, 2]
//输出：2
//示例 3：
//输入：nums = [5, 1, 5, 2, 5, 3, 5, 4]
//输出：5
//提示：
//2 <= n <= 5000
//nums.length == 2 * n
//0 <= nums[i] <= 10^4
//nums 由 n + 1 个 不同的 元素组成，且其中一个元素恰好重复 n 次

int repeatedNTimes(int* nums, int numsSize) {
	int tag = numsSize / 2;
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	int size = max - min + 1;
	int* hash = (int*)calloc(size, sizeof(int));
	assert(hash);
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
		if (hash[key] >= tag) {
			ans = nums[i];
			break;
		}
	}
	return ans;
}