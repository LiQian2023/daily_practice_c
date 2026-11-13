#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2026.11.13力扣网刷题
//LCR 081. 组合总和——数组、回溯——中等
//给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。
//candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是不同的。
//对于给定的输入，保证和为 target 的唯一组合数少于 150 个。
//示例 1：
//输入 : candidates = [2, 3, 6, 7], target = 7
//输出 : [[7], [2, 2, 3]]
//示例 2：
//输入 : candidates = [2, 3, 5], target = 8
//输出 : [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
//示例 3：
//输入 : candidates = [2], target = 1
//输出 : []
//示例 4：
//输入 : candidates = [1], target = 1
//输出 : [[1]]
//示例 5：
//输入 : candidates = [1], target = 2
//输出 : [[1, 1]]
//提示：
//1 <= candidates.length <= 30
//1 <= candidates[i] <= 200
//candidate 中的每个元素都是独一无二的。
//1 <= target <= 500
//注意：本题与主站 39 题相同： https ://leetcode.cn/problems/combination-sum/
bool Realloc(int*** ans, int* maxSize, int**col) {
	int newSize = *maxSize * 3 / 2;
	int** tmp = (int**)realloc(*ans, newSize * sizeof(int*));
	if (!tmp) {
		perror("realloc(ans)");
		return false;
	}
	*ans = tmp;
	int* tmp2 = (int*)realloc(*col, newSize * sizeof(int));
	if (!tmp2) {
		perror("realloc(col)");
		return false;
	}
	*col = tmp2;
	*maxSize = newSize;
	return true;
}

void backtrack(int* nums, int len, int target, int* stack, int top, int*** ans, int* row, int** col, int* maxSize, int begin, bool* flag) {
	if (stack[0] == target) {
		if (*row == *maxSize) {
			*flag = Realloc(ans, maxSize, col);
		}
		if (*flag) {
			(*ans)[*row] = (int*)calloc(top, sizeof(int));
			assert((*ans)[*row]);
			memcpy((*ans)[*row], stack + 1, top * sizeof(int));
			(*col)[*row] = top;
			*row += 1;
		}
		return;
	}
	if (stack[0] > target) {
		return;
	}
	for (int i = begin; i < len && *flag; i++) {
		stack[top + 1] = nums[i];
		stack[0] += nums[i];
		backtrack(nums, len, target, stack, top + 1, ans, row, col, maxSize, i, flag);
		stack[0] -= nums[i];
	}
}
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	qsort(candidates, candidatesSize, sizeof(int), cmp);
	int* stack = (int*)calloc(target + 1, sizeof(int));
	assert(stack);
	int maxSize = 4;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	*returnSize = 0;
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	bool flag = true;
	backtrack(candidates, candidatesSize, target, stack, 0, &ans, returnSize, returnColumnSizes, &maxSize, 0, &flag);
	free(stack);
	if (!flag) {
		for (int i = 0; i < *returnSize; i++) {
			free(ans[i]);
			ans[i] = NULL;
		}
		free(ans);
		ans = NULL;
		free(*returnColumnSizes);
		*returnColumnSizes = NULL;
		*returnSize = 0;
	}
	return ans;
}