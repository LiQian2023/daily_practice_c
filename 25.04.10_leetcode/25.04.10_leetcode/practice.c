#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.10力扣网刷题
//唯一元素的和——数组、哈希表、计数——简单
//给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。
//请你返回 nums 中唯一元素的 和 。
//示例 1：
//输入：nums = [1, 2, 3, 2]
//输出：4
//解释：唯一元素为[1, 3] ，和为 4 。
//示例 2：
//输入：nums = [1, 1, 1, 1, 1]
//输出：0
//解释：没有唯一元素，和为 0 。
//示例 3 ：
//输入：nums = [1, 2, 3, 4, 5]
//输出：15
//解释：唯一元素为[1, 2, 3, 4, 5] ，和为 15 。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

int sumOfUnique(int* nums, int numsSize) {
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
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
	}
	int ans = 0;
	for (int i = 0; i < size; i++) {
		if (hash[i] == 1) {
			ans += i + min;
		}
	}
	free(hash);
	return ans;
}