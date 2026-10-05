#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.10.05力扣网刷题
//856. 括号的分数——资深工程师、栈、字符串、括号序列、第90场周赛——中等
//给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
//() 得 1 分。
//AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
//(A) 得 2 * A 分，其中 A 是平衡括号字符串。
//示例 1：
//输入： "()"
//输出： 1
//示例 2：
//输入： "(())"
//输出： 2
//示例 3：
//输入： "()()"
//输出： 2
//示例 4：
//输入： "(()(()))"
//输出： 6
//提示：
//S 是平衡括号字符串，且只含有(和) 。
//2 <= S.length <= 50

// 方法一：dp + stack
int scoreOfParentheses1(char* s) {
	int len = strlen(s);
	int* stack = (int*)calloc(len + 1, sizeof(int));
	assert(stack);
	int* dp = (int*)calloc(len + 1, sizeof(int));
	assert(dp);
	int top = 1;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			stack[top] = i + 1;
			top += 1;
		}
		else {
			int A = stack[--top];
			if (dp[A] == 0) {
				dp[stack[top  - 1]] += 1;
			}
			else {
				dp[stack[top - 1]] += 2 * dp[A];
			}
		}
	}
	int ans = dp[0];
	free(stack);
	free(dp);
	return ans;
}

// 方法二：stack
int scoreOfParentheses2(char* s) {
	int len = strlen(s);
	int* stack = (int*)calloc(len + 1, sizeof(int));
	assert(stack);
	int top = 1;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			stack[top] = 0;
			top += 1;
		}
		else {
			int A = stack[--top];
			if (A == 0) {
				stack[top - 1] += 1;
			}
			else {
				stack[top - 1] += 2 * A;
			}
		}
	}
	int ans = stack[0];
	free(stack);
	return ans;
}

// 方法三：字符串遍历
int scoreOfParentheses(char* s) {
	int ans = 0, depth = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			depth += 1;
		}
		else {
			if (s[i - 1] == '(') {
				ans += 1 << (depth - 1);
			}
			depth -= 1;
		}
	}
	return ans;
}