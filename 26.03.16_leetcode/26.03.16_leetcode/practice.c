#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.03.16力扣网刷题
//3754. 连接非零数字并乘以其数字和 I——中级工程师、数学、第477场周赛——简单
//给你一个整数 n。
//将 n 中所有的 非零数字 按照它们的原始顺序连接起来，形成一个新的整数 x。如果不存在 非零数字 ，则 x = 0。
//sum 为 x 中所有数字的 数字和 。
//返回一个整数，表示 x * sum 的值。
//示例 1：
//输入： n = 10203004
//输出： 12340
//解释：
//非零数字是 1、2、3 和 4。因此，x = 1234。
//数字和为 sum = 1 + 2 + 3 + 4 = 10。
//因此，答案是 x * sum = 1234 * 10 = 12340。
//示例 2：
//输入： n = 1000
//输出： 1
//解释：
//非零数字是 1，因此 x = 1 且 sum = 1。
//因此，答案是 x * sum = 1 * 1 = 1。
//提示：
//0 <= n <= 10^9

typedef struct Stack {
	int* stack;
	int top;
}Stack;
Stack* CreateStack() {
	Stack* s = (Stack*)calloc(1, sizeof(Stack));
	assert(s);
	s->stack = (int*)calloc(10, sizeof(s->stack));
	assert(s->stack);
	s->top = -1;
	return s;
}
void Push(Stack* s, int x) {
	s->stack[++(s->top)] = x;
}
int Pop(Stack* s) {
	int x = s->stack[s->top];
	s->top -= 1;
	return x;
}
bool isEmpty(Stack* s) {
	return s->top == -1;
}
void Free(Stack** s) {
	free((*s)->stack);
	(*s)->stack = NULL;
	free(*s);
	*s = NULL;
}

long long sumAndMultiply(int n) {
	Stack* s = CreateStack();
	while (n) {
		int x = n % 10;
		if (x) {
			Push(s, x);
		}
		n /= 10;
	}
	long long sum = 0, x = 0;
	while (!isEmpty(s)) {
		int top = Pop(s);
		sum += top;
		x *= 10;
		x += top;
	}
	Free(&s);
	return sum * x;
}