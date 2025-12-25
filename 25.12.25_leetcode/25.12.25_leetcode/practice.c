#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.12.25力扣网刷题
//3105. 最长的严格递增或递减子数组——数组、第392场周赛——简单
//给你一个整数数组 nums 。
//返回数组 nums 中 严格递增 或 严格递减 的最长非空子数组的长度。
//示例 1：
//输入：nums = [1, 4, 3, 3, 2]
//输出：2
//解释：
//nums 中严格递增的子数组有[1]、[2]、[3]、[3]、[4] 以及[1, 4] 。
//nums 中严格递减的子数组有[1]、[2]、[3]、[3]、[4]、[3, 2] 以及[4, 3] 。
//因此，返回 2 。
//示例 2：
//输入：nums = [3, 3, 3, 3]
//输出：1
//解释：
//nums 中严格递增的子数组有[3]、[3]、[3] 以及[3] 。
//nums 中严格递减的子数组有[3]、[3]、[3] 以及[3] 。
//因此，返回 1 。
//示例 3：
//输入：nums = [3, 2, 1]
//输出：3
//解释：
//nums 中严格递增的子数组有[3]、[2] 以及[1] 。
//nums 中严格递减的子数组有[3]、[2]、[1]、[3, 2]、[2, 1] 以及[3, 2, 1] 。
//因此，返回 3 。
//提示：
//1 <= nums.length <= 50
//1 <= nums[i] <= 50

int longestMonotonicSubarray(int* nums, int numsSize) {
	int ret = 0, flag = 1;
	for (int l = 0, r = 1; r <= numsSize; r += 1) {
		int change = 0;
		if (r < numsSize && flag && nums[r - 1] > nums[r]) {
			flag = 0;
			change = 1;
		}
		else if (r < numsSize && flag == 0 && nums[r - 1] < nums[r]) {
			flag = 1;
			change = 2;
		}
		else if (r < numsSize && nums[r - 1] == nums[r]) {
			change = 3;
		}
		if (r - l > ret) {
			ret = r - l;
		}
		if (change) {
			if (change == 3) {
				l = r;
			}
			else {
				l = r - 1;
			}
		}
	}
	return ret;
}