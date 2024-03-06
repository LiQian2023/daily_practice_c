#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//2024.03.06力扣网刷题
//有效的括号——栈、字符串——简单
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。
//示例 1：
//输入：s = "()"
//输出：true
//示例 2：
//输入：s = "()[]{}"
//输出：true
//示例 3：
//输入：s = "(]"
//输出：false
//提示：
//1 <= s.length <= 10^4
//s 仅由括号 '()[]{}' 组成

typedef struct Stack {
	char data;
	struct Stack* next;
}Stack;

void Push(Stack** S, char val) {
	assert(S);
	Stack* p = (Stack*)calloc(1, sizeof(Stack));
	assert(p);
	p->data = val;
	p->next = *S;
	*S = p;
}

bool Pop(Stack** S, char* val) {
	assert(S);
	if (*S == NULL)
		return false;
	Stack* p = *S;
	*S = (*S)->next;
	*val = p->data;
	free(p);
	return true;
}

bool isValid(char* s) {
	Stack* S = NULL;
	char val = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			Push(&S, s[i]);
		else if (s[i] == ')' && S != NULL && S->data == '(') {
			Pop(S, &val);
		}
		else if (s[i] == ']' && S != NULL && S->data == '[') {
			Pop(S, &val);
		}
		else if (s[i] == '}' && S != NULL && S->data == '{') {
			Pop(S, &val);
		}
		else
			return false;
	}
	if (S != NULL)
		return false;
	return true;
}

bool isValid1(char* s) {
	char S[10001] = { 0 };
	int i = 0;
	for (int j = 0; j < strlen(s); j++) {
		if (s[j] == '(' || s[j] == '[' || s[j] == '{') {
			S[i] = s[j];
			i++;
		}
		else if (s[j] == ')' && i != 0 && S[i - 1] == '(') {
			i--;
			S[i] = 0;
		}
		else if (s[j] == ']' && i != 0 && S[i - 1] == '[') {
			i--;
			S[i] = 0;
		}
		else if (s[j] == '}' && i != 0 && S[i - 1] == '{') {
			i--;
			S[i] = 0;
		}
		else
			return false;
	}
	if (i != 0 || S[i] != 0)
		return false;
	return true;
}

int main() {
	char s[10] = { 0 };
	scanf("%s", s);
	if (isValid1(s))
		printf("true\n");
	else
		printf("false\n");
	return 0;
}