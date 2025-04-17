#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.18力扣网刷题
//差的绝对值为 K 的数对数目——数组、哈希表、计数——简单
//给你一个整数数组 nums 和一个整数 k ，请你返回数对(i, j) 的数目，满足 i < j 且 | nums[i] - nums[j]| == k 。
//| x | 的值定义为：
//如果 x >= 0 ，那么值为 x 。
//如果 x < 0 ，那么值为 - x 。
//示例 1：
//输入：nums = [1, 2, 2, 1], k = 1
//输出：4
//解释：差的绝对值为 1 的数对为：
//- [1, 2, 2, 1]
//- [1, 2, 2, 1]
//- [1, 2, 2, 1]
//- [1, 2, 2, 1]
//示例 2：
//输入：nums = [1, 3], k = 3
//输出：0
//解释：没有任何数对差的绝对值为 3 。
//示例 3：
//输入：nums = [3, 2, 1, 5, 4], k = 2
//输出：3
//解释：差的绝对值为 2 的数对为：
//- [3, 2, 1, 5, 4]
//- [3, 2, 1, 5, 4]
//- [3, 2, 1, 5, 4]
//提示：
//1 <= nums.length <= 200
//1 <= nums[i] <= 100
//1 <= k <= 99

int countKDifference(int* nums, int numsSize, int k) {
	int max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	int size = max + 1;
	int* hash = (int*)calloc(size, sizeof(int));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i];
		hash[key] += 1;
	}
	int ans = 0;
	for (int i = 0; i < size - k; i++) {
		int key1 = i, key2 = i + k;
		ans += hash[key1] * hash[key2];
	}
	free(hash);
	return ans;
}