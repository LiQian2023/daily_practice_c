#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2025.12.08力扣网刷题
//3678. 大于平均值的最小未出现正整数——数组、哈希表、第165场双周赛——简单
//给你一个整数数组 nums。
//返回 nums 中 严格大于 nums 中所有元素 平均值 的 最小未出现正整数。
//数组的 平均值 定义为数组中所有元素的总和除以元素的数量。
//示例 1:
//输入: nums = [3, 5]
//输出 : 6
//解释 :
//nums 的平均值是(3 + 5) / 2 = 8 / 2 = 4 。
//大于 4 的最小未出现正整数是 6。
//示例 2 :
//输入 : nums = [-1, 1, 2]
//输出 : 3
//解释 :
//nums 的平均值是(-1 + 1 + 2) / 3 = 2 / 3 = 0.667 。
//大于 0.667 的最小未出现正整数是 3 。
//示例 3 :
//输入 : nums = [4, -1]
//输出 : 2
//解释 :
//nums 的平均值是(4 + (-1)) / 2 = 3 / 2 = 1.50。
//大于 1.50 的最小未出现正整数是 2。
//提示 :
//1 <= nums.length <= 100
//- 100 <= nums[i] <= 100

int smallestAbsent(int* nums, int numsSize) {
	int max = nums[0], min = nums[0];
	int avrange = 0, ans = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
		avrange += nums[i];
	}
	avrange /= numsSize;
	int* hash = (int*)calloc(202, sizeof(int));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
	}
	for (int i = 1 - min; i < 202; i++) {
		if (i + min > avrange && hash[i] == 0) {
			ans = i + min;
			break;
		}
	}
	free(hash);
	hash = NULL;
	return ans;
}