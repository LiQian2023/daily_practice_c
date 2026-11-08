#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.11.09力扣网刷题
//LCR 080. 组合——数组、回溯——中等
//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//示例 1：
//输入 : n = 4, k = 2
//输出 :
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]
//示例 2：
//输入 : n = 1, k = 1
//输出 : [[1]]
//提示：
//1 <= n <= 20
//1 <= k <= n
//注意：本题与主站 77 题相同： https ://leetcode.cn/problems/combinations/

int combination(int m, int n) {
	int ans = 1;
	for (int i = n - m + 1, j = 1; i <= n && j <= m;) {
		if (i <= n) {
			ans *= i;
			i += 1;
		}
		if (j <= m) {
			ans /= j;
			j += 1;
		}
	}
	return ans;
}
void dfs(int n, int k, int* stack, int top, int** ans, int* row, int begin) {
	if (top == k) {
		memcpy(ans[*row], stack, top * sizeof(int));
		*row += 1;
		return;
	}
	for (int i = begin; i <= n; i++) {
		stack[top] = i;
		dfs(n, k, stack, top + 1, ans, row, i + 1);
	}
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
	int size = combination(k, n);
	int** ans = (int**)calloc(size, sizeof(int*));
	assert(ans);
	*returnSize = 0;
	*returnColumnSizes = (int*)calloc(size, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < size; i++) {
		ans[i] = (int*)calloc(k, sizeof(int));
		assert(ans[i]);
		(*returnColumnSizes)[i] = k;
	}
	int* stack = (int*)calloc(k, sizeof(int));
	assert(stack);
	dfs(n, k, stack, 0, ans, returnSize, 1);
	free(stack);
	return ans;
}