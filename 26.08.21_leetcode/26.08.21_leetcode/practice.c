#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//2026.08.21力扣网刷题
//17. 电话号码的字母组合——哈希表、字符串、回溯——中等
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//示例 1：
//输入：digits = "23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//示例 2：
//输入：digits = "2"
//输出：["a", "b", "c"]
//提示：
//1 <= digits.length <= 4
//digits[i] 是范围['2', '9'] 的一个数字。
int maxSize = 4;
void Realloc(char*** ans, int* row, int size) {
	int newSize = maxSize * 3 / 2;
	char** tmp = (char**)calloc(newSize, sizeof(char*));
	if (!tmp) {
		perror("calloc");
		return;
	}
	for (int i = 0; i < newSize; i++) {
		tmp[i] = (char*)calloc(size + 1, sizeof(char));
		assert(tmp[i]);
	}
	for (int i = 0; i < *row; i++) {
		for (int j = 0; j < size + 1; j++) {
			tmp[i][j] = (*ans)[i][j];
		}
		free((*ans)[i]);
		(*ans)[i] = NULL;
	}
	free(*ans);
	*ans = tmp;
	maxSize = newSize;
}
void DFS(char** hash, char*** ans, int* row, char* stack, int* top,char* digits, int size) {
	if (digits[*top] == 0) {
		
		memcpy((*ans)[*row], stack, *top);
		*row += 1;
		if (*row == maxSize) {
			Realloc(ans, row, size);
		}
		return;
	}
	int key = digits[*top] - '0';
	int len = strlen(hash[key]);
	for (int i = 0; i < len; i++) {
		stack[*top] = hash[key][i];
		*top += 1;
		DFS(hash, ans, row, stack, top, digits, size);
		*top -= 1;
	}
}
char** letterCombinations(char* digits, int* returnSize) {
	char* hash[10] = { "", "", "abc", "def", "ghi","jkl","mno", "pqrs","tuv","wxyz" };
	char* stack = (char*)calloc(5, sizeof(char));
	assert(stack);
	int top = 0;
	int col = strlen(digits);
	char** ans = (char**)calloc(maxSize, sizeof(char*));
	assert(ans);
	for (int i = 0; i < maxSize; i++) {
		ans[i] = (char*)calloc(col + 1, sizeof(char));
		assert(ans[i]);
	}
	int row = 0;
	DFS(hash, &ans, &row, stack, &top, digits, col);
	*returnSize = row;
	return ans;
}