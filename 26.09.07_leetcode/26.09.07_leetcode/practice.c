#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//2026.09.07力扣网刷题
//39. 组合总和——数组、回溯——中等
//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
//对于给定的输入，保证和为 target 的不同组合数少于 150 个。
//示例 1：
//输入：candidates = [2, 3, 6, 7], target = 7
//输出： [[2, 2, 3], [7]]
//解释：
//2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
//7 也是一个候选， 7 = 7 。
//仅有这两种组合。
//示例 2：
//输入 : candidates = [2, 3, 5], target = 8
//输出 : [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
//示例 3：
//输入 : candidates = [2], target = 1
//输出 : []
//提示：
//1 <= candidates.length <= 30
//2 <= candidates[i] <= 40
//candidates 的所有元素 互不相同
//1 <= target <= 40
void DFS(int* nums, int len, int target, int*** ans, int* row, int** col, int* stack, int top, int sum,int* maxSize, int start) {
	if (sum == target) {
		if (*row == *maxSize) {
			int newSize = (*maxSize) * 3 / 2;
			int** tmp1 = (int**)realloc((*ans), newSize * sizeof(int*));
			if (!tmp1) {
				perror("realloc");
				return;
			}
			(*ans) = tmp1;
			int* tmp2 = (int*)realloc((*col), newSize * sizeof(int));
			if (!tmp2) {
				perror("realloc");
				return;
			}
			(*col) = tmp2;
			*maxSize = newSize;
		}
		(*col)[*row] = top;
		(*ans)[*row] = (int*)calloc(top, sizeof(int));
		assert((*ans)[*row]);
		memcpy((*ans)[*row], stack, top * sizeof(int));
		*row += 1;
		return;
	}
	for (int i = start; i < len; i++) {
		if (sum + nums[i] <= target) {
			stack[top] = nums[i];
			DFS(nums, len, target, ans, row, col, stack, top + 1, sum + nums[i], maxSize, i);
		}
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
	int maxSize = 4;
	*returnSize = 0;
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	int* stack = (int*)calloc(21, sizeof(int));
	assert(stack);
	DFS(candidates, candidatesSize, target, &ans, returnSize, returnColumnSizes, stack, 0, 0, &maxSize, 0);
	free(stack);
	return ans;
}