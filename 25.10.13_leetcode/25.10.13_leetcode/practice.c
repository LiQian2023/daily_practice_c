#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2025.10.13力扣网刷题
//是否所有 1 都至少相隔 k 个元素——数组、第187场周赛——简单
//给你一个由若干 0 和 1 组成的数组 nums 以及整数 k。如果所有 1 都至少相隔 k 个元素，则返回 true ；否则，返回 false 。
//示例 1：
//输入：nums = [1, 0, 0, 0, 1, 0, 0, 1], k = 2
//输出：true
//解释：每个 1 都至少相隔 2 个元素。
//示例 2：
//输入：nums = [1, 0, 0, 1, 0, 1], k = 2
//输出：false
//解释：第二个 1 和第三个 1 之间只隔了 1 个元素。
//提示：
//1 <= nums.length <= 10^5
//0 <= k <= nums.length
//nums[i] 的值为 0 或 1

bool kLengthApart(int* nums, int numsSize, int k) {
	int gap = 0, one = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i]) {
			if (one >= 1 && gap < k) {
				return false;
			}
			one += 1;
			gap = 0;
		}
		else {
			gap += 1;
		}
	}
	return true;
}