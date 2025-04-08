#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.09力扣网刷题
//使数组的值全部为 K 的最少操作次数——数组、哈希表——简单
//给你一个整数数组 nums 和一个整数 k 。
//如果一个数组中所有 严格大于 h 的整数值都 相等 ，那么我们称整数 h 是 合法的 。
//比方说，如果 nums = [10, 8, 10, 8] ，那么 h = 9 是一个 合法 整数，因为所有满足 nums[i] > 9 的数都等于 10 ，但是 5 不是 合法 整数。
//你可以对 nums 执行以下操作：
//选择一个整数 h ，它对于 当前 nums 中的值是合法的。
//对于每个下标 i ，如果它满足 nums[i] > h ，那么将 nums[i] 变为 h 。
//你的目标是将 nums 中的所有元素都变为 k ，请你返回 最少 操作次数。如果无法将所有元素都变 k ，那么返回 - 1 。
//示例 1：
//输入：nums = [5, 2, 5, 4, 5], k = 2
//输出：2
//解释：
//依次选择合法整数 4 和 2 ，将数组全部变为 2 。
//示例 2：
//输入：nums = [2, 1, 2], k = 2
//输出： - 1
//解释：
//没法将所有值变为 2 。
//示例 3：
//输入：nums = [9, 7, 5, 3], k = 1
//输出：4
//解释：
//依次选择合法整数 7 ，5 ，3 和 1 ，将数组全部变为 1 。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
//1 <= k <= 100

int minOperations(int* nums, int numsSize, int k) {
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
		if (nums[i] < k) {
			return -1;
		}
		int key = nums[i] - min;
		hash[key] += 1;
	}
	int ans = 0;
	for (int i = max; i > k; i--) {
		if (i < min) {
			break;
		}
		int key = i - min;
		if (hash[key]) {
			ans += 1;
		}
	}
	free(hash);
	return ans;
}