#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
//2026.04.11力扣网刷题
//LCR 147. 最小栈——栈、设计——简单
//请你设计一个 最小栈 。它提供 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//实现 MinStack 类 :
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素。
//示例 1：
//输入：
//["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
//[[], [-2], [0], [-3], [], [], [], []]
//输出：
//[null, null, null, null, -3, null, 0, -2]
//解释：
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 - 3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 - 2.
//提示：
//- 2^31 <= val <= 2^31 - 1
//pop、top 和 getMin 操作总是在 非空栈 上调用
//push、pop、top 和 getMin 最多被调用 3 * 10^4 次
//注意：本题与主站 155 题相同：https://leetcode.cn/problems/min-stack/


#define MAXSIZE 30000



typedef struct {
	int* stack;
	int top;
	int min;
	int maxSize;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* obj = (MinStack*)calloc(1, sizeof(MinStack));
	assert(obj);
	obj->top = -1;
	obj->maxSize = MAXSIZE;
	obj->stack = (int*)calloc(MAXSIZE, sizeof(int));
	assert(obj->stack);
	obj->min = INT_MAX;
	return obj;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top + 1 == obj->maxSize) {
		return;
	}
	obj->top += 1;
	obj->stack[obj->top] = x;
	if (x < obj->min) {
		obj->min = x;
	}
}
void FindMin(MinStack* obj) {
	obj->min = obj->stack[obj->top];
	for (int i = 0; i < obj->top; i++) {
		if (obj->stack[i] < obj->min) {
			obj->min = obj->stack[i];
		}
	}
}
void minStackPop(MinStack* obj) {
	int top = obj->stack[obj->top];
	obj->top -= 1;
	if (obj->top >= 0 && top == obj->min) {
		FindMin(obj);
	}
	else if (obj->top == -1) {
		obj->min = INT_MAX;
	}
}

int minStackTop(MinStack* obj) {
	return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj->stack);
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/