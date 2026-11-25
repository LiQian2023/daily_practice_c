#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//2026.11.25力扣网刷题
//784. 字母大小写全排列——位运算、字符串、回溯——中等
//给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。
//返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。
//示例 1：
//输入：s = "a1b2"
//输出：["a1b2", "a1B2", "A1b2", "A1B2"]
//示例 2:
//输入: s = "3z4"
//输出 : ["3z4", "3Z4"]
//提示 :
//1 <= s.length <= 12
//s 由小写英文字母、大写英文字母和数字组成
void backTrack(char* s, int len, char* stack, int top, char** ans, int* row) {
	if (top == len) {
		memcpy(ans[*row], stack, top * sizeof(stack[0]));
		*row += 1;
		return;
	}
	// 选小写
	if (isalpha(s[top])) {
		stack[top] = tolower(s[top]);
	}
	else {
		stack[top] = s[top];
	}
	backTrack(s, len, stack, top + 1, ans, row);
	// 选大写
	if (isalpha(s[top])) {
		stack[top] = toupper(s[top]);
		backTrack(s, len, stack, top + 1, ans, row);
	}
}
char** letterCasePermutation(char* s, int* returnSize) {
	int n = 0, len = strlen(s);
	for (int i = 0; s[i]; i++) {
		if (isalpha(s[i])) {
			n += 1;
		}
	}
	int row = 1 << n;
	char** ans = (char**)calloc(row, sizeof(char*));
	assert(ans);
	for (int i = 0; i < row; i++) {
		ans[i] = (char*)calloc(len + 1, sizeof(char));
		assert(ans[i]);
	}
	*returnSize = 0;
	char* stack = (char*)calloc(len + 1, sizeof(char));
	assert(stack);
	backTrack(s, len, stack, 0, ans, returnSize);
	free(stack);
	return ans;
}