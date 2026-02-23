#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.02.23力扣网刷题
//225. 用队列实现栈——栈、设计、队列——简单
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//实现 MyStack 类：
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//注意：
//你只能使用队列的标准操作 —— 也就是 push to back、peek / pop from front、size 和 is empty 这些操作。
//你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//示例：
//输入：
//["MyStack", "push", "push", "top", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 2, 2, false]
//解释：
//MyStack myStack = new MyStack();
//myStack.push(1);
//myStack.push(2);
//myStack.top(); // 返回 2
//myStack.pop(); // 返回 2
//myStack.empty(); // 返回 False
//提示：
//1 <= x <= 9
//最多调用100 次 push、pop、top 和 empty
//每次调用 pop 和 top 都保证栈不为空
//进阶：你能否仅用一个队列来实现栈。

#define MAXSIZE 100
// 双端队列模拟实现栈
typedef struct deque {
	int data[MAXSIZE];
	int front_l, front_r;
	int rear_l, rear_r;
	int que_len;
	int l_len, r_len;
	int max_len;
}deque;
deque* CreateDeque() {
	deque* que = (deque*)calloc(1, sizeof(deque));
	assert(que);
	que->max_len = MAXSIZE;
	que->front_l = -1;
	que->rear_l = -1;
	que->front_r = que->max_len;
	que->rear_r = que->max_len;
	que->que_len = 0;
	return que;
}
bool isEmpty(deque* q, char dic) {
	if (dic == 'l') {
		return q->l_len == 0;
	}
	return q->r_len == 0;
}
void pushToBack(deque* q, int x, char dic) {
	if (dic == 'l') {
		// 只允许从左端入，左端出
		if (q->rear_l < q->rear_r) {
			q->rear_r -= 1;
			q->front_r -= 1;
			q->data[q->rear_r] = x;
			q->que_len += 1;
			q->l_len += 1;
		}
	}
	else if (dic == 'r') {
		// 只允许从右端入，右端出
		if (q->rear_r > q->rear_l) {
			q->rear_l += 1;
			q->front_l += 1;
			q->data[q->rear_l] = x;
			q->que_len += 1;
			q->r_len += 1;
		}
	}
}
int popFromFront(deque* q, char dic) {
	if (isEmpty(q, dic)) {
		return 0;
	}
	int x = 0;
	if (dic == 'l') {
		x = q->data[q->front_r];
		q->front_r += 1;
		q->rear_r += 1;
		q->que_len -= 1;
		q->l_len -= 1;
	}
	else if (dic == 'r') {
		x = q->data[q->front_l];
		q->front_l -= 1;
		q->rear_l -= 1;
		q->que_len -= 1;
		q->r_len -= 1;
	}
	return x;
}

void freeDeque(deque** q) {
	free(*q);
	*q = NULL;
}
typedef struct {
	deque* q;
} MyStack;


MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)calloc(1, sizeof(MyStack));
	assert(obj);
	obj->q = CreateDeque();
	return obj;
}

void PrintStack(MyStack* obj) {
	for (int i = 0; i < obj->q->que_len; i++) {
		printf("%d, ", obj->q->data[i]);
	}
	printf("\n");
}

void myStackPush(MyStack* obj, int x) {
	// 默认从左端进，左端出
	pushToBack(obj->q, x, 'l');
}

int myStackPop(MyStack* obj) {
	return popFromFront(obj->q, 'l');
}

int myStackTop(MyStack* obj) {
	int x = popFromFront(obj->q, 'l');
	pushToBack(obj->q, x, 'l');
	return x;
}

bool myStackEmpty(MyStack* obj) {
	return isEmpty(obj->q, 'l');
}

void myStackFree(MyStack* obj) {
	if (!myStackEmpty(obj)) {
		freeDeque(&(obj->q));
		free(obj);
		obj = NULL;
	}
}