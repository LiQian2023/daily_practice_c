#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.11.17力扣网刷题
//LCR 082. 组合总和 II——数组、回溯——中等
//给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。
//示例 1：
//输入：candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
//输出：
//[
//	[1, 1, 6],
//	[1, 2, 5],
//	[1, 7],
//	[2, 6]
//]
//示例 2：
//输入：candidates = [2, 5, 2, 1, 2], target = 5
//输出：
//[
//	[1, 2, 2],
//	[5]
//]
//提示：
//1 <= candidates.length <= 100
//1 <= candidates[i] <= 50
//1 <= target <= 30
//注意：本题与主站 40 题相同： https ://leetcode.cn/problems/combination-sum-ii/
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
void Realloc(int*** ans, int** col, int* maxSize, bool* flag) {
	int newSize = *maxSize * 3 / 2;
	int** tmp1 = (int**)realloc(*ans, newSize * sizeof(int*));
	if (!tmp1) {
		*flag = false;
		perror("realloc(ans)");
		return;
	}
	*ans = tmp1;
	int* tmp2 = (int*)realloc(*col, newSize * sizeof(int));
	if (!tmp2) {
		*flag = false;
		perror("realloc(col)");
		return;
	}
	*col = tmp2;
	*maxSize = newSize;
}
void backTrack(int* nums, int len, int target, int*** ans, int* row, int** col, int* maxSize, int* stack, int top, int begin, bool* flag, int sum) {
	if (sum == target) {
		if (*row == *maxSize) {
			Realloc(ans, col, maxSize, flag);
		}
		if (*flag) {
			(*col)[*row] = top;
			(*ans)[*row] = (int*)calloc(top, sizeof(int));
			assert((*ans)[*row]);
			memcpy((*ans)[*row], stack, top * sizeof(int));
			*row += 1;
		}
		return;
	}
	for (int i = begin; *flag && i < len; i++) {
		if (i > begin && nums[i] == nums[i - 1]) {
			continue;
		}
		if (sum + nums[i] > target) {
			break;
		}
		stack[top] = nums[i];
		backTrack(nums, len, target, ans, row, col, maxSize, stack, top + 1, i + 1, flag, sum + nums[i]);
	}
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	int maxSize = 4;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = 0;
	int* stack = (int*)calloc(candidatesSize, sizeof(int));
	assert(stack);
	qsort(candidates, candidatesSize, sizeof(int), cmp);
	bool flag = true;
	backTrack(candidates, candidatesSize, target, &ans, returnSize, returnColumnSizes, &maxSize, stack, 0, 0, &flag, 0);
	if (!flag) {
		free(*returnColumnSizes);
		*returnColumnSizes = NULL;
		for (int i = 0; i < *returnSize; i++) {
			if (ans[i]) {
				free(ans[i]);
				ans[i] = NULL;
			}
		}
		free(ans);
		ans = NULL;
		*returnSize = 0;
	}
	free(stack);
	return ans;
}