#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2026.05.16力扣网刷题
//面试题 03.04.化栈为队——栈、设计、队列——简单
//实现一个MyQueue类，该类用两个栈来实现一个队列。
//示例：
//MyQueue queue = new MyQueue();
//queue.push(1);
//queue.push(2);
//queue.peek();  // 返回 1
//queue.pop();   // 返回 1
//queue.empty(); // 返回 false
//说明：
//你只能使用标准的栈操作 -- 也就是只有 push to top, peek / pop from top, size 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。




typedef struct {
	int* pushStack;
	int* popStack;
	int pushTop;
	int popTop;
	int baseSize;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)calloc(1, sizeof(MyQueue));
	assert(obj);
	obj->baseSize = 10;
	obj->popStack = (int*)calloc(obj->baseSize, sizeof(int));
	assert(obj->popStack);
	obj->pushStack = (int*)calloc(obj->baseSize, sizeof(int));
	assert(obj->pushStack);
	obj->popTop = -1;
	obj->pushTop = -1;
	return obj;
}

void Realloc(int** stack, int size) {
	int* tmp = (int*)realloc(*stack, size * sizeof(int));
	assert(tmp);
	if (!tmp) {
		perror("realloc()");
		return;
	}
	*stack = tmp;
}
void Transform(int* stack1, int* stack2, int* top1, int* top2) {
	while (*top1 != -1) {
		*top2 += 1;
		stack2[*top2] = stack1[*top1];
		*top1 -= 1;
	}
}
/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	Transform(obj->popStack, obj->pushStack, &obj->popTop, &obj->pushTop);
	obj->pushTop += 1;
	if (obj->pushTop == obj->baseSize) {
		int newSize = obj->baseSize * 3 / 2;
		Realloc(&(obj->pushStack), newSize);
		Realloc(&(obj->popStack), newSize);
		obj->baseSize = newSize;
	}
	obj->pushStack[obj->pushTop] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	Transform(obj->pushStack, obj->popStack, &obj->pushTop, &obj->popTop);
	int ans = obj->popStack[obj->popTop];
	obj->popTop -= 1;
	return ans;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	Transform(obj->pushStack, obj->popStack, &obj->pushTop, &obj->popTop);
	return obj->popStack[obj->popTop];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return obj->popTop == -1 && obj->pushTop == -1;
}

void myQueueFree(MyQueue* obj) {
	free(obj->popStack);
	obj->popStack = NULL;
	free(obj->pushStack);
	obj->pushStack = NULL;
	free(obj);
	obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/