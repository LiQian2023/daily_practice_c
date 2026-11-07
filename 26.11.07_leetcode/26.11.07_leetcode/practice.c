#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

//2026.11.07力扣网刷题
//LCR 079. 子集——位运算、数组、回溯——中等
//给定一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
//示例 1：
//输入：nums = [1, 2, 3]
//输出： [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//示例 2：
//输入：nums = [0]
//输出： [[], [0]]
//提示：
//1 <= nums.length <= 10
//- 10 <= nums[i] <= 10
//nums 中的所有元素 互不相同
//注意：本题与主站 78 题相同： https ://leetcode.cn/problems/subsets/

void BackTrack(int* nums, int len, int* stack, int top, int** ans, int* row, int** col, int begin) {
	(*col)[*row] = top;
	if (top > 0) {
		ans[*row] = (int*)calloc(top, sizeof(int));
		assert(ans[*row]);
		memcpy(ans[*row], stack, top * sizeof(stack[0]));
	}
	*row += 1;
	if (top == len) {
		return;
	}
	for (int i = begin; i < len; i++) {
		stack[top] = nums[i];
		BackTrack(nums, len, stack, top + 1, ans, row, col, i + 1);
	}
}
int factorial(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return n * factorial(n - 1);
}
int Permutation(int m, int n) {
	int ans = 1;
	for (int i = n - m + 1; i <= n; i++) {
		ans *= i;
	}
	int d = 1;
	for (int i = 1; i <= m; i++) {
		d *= i;
	}
	return ans / d;
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int size = 0;
	for (int i = 0; i <= numsSize; i++) {
		size += Permutation(i, numsSize);
	}
	int** ans = (int**)calloc(size, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(size, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = 0;
	int* stack = (int*)calloc(numsSize, sizeof(int));
	assert(stack);
	BackTrack(nums, numsSize, stack, 0, ans, returnSize, returnColumnSizes, 0);
	free(stack);
	return ans;
}