#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.15力扣网刷题
//面试题 03.02.栈的最小值——栈、设计——简单
//请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。
//示例：
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 - 3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 - 2.




typedef struct {
	int* stack;
	int* mStack;
	int top;
	int mTop;
	int baseSize;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* obj = (MinStack*)calloc(1, sizeof(MinStack));
	assert(obj);
	obj->baseSize = 10;
	obj->stack = (int*)calloc(obj->baseSize, sizeof(int));
	assert(obj->stack);
	obj->mStack = (int*)calloc(obj->baseSize, sizeof(int));
	assert(obj->mStack);
	obj->top = -1;
	obj->mTop = -1;
	return obj;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top + 1 == obj->baseSize) {
		int newSize = obj->baseSize + obj->baseSize / 2;
		int* tmp1 = (int*)realloc(obj->stack, sizeof(int) * newSize);
		assert(tmp1);
		if (!tmp1) {
			perror("realloc(stack)");
			return;
		}
		obj->stack = tmp1;
		int* tmp2 = (int*)realloc(obj->mStack, sizeof(int) * newSize);
		assert(tmp2);
		if (!tmp2) {
			perror("realloc(mStack)");
			return;
		}
		obj->mStack = tmp2;
		obj->baseSize = newSize;
	}
	if (obj->mTop == -1 || x <= obj->mStack[obj->mTop]) {
		obj->mTop += 1;
		obj->mStack[obj->mTop] = x;
	}
	obj->top += 1;
	obj->stack[obj->top] = x;
}

void minStackPop(MinStack* obj) {
	if (obj->stack[obj->top] == obj->mStack[obj->mTop]) {
		obj->mTop -= 1;
	}
	obj->top -= 1;
}

int minStackTop(MinStack* obj) {
	return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
	return obj->mStack[obj->mTop];
}

void minStackFree(MinStack* obj) {
	free(obj->stack);
	obj->stack = NULL;
	free(obj->mStack);
	obj->mStack = NULL;
	free(obj);
	obj = NULL;
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