#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

//2025.07.25力扣网刷题
//括号的最大嵌套深度——栈、字符串、第210场周赛——简单
//给定 有效括号字符串 s，返回 s 的 嵌套深度。嵌套深度是嵌套括号的 最大 数量。
//示例 1：
//输入：s = "(1+(2*3)+((8)/4))+1"
//输出：3
//解释：数字 8 在嵌套的 3 层括号中。
//示例 2：
//输入：s = "(1)+((2))+(((3)))"
//输出：3
//解释：数字 3 在嵌套的 3 层括号中。
//示例 3：
//输入：s = "()(())((()()))"
//输出：3
//提示：
//1 <= s.length <= 100
//s 由数字 0 - 9 和字符 '+'、'-'、'*'、'/'、'('、')' 组成
//题目数据保证括号字符串 s 是 有效的括号字符串

int maxDepth(char* s) {
	int top = 0;
	int max = 0;
	for (int i = 0; s[i]; i++) {
		switch (s[i]) {
		case '(':
			top += 1;
			break;
		case ')':
			top -= 1;
			break;
		default:
			break;
		}
		max = max < top ? top : max;
	}
	return max;
}