#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.01.05力扣网刷题
//3712. 出现次数能被 K 整除的元素总和——数组、哈希表、计数、第471场周赛——简单
//给你一个整数数组 nums 和一个整数 k。
//请返回一个整数，表示 nums 中所有其 出现次数 能被 k 整除的元素的总和；如果没有这样的元素，则返回 0 。
//注意： 若某个元素在数组中的总出现次数能被 k 整除，则它在求和中会被计算 恰好 与其出现次数相同的次数。
//元素 x 的 出现次数 指它在数组中出现的次数。
//示例 1：
//输入： nums = [1, 2, 2, 3, 3, 3, 3, 4], k = 2
//输出： 16
//解释：
//数字 1 出现 1 次（奇数次）。
//数字 2 出现 2 次（偶数次）。
//数字 3 出现 4 次（偶数次）。
//数字 4 出现 1 次（奇数次）。
//因此总和为 2 + 2 + 3 + 3 + 3 + 3 = 16。
//示例 2：
//输入： nums = [1, 2, 3, 4, 5], k = 2
//输出： 0
//解释：
//没有元素出现偶数次，因此总和为 0。
//示例 3：
//输入： nums = [4, 4, 4, 1, 2, 3], k = 3
//输出： 12
//解释：
//数字 1 出现 1 次。
//数字 2 出现 1 次。
//数字 3 出现 1 次。
//数字 4 出现 3 次。
//因此总和为 4 + 4 + 4 = 12。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
//1 <= k <= 100

int sumDivisibleByK(int* nums, int numsSize, int k) {
	int max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
	}
	int* hash = (int*)calloc(max + 1, sizeof(int));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		hash[nums[i]] += 1;
	}
	int ans = 0;
	for (int i = 0; i <= max; i++) {
		if (hash[i] % k == 0) {
			ans += i * hash[i];
		}
	}
	free(hash);
	hash = NULL;
	return ans;
}