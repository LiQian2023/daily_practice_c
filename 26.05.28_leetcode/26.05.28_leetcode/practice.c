#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2026.05.28力扣网刷题
//1. 两数之和——初级工程师、数组、哈希表——简单
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
//你可以按任意顺序返回答案。
//示例 1：
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[0, 1]
//解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
//示例 2：
//输入：nums = [3, 2, 4], target = 6
//输出：[1, 2]
//示例 3：
//输入：nums = [3, 3], target = 6
//输出：[0, 1]
//提示：
//2 <= nums.length <= 10^4
//- 109 <= nums[i] <= 10^9
//- 109 <= target <= 10^9
//只会存在一个有效答案
//进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Hash {
	int key;
	int val;
	bool used;
}Hash;

int getKey(Hash* h, int len, int num) {
	int key = abs(num % len);
	for (; h[key].used && h[key].key != num; key = (key + 1) % len) {
		;
	}
	return key;
}

void Destroy(Hash** h) {
	free(*h);
	(*h) = NULL;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	Hash* h = (Hash*)calloc(numsSize, sizeof(Hash));
	assert(h);
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	for (int i = 0; i < numsSize; i++) {
		int x = target - nums[i];
		int key = getKey(h, numsSize, x);
		if (h[key].used) {
			ans[0] = h[key].val;
			ans[1] = i;
			break;
		}
		key = getKey(h, numsSize, nums[i]);
		if (h[key].used == false) {
			h[key].key = nums[i];
			h[key].val = i;
			h[key].used = true;
		}
	}
	Destroy(&h);
	return ans;
}