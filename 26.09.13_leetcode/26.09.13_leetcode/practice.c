#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2026.09.13力扣网刷题
//47. 全排列 II——数组、回溯、排序——中等
//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
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
void DFS(int* nums, int len, int* stack, int top, bool* visited, int*** ans, int* row, int** col, int* maxSize) {
	if (top == len) {
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
		(*ans)[*row] = (int*)calloc(len, sizeof(int));
		if ((*ans)[*row] == NULL) {
			perror("calloc");
			return;
		}
		memcpy((*ans)[*row], stack, len * sizeof(int));
		(*col)[*row] = len;
		*row += 1;
		return;
	}
	for (int i = 0; i < len; i++) {
		if (visited[i]) {
			continue;
		}
		if (i > 0 && nums[i] == nums[i - 1]&& !visited[i - 1]) {
			continue;
		}
		visited[i] = true;
		stack[top] = nums[i];
		DFS(nums, len, stack, top + 1, visited, ans, row, col, maxSize);
		visited[i] = false;
	}
}
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int maxSize = 4;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	int* stack = (int*)calloc(numsSize, sizeof(int));
	assert(stack);
	bool* visited = (bool*)calloc(numsSize, sizeof(bool));
	assert(visited);
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = 0;
	DFS(nums, numsSize, stack, 0, visited, &ans, returnSize, returnColumnSizes, &maxSize);
	free(stack);
	free(visited);
	return ans;
}