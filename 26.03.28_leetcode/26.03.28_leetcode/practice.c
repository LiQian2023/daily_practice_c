#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.28力扣网刷题
//3866. 找到第一个唯一偶数——中级工程师、数组、哈希表、计数、第178场双周赛——简单
//给你一个整数数组 nums。
//请你返回一个整数，表示 nums 中出现 恰好 一次的第一个 偶数（以数组下标最早为准）。
//如果不存在这样的整数，返回 - 1。
//如果一个整数 x 能被 2 整除，那么它就被认为是 偶数。
//示例 1：
//输入： nums = [3, 4, 2, 5, 4, 6]
//输出： 2
//解释：
//2 和 6 都是偶数，并且它们都恰好出现一次。因为 2 在数组中出现得更早，所以答案是 2。
//示例 2：
//输入： nums = [4, 4]
//输出： - 1
//解释：
//没有恰好出现一次的偶数，所以返回 - 1。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

int firstUniqueEven(int* nums, int numsSize) {
	int hash[101] = { 0 };
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 2 == 0) {
			hash[nums[i]] += 1;
		}
	}
	int ans = -1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 2 == 0 && hash[nums[i]] == 1) {
			ans = nums[i];
			break;
		}
	}
	return ans;
}