#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.11.06力扣网刷题
//数组串联——数组、模拟、第249场周赛——简单
//给你一个长度为 n 的整数数组 nums 。请你构建一个长度为 2n 的答案数组 ans ，数组下标 从 0 开始计数 ，对于所有 0 <= i < n 的 i ，满足下述所有要求：
//ans[i] == nums[i]
//ans[i + n] == nums[i]
//具体而言，ans 由两个 nums 数组 串联 形成。
//返回数组 ans 。
//示例 1：
//输入：nums = [1, 2, 1]
//输出：[1, 2, 1, 1, 2, 1]
//解释：数组 ans 按下述方式形成：
//- ans = [nums[0], nums[1], nums[2], nums[0], nums[1], nums[2]]
//- ans = [1, 2, 1, 1, 2, 1]
//示例 2：
//输入：nums = [1, 3, 2, 1]
//输出：[1, 3, 2, 1, 1, 3, 2, 1]
//解释：数组 ans 按下述方式形成：
//- ans = [nums[0], nums[1], nums[2], nums[3], nums[0], nums[1], nums[2], nums[3]]
//- ans = [1, 3, 2, 1, 1, 3, 2, 1]
//提示：
//n == nums.length
//1 <= n <= 1000
//1 <= nums[i] <= 1000

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
	int* ans = (int*)calloc(2 * numsSize, sizeof(int));
	assert(ans);
	*returnSize = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numsSize; j++) {
			ans[*returnSize] = nums[j];
			*returnSize += 1;
		}
	}
	return ans;
}