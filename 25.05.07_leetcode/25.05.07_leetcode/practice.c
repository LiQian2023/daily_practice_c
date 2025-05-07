#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.07力扣网刷题
//收集元素的最少操作次数——位运算、数组、哈希表——简单
//给你一个正整数数组 nums 和一个整数 k 。
//一次操作中，你可以将数组的最后一个元素删除，将该元素添加到一个集合中。
//请你返回收集元素 1, 2, ..., k 需要的 最少操作次数 。
//示例 1：
//输入：nums = [3, 1, 5, 4, 2], k = 2
//输出：4
//解释：4 次操作后，集合中的元素依次添加了 2 ，4 ，5 和 1 。此时集合中包含元素 1 和 2 ，所以答案为 4 。
//示例 2：
//输入：nums = [3, 1, 5, 4, 2], k = 5
//输出：5
//解释：5 次操作后，集合中的元素依次添加了 2 ，4 ，5 ，1 和 3 。此时集合中包含元素 1 到 5 ，所以答案为 5 。
//示例 3：
//输入：nums = [3, 2, 5, 3, 1], k = 3
//输出：4
//解释：4 次操作后，集合中的元素依次添加了 1 ，3 ，5 和 2 。此时集合中包含元素 1 到 3  ，所以答案为 4 。
//提示：
//1 <= nums.length <= 50
//1 <= nums[i] <= nums.length
//1 <= k <= nums.length
//输入保证你可以收集到元素 1, 2, ..., k 。

int minOperations(int* nums, int numsSize, int k) {
	int hash[51] = { 0 };
	for (int i = 0; i < numsSize; i++) {
		hash[nums[i]] = i;
	}
	int begin = hash[1], end = hash[1];
	for (int i = 1; i <= k; i++) {
		if (hash[i] < begin) {
			begin = hash[i];
		}
		else if (hash[i] > end) {
			end = hash[i];
		}
	}
	if (end < numsSize - 1) {
		end = numsSize - 1;
	}
	return end - begin + 1;
}