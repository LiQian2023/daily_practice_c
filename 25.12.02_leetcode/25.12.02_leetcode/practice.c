#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.12.02力扣网刷题
//3452. 好数字之和——数组、第150场双周赛——简单
//给定一个整数数组 nums 和一个整数 k，如果元素 nums[i] 严格 大于下标 i - k 和 i + k 处的元素（如果这些元素存在），则该元素 nums[i] 被认为是 好 的。如果这两个下标都不存在，那么 nums[i] 仍然被认为是 好 的。
//返回数组中所有 好 元素的 和。
//示例 1：
//输入： nums = [1, 3, 2, 1, 5, 4], k = 2
//输出： 12
//解释：
//好的数字包括 nums[1] = 3，nums[4] = 5 和 nums[5] = 4，因为它们严格大于下标 i - k 和 i + k 处的数字。
//示例 2：
//输入： nums = [2, 1], k = 1
//输出： 2
//解释：
//唯一的好数字是 nums[0] = 2，因为它严格大于 nums[1]。
//提示：
//2 <= nums.length <= 100
//1 <= nums[i] <= 1000
//1 <= k <= floor(nums.length / 2)

int sumOfGoodNumbers(int* nums, int numsSize, int k) {
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		bool flag1 = (i - k < 0 && i + k >= numsSize);
		bool flag2 = (i - k >= 0 && nums[i] > nums[i - k] && i + k<numsSize && nums[i]>nums[i + k]);
		bool flag3 = (i - k < 0 && i + k<numsSize && nums[i]>nums[i + k]);
		bool flag4 = (i - k >= 0 && nums[i] > nums[i - k] && i + k >= numsSize);
		if (flag1 || flag2 || flag3 || flag4) {
			ans += nums[i];
		}
	}
	return ans;
}