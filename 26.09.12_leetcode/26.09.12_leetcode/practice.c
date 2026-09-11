#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
//2026.09.12力扣网刷题
//46. 全排列——数组、回溯——中等
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
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

void DFS(int* nums, int len, int* stack, int top, bool* visited, int*** ans, int* row, int** col, int* maxSize) {
	if (top == len) {
		if (*row == *maxSize) {
			int newSize = (*maxSize) * 3 / 2;
			int** tmp1 = (int**)realloc((*ans), newSize * sizeof(int*));
			if (!tmp1) {
				perror("realloc");
				return;
			}
			int* tmp2 = (int*)realloc((*col), newSize * sizeof(int));
			if (!tmp2) {
				perror("realloc");
				return;
			}
			*ans = tmp1;
			*col = tmp2;
			*maxSize = newSize;
		}
		(*ans)[*row] = (int*)calloc(top, sizeof(int));
		assert((*ans)[*row]);
		memcpy((*ans)[*row], stack, top * sizeof(int));
		(*col)[*row] = top;
		*row += 1;
		return;
	}
	for (int i = 0; i < len; i++) {
		if (!visited[i]) {
			visited[i] = true;
			stack[top] = nums[i];
			DFS(nums, len, stack, top + 1, visited, ans, row, col, maxSize);
			visited[i] = false;
		}
	}
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int maxSize = 4;
	*returnSize = 0;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	int* stack = (int*)calloc(numsSize, sizeof(int));
	assert(stack);
	bool* visited = (bool*)calloc(numsSize, sizeof(bool));
	assert(visited);
	DFS(nums, numsSize, stack, 0, visited, &ans, returnSize, returnColumnSizes, &maxSize);
	free(stack);
	free(visited);
	return ans;
}