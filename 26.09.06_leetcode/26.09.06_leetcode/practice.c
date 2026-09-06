#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.09.06力扣网刷题
//22. 括号生成——字符串、动态规划、回溯、括号序列——中等
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//示例 1：
//输入：n = 3
//输出：["((()))", "(()())", "(())()", "()(())", "()()()"]
//示例 2：
//输入：n = 1
//输出：["()"]
//提示：
//1 <= n <= 8
void DFS(char* stack, int* top,int n, int col, char*** ans, int* row, int left, int right,int* maxSize) {
	if (*top == col - 1) {
		if (*row == *maxSize) {
			int newSize = (*maxSize) * 3 / 2;
			char** tmp = (char**)realloc(*ans, newSize * sizeof(**ans));
			if (!tmp) {
				perror("realloc");
				return;
			}
			*ans = tmp;
			*maxSize = newSize;
		}
		(*ans)[*row] = (char*)calloc(col, sizeof(char));
		assert((*ans)[*row]);
		strncpy((*ans)[*row], stack, col);
		*row += 1;
		return;
	}
	if (left < n) {
		stack[*top] = '(';
		*top += 1;
		DFS(stack, top, n, col, ans, row, left + 1, right, maxSize);
		*top -= 1;
	}
	if (right < left) {
		stack[*top] = ')';
		*top += 1;
		DFS(stack, top, n, col, ans, row, left, right + 1, maxSize);
		*top -= 1;
	}
}
char** generateParenthesis(int n, int* returnSize) {
	int maxSize = 4;
	char** ans = (char**)calloc(maxSize, sizeof(char*));
	assert(ans);
	int col = 2 * n + 1;
	char* stack = (char*)calloc(col, sizeof(char));
	assert(stack);
	*returnSize = 0;
	int top = 0, left = 0, right = 0;
	DFS(stack, &top, n, col, &ans, returnSize, left, right, &maxSize);
	free(stack);
	return ans;
}