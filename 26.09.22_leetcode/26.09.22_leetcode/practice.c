#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.09.22力扣网刷题
//90. 子集 II——位运算、数组、回溯——中等
//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
//解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//示例 1：
//输入：nums = [1, 2, 2]
//输出： [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
//示例 2：
//输入：nums = [0]
//输出： [[], [0]]
//提示：
//1 <= nums.length <= 10
//- 10 <= nums[i] <= 10
void getLimit(int* nums, int len, int* max, int* min) {
	for (int i = 0; i < len; i++) {
		if (nums[i] > *max) {
			*max = nums[i];
		}
		else if (nums[i] < *min) {
			*min = nums[i];
		}
	}
}
void CountSort(int* nums, int len, int max, int min) {
	int hash[21] = { 0 };
	for (int i = 0; i < len; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
	}
	for (int i = 0, j = 0; i <= max - min; i++) {
		while (hash[i]) {
			nums[j] = i + min;
			hash[i] -= 1;
			j += 1;
		}
	}
}
void DFS(int* nums, int len, int* stack, int top, int start, int** ans, int* row, int** col) {
	if (top) {
		ans[*row] = (int*)calloc(top, sizeof(int));
		assert(ans[*row]);
		memcpy(ans[*row], stack, top * sizeof(int));
	}
	else {
		ans[*row] = NULL;
	}
	(*col)[*row] = top;
	*row += 1;
	for (int i = start; i < len; i++) {
		if (i > start && nums[i] == nums[i - 1]) {
			continue;
		}
		stack[top] = nums[i];
		DFS(nums, len, stack, top + 1, i + 1, ans, row, col);
	}
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int max = nums[0], min = nums[0];
	getLimit(nums, numsSize, &max, &min);
	CountSort(nums, numsSize, max, min);
	int* stack = (int*)calloc(numsSize, sizeof(int));
	assert(stack);
	int maxSize = 1 << numsSize;
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = 0;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	DFS(nums, numsSize, stack, 0, 0, ans, returnSize, returnColumnSizes);
	free(stack);
	return ans;
}