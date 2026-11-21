#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.11.21力扣网刷题
//LCR 084. 全排列 II——数组、回溯——中等
//给定一个可包含重复数字的整数集合 nums ，按任意顺序 返回它所有不重复的全排列。
//示例 1：
//输入：nums = [1, 1, 2]
//输出：
//[[1, 1, 2],
//[1, 2, 1],
//[2, 1, 1]]
//示例 2：
//输入：nums = [1, 2, 3]
//输出： [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
//提示：
//1 <= nums.length <= 8
//- 10 <= nums[i] <= 10
//注意：本题与主站 47 题相同： https ://leetcode.cn/problems/permutations-ii/
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
void backTrack(int* nums, int len, int* stack, bool* visited, int top, int** ans, int* row) {
	if (top == len) {
		memcpy(ans[*row], stack, top * sizeof(int));
		*row += 1;
		return;
	}
	for (int i = 0; i < len; i++) {
		if (visited[i] || (i > 0 && nums[i - 1] == nums[i] && visited[i - 1] == false)) {
			continue;
		}
		visited[i] = true;
		stack[top] = nums[i];
		backTrack(nums, len, stack, visited, top + 1, ans, row);
		visited[i] = false;
	}
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int size = 1;
	for (int i = 1; i <= numsSize; i++) {
		size *= i;
	}
	int** ans = (int**)calloc(size, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(size, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < size; i++) {
		ans[i] = (int*)calloc(numsSize, sizeof(int));
		assert(ans[i]);
		(*returnColumnSizes)[i] = numsSize;
	}
	*returnSize = 0;
	int* stack = (int*)calloc(numsSize, sizeof(int));
	assert(stack);
	for (int i = 0; i < numsSize; i++) {
		stack[i] = 11;
	}
	bool* visited = (bool*)calloc(numsSize, sizeof(bool));
	assert(visited);
	qsort(nums, numsSize, sizeof(int), cmp);
	backTrack(nums, numsSize, stack, visited, 0, ans, returnSize);
	free(stack);
	free(visited);
	return ans;
}