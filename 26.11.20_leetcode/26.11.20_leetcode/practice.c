#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2026.11.20力扣网刷题
//LCR 083. 全排列——数组、回溯——中等
//给定一个不含重复数字的整数数组 nums ，返回其 所有可能的全排列 。可以 按任意顺序 返回答案。
//示例 1：
//输入：nums = [1, 2, 3]
//输出： [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
//示例 2：
//输入：nums = [0, 1]
//输出： [[0, 1], [1, 0]]
//示例 3：
//输入：nums = [1]
//输出： [[1]]
//提示：
//1 <= nums.length <= 6
//- 10 <= nums[i] <= 10
//nums 中的所有整数 互不相同
//注意：本题与主站 46 题相同：https://leetcode.cn/problems/permutations/ 
void backTrack(int* nums, int len, int* stack, bool* visited, int top, int** ans, int* row) {
	if (top == len) {
		memcpy(ans[*row], stack, top * sizeof(int));
		*row += 1;
		return;
	}
	for (int i = 0; i < len; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		stack[top] = nums[i];
		backTrack(nums, len, stack, visited, top + 1, ans, row);
		visited[i] = false;
	}
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int size = 1;
	for (int i = 1; i <= numsSize; i++) {
		size *= i;
	}
	int** ans = (int**)calloc(size, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(size, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < size; i++) {
		(*returnColumnSizes)[i] = numsSize;
		ans[i] = (int*)calloc(numsSize, sizeof(int));
		assert(ans[i]);
	}
	*returnSize = 0;
	int* stack = (int*)calloc(numsSize, sizeof(int));
	assert(stack);
	bool* visited = (bool*)calloc(numsSize, sizeof(bool));
	assert(visited);
	backTrack(nums, numsSize, stack, visited, 0, ans, returnSize);
	free(stack);
	stack = NULL;
	free(visited);
	visited = NULL;
	return ans;
}