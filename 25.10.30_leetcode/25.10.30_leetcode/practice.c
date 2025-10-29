#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.10.30力扣网刷题
//最大升序子数组和——数组、第233场周赛——简单
//给你一个正整数组成的数组 nums ，返回 nums 中一个 严格递增子数组 的最大可能元素和。
//子数组是数组中的一个连续数字序列。
//示例 1：
//输入：nums = [10, 20, 30, 5, 10, 50]
//输出：65
//解释：[5, 10, 50] 是元素和最大的升序子数组，最大元素和为 65 。
//示例 2：
//输入：nums = [10, 20, 30, 40, 50]
//输出：150
//解释：[10, 20, 30, 40, 50] 是元素和最大的升序子数组，最大元素和为 150 。
//示例 3：
//输入：nums = [12, 17, 15, 13, 10, 11, 12]
//输出：33
//解释：[10, 11, 12] 是元素和最大的升序子数组，最大元素和为 33 。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

int maxAscendingSum(int* nums, int numsSize) {
	int ans = nums[0], tmp = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] > nums[i - 1]) {
			tmp += nums[i];
		}
		if (ans < tmp) {
			ans = tmp;
		}
		if (nums[i] <= nums[i - 1]) {
			tmp = nums[i];
		}
	}
	return ans;
}