#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.09.14力扣网刷题
//77. 组合——回溯——中等
//给定两个整数 n 和 k，返回范围[1, n] 中所有可能的 k 个数的组合。
//你可以按 任何顺序 返回答案。
//示例 1：
//输入：n = 4, k = 2
//输出：
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]
//示例 2：
//输入：n = 1, k = 1
//输出： [[1]]
//提示：
//1 <= n <= 20
//1 <= k <= n
void DFS(int n, int k, int* stack, bool* visited, int top, int*** ans, int* row, int** col, int* maxSize, int start) {
	if (top == k) {
		if (*row == *maxSize) {
			int newSize = *maxSize * 3 / 2;
			int** tmp1 = (int**)realloc(*ans, newSize * sizeof(int*));
			if (!tmp1) {
				perror("realloc");
				return;
			}
			*ans = tmp1;
			int* tmp2 = (int*)realloc(*col, newSize * sizeof(int));
			if (!tmp2) {
				perror("realloc");
				return;
			}
			(*col) = tmp2;
			*maxSize = newSize;
		}
		(*col)[*row] = k;
		(*ans)[*row] = (int*)calloc(k, sizeof(int));
		if (!(*ans)[*row]) {
			perror("calloc");
			return;
		}
		memcpy((*ans)[*row], stack, k * sizeof(int));
		*row += 1;
		return;
	}
	for (int i = start; i <= n; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		stack[top] = i;
		DFS(n, k, stack, visited, top + 1, ans, row, col, maxSize, i + 1);
		visited[i] = false;
	}
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
	int* stack = (int*)calloc(k, sizeof(int));
	assert(stack);
	bool* visited = (bool*)calloc(n + 1, sizeof(bool));
	assert(visited);
	int maxSize = 4;
	int** ans = (int**)calloc(maxSize, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(maxSize, sizeof(int));
	assert(*returnColumnSizes);
	*returnSize = 0;
	DFS(n, k, stack, visited, 0, &ans, returnSize, returnColumnSizes, &maxSize, 1);
	free(stack);
	free(visited);
	return ans;
}