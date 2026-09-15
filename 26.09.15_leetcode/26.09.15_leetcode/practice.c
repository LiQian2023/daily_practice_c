#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.09.15力扣网刷题
//78. 子集——位运算、数组、回溯——中等
//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
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
void DFS(int* nums, int len, int* stack, int top, int start, int*** ans, int* row, int** col, int* maxSize) {
	if (*row == *maxSize) {
		int newSize = *maxSize * 3 / 2;
		int** tmp1 = (int**)realloc((*ans), newSize * sizeof(int*));
		if (!tmp1) {
			perror("realloc");
			return;
		}
		*ans = tmp1;
		int* tmp2 = (int*)realloc((*col), newSize * sizeof(int));
		if (!tmp2) {
			perror("realloc");
			return;
		}
		*col = tmp2;
		*maxSize = newSize;
	}
	if (top > 0) {
		(*ans)[*row] = (int*)calloc(top, sizeof(int));
		if (!(*ans)[*row]) {
			perror("calloc");
			return;
		}
		memcpy((*ans)[*row], stack, top * sizeof(int));
	}
	else {
		(*ans)[*row] = NULL;
	}
	(*col)[*row] = top;
	*row += 1;
	for (int i = start; i < len; i++) {
		stack[top] = nums[i];
		DFS(nums, len, stack, top + 1, i + 1, ans, row, col, maxSize);
	}
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int* stack = (int*)calloc(numsSize, sizeof(int));
	assert(stack);
	*returnSize = 0;
	int maxSize = 4;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	DFS(nums, numsSize, stack, 0, 0, &ans, returnSize, returnColumnSizes, &maxSize);
	free(stack);
	return ans;
}