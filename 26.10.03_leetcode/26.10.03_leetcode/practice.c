#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.10.03力扣网刷题
//32. 最长有效括号——栈、字符串、动态规划、括号序列——困难
//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号 子串 的长度。
//左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如 "(()())"。
//示例 1：
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
//示例 2：
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
//示例 3：
//输入：s = ""
//输出：0
//提示：
//0 <= s.length <= 3 * 10^4
//s[i] 为 '(' 或 ')'

int longestValidParentheses(char* s) {
	int len = strlen(s);
	if (len == 0) {
		return 0;
	}
	int* stack = (int*)calloc(len, sizeof(int));
	assert(stack);
	int top = 0;
	int ans = 0, boundary = -1;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			stack[top] = i;
			top += 1;
		}
		else {
			if (top) {
				top -= 1;
			}
			else {
				boundary = i;
				continue;
			}
			int tmp = i - boundary;
			if (top) {
				tmp = i - stack[top - 1];
			}
			if (tmp > ans) {
				ans = tmp;
			}
		}
	}
	free(stack);
	return ans;
}
