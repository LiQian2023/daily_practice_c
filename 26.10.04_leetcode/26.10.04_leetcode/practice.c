#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.10.04力扣网刷题
//678. 有效的括号字符串——栈、贪心、字符串、动态规划、括号序列——中等
//给你一个只包含三种字符的字符串，支持的字符类型分别是 '('、')' 和 '*'。请你检验这个字符串是否为有效字符串，如果是 有效 字符串返回 true 。
//有效 字符串符合如下规则：
//任何左括号 '(' 必须有相应的右括号 ')'。
//任何右括号 ')' 必须有相应的左括号 '(' 。
//左括号 '(' 必须在对应的右括号之前 ')'。
//'*' 可以被视为单个右括号 ')' ，或单个左括号 '(' ，或一个空字符串 ""。
//示例 1：
//输入：s = "()"
//输出：true
//示例 2：
//输入：s = "(*)"
//输出：true
//示例 3：
//输入：s = "(*))"
//输出：true
//提示：
//1 <= s.length <= 100
//s[i] 为 '('、')' 或 '*'

bool checkValidString(char* s) {
	int len = strlen(s);
	int* stack1 = (int*)calloc(len, sizeof(int));
	assert(stack1);
	int* stack2 = (int*)calloc(len, sizeof(int));
	assert(stack2);
	int top = 0, top2 = 0;
	bool ans = true;
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			stack1[top] = i;
			top += 1;
		}
		else {
			if (s[i] == ')') {
				if (top == 0 && top2 == 0) {
					ans = false;
					break;
				}
				else if (top) {
					top -= 1;
				}
				else if (top2) {
					top2 -= 1;
				}
			}
			else {
				stack2[top2] = i;
				top2 += 1;
			}
		}
	}
	if (ans) {
		if (top2 < top) {
			ans = false;
		}
		else {
			int i = 0, j = 0;
			for (; i < top && j < top2; j++) {
				if (stack1[i] < stack2[j]) {
					i++;
				}
			}
			if (i < top) {
				ans = false;
			}
		}
	}
	free(stack1);
	free(stack2);
	return ans;
}