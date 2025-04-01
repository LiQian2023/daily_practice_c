#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
//2025.04.01力扣网刷题
//比较含退格的字符串——栈、双指针、字符串、模拟——简单
//给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
//注意：如果对空文本输入退格字符，文本继续为空。
//示例 1：
//输入：s = "ab#c", t = "ad#c"
//输出：true
//解释：s 和 t 都会变成 "ac"。
//示例 2：
//输入：s = "ab##", t = "c#d#"
//输出：true
//解释：s 和 t 都会变成 ""。
//示例 3：
//输入：s = "a#c", t = "b"
//输出：false
//解释：s 会变成 "c"，但 t 仍然是 "b"。
//提示：
//1 <= s.length, t.length <= 200
//s 和 t 只含有小写字母以及字符 '#'
//进阶：
//你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？

void Push(char* stack1, char* str, int len, int* top) {
	for (int i = 0; i < len; i++) {
		if (str[i] == '#') {
			if (*top)
				*top -= 1;
		}
		else {
			stack1[*top] = str[i];
			*top += 1;
		}
	}
}
bool backspaceCompare1(char* s, char* t) {
	int len1 = strlen(s);
	char* stack1 = (char*)calloc(len1, sizeof(char));
	assert(stack1);
	int top1 = 0;
	Push(stack1, s, len1, &top1);
	int len2 = strlen(t);
	char* stack2 = (char*)calloc(len2, sizeof(char));
	assert(stack2);
	int top2 = 0;
	Push(stack2, t, len2, &top2);
	bool flag = false;
	if (top1 == top2) {
		flag = strncmp(stack1, stack2, top1) == 0;
	}
	free(stack1);
	free(stack2);
	return flag;
}

void Delete(char* str, int* del, int* pi) {
	while (*pi >= 0 && str[*pi] == '#') {
		*del += 1;
		*pi -= 1;
	}
	while (*pi >= 0 && *del) {
		if (str[*pi] == '#') {
			*del += 1;
		}
		else {
			*del -= 1;
		}
		*pi -= 1;
	}
}
bool backspaceCompare(char* s, char* t) {
	int len1 = strlen(s);
	int len2 = strlen(t);
	int del_s = 0;
	int del_t = 0;
	for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0;) {
		Delete(s, &del_s, &i);
		Delete(t, &del_t, &j);
		if (i < 0 && j < 0) {
			break;
		}
		else if (i < 0 && j >= 0 || i >= 0 && j < 0) {
			if (i >= 0 && s[i] == '#' || j >= 0 && t[j] == '#') {
				continue;
			}
			else {
				return false;
			}
		}
		else {
			if (s[i] == '#' || t[j] == '#') {
				continue;
			}
			//字符元素不相等
			if (s[i] != t[j]) {
				return false;
			}
			i -= 1, j -= 1;
		}
	}
	return true;
}