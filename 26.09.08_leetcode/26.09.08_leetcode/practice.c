#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//2026.09.08力扣网刷题
//40. 组合总和 II——数组、回溯——中等
//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的每个数字在每个组合中只能使用 一次 。
//注意：解集不能包含重复的组合。
//示例 1:
//输入: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
//输出 :
//[
//	[1, 1, 6],
//	[1, 2, 5],
//	[1, 7],
//	[2, 6]
//]
//示例 2:
//输入: candidates = [2, 5, 2, 1, 2], target = 5,
//输出 :
//[
//	[1, 2, 2],
//	[5]
//]
//提示 :
//1 <= candidates.length <= 100
//1 <= candidates[i] <= 50
//1 <= target <= 30
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
void DFS(int* nums, int len, int* stack, int top, int*** ans, int* row,int** col, int* maxSize, int start, int sum, int target) {
	if (sum == target) {
		if (*row == *maxSize) {
			int newSize = *maxSize * 3 / 2;
			int** tmp1 = (int**)realloc((*ans), newSize * sizeof(int*));
			if (!tmp1) {
				perror("realloc");
				return;
			}
			(*ans) = tmp1;
			int* tmp2 = (int*)realloc(*col, newSize * sizeof(int));
			if (!tmp2) {
				perror("realloc");
				return;
			}
			(*col) = tmp2;
			*maxSize = newSize;
		}
		(*ans)[*row] = (int*)calloc(top, sizeof(int));
		assert((*ans)[*row]);
		memcpy((*ans)[*row], stack, top * sizeof(int));
		(*col)[*row] = top;
		*row += 1;
		return;
	}
	for (int i = start; i < len; i++) {
		if (sum + nums[i] > target) {
			break;
		}
		if (i > start && nums[i] == nums[i - 1]) {
			continue;
		}
		stack[top] = nums[i];
		DFS(nums, len, stack, top + 1, ans, row, col, maxSize, i + 1, sum + nums[i], target);
	}
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	qsort(candidates, candidatesSize, sizeof(int), cmp);
	int* stack = (int*)calloc(100, sizeof(int));
	assert(stack);
	int maxSize = 4;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	*returnSize = 0;
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	DFS(candidates, candidatesSize, stack, 0, &ans, returnSize, returnColumnSizes, &maxSize, 0, 0, target);
	free(stack);
	return ans;
}