#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2026.10.08力扣网刷题
//1021. 删除最外层的括号——资深工程师、栈、字符串、括号序列、第131场周赛——简单
//有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，其中 A 和 B 都是有效的括号字符串， + 代表字符串的连接。
//例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
//如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。
//给出一个非空有效字符串 s，考虑将其进行原语化分解，使得：s = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。
//对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。
//示例 1：
//输入：s = "(()())(())"
//输出："()()()"
//解释：
//输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
//删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
//示例 2：
//输入：s = "(()())(())(()(()))"
//输出："()()()()(())"
//解释：
//输入字符串为 "(()())(())(()(()))"，原语化分解得到 "(()())" + "(())" + "(()(()))"，
//删除每个部分中的最外层括号后得到 "()()" + "()" + "()(())" = "()()()()(())"。
//示例 3：
//输入：s = "()()"
//输出：""
//解释：
//输入字符串为 "()()"，原语化分解得到 "()" + "()"，
//删除每个部分中的最外层括号后得到 "" + "" = ""。
//提示：
//1 <= s.length <= 10^5
//s[i] 为 '(' 或 ')'
//s 是一个有效括号字符串

char* removeOuterParentheses1(char* s) {
	int len = strlen(s);
	int* stack = (int*)calloc(len, sizeof(int));
	assert(stack);
	bool* del = (bool*)calloc(len, sizeof(bool));
	assert(del);
	for (int i = 0, top = 0; i < len; i++) {
		if (s[i] == '(') {
			if (top == 0) {
				del[i] = true;
			}
			stack[top] = i;
			top += 1;
		}
		else {
			int pi = stack[--top];
			if (del[pi]) {
				del[i] = true;
			}
		}
	}
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	for (int i = 0, j = 0; i < len; i++) {
		if (!del[i]) {
			ans[j++] = s[i];
			ans[j] = 0;
		}
	}
	free(stack);
	free(del);
	return ans;
}

char* removeOuterParentheses(char* s) {
	int len = strlen(s);
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	int depth = 0;
	for (int i = 0, j = 0; i < len; i++) {
		if (s[i] == '(') {
			depth += 1;
			if (depth > 1) {
				ans[j++] = '(';
			}
		}
		else {
			if (depth > 1) {
				ans[j++] = ')';
			}
			depth -= 1;
		}
	}
	return ans;
}