#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.01.13力扣网刷题
//3745. 三元素表达式的最大值——贪心、数组、枚举、排序、第467场周赛——简单
//给你一个整数数组 nums。
//从 nums 中选择三个元素 a、b 和 c，它们的下标需 互不相同 ，使表达式 a + b - c 的值最大化。
//返回该表达式可能的 最大值 。
//示例 1：
//输入： nums = [1, 4, 2, 5]
//输出： 8
//解释：
//可以选择 a = 4，b = 5，c = 1。表达式的值为 4 + 5 - 1 = 8，这是可能的最大值。
//示例 2：
//输入： nums = [-2, 0, 5, -2, 4]
//输出： 11
//解释：
//可以选择 a = 5，b = 4，c = -2。表达式的值为 5 + 4 - (-2) = 11，这是可能的最大值。
//提示：
//3 <= nums.length <= 100
//- 100 <= nums[i] <= 100

void Count_Sort(int* nums, int len, int max, int min) {
	int* hash = (int*)calloc(max - min + 1, sizeof(int));
	assert(hash);
	for (int i = 0; i < len; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
	}
	for (int i = min, j = 0; i <= max && j < len; i++) {
		while (hash[i - min]) {
			nums[j] = i;
			j += 1;
			hash[i - min] -= 1;
		}
	}
	free(hash);
	hash = NULL;
}

// 计数排序
int maximizeExpressionOfThree(int* nums, int numsSize) {
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	Count_Sort(nums, numsSize, max, min);
	return nums[numsSize - 1] + nums[numsSize - 2] - nums[0];
}