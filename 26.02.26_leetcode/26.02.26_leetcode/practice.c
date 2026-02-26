#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.02.26力扣网刷题
//232. 用栈实现队列——栈、设计、队列——简单
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//实现 MyQueue 类：
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//说明：
//你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//示例 1：
//输入：
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 1, 1, false]
//解释：
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false
//提示：
//1 <= x <= 9
//最多调用 100 次 push、pop、peek 和 empty
//假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
//进阶：
//你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。

#define MAXSIZE 100
typedef struct Stack {
	int data[MAXSIZE];
	int top;
	int len;
	int maxSize;
} Stack;

Stack* CreateStack() {
	Stack* S = (Stack*)calloc(1, sizeof(Stack));
	assert(S);
	S->top = -1;
	S->len = 0;
	S->maxSize = MAXSIZE;
	return S;
}
bool isEmpty(Stack* s) {
	return s->len == 0;
}
void Push(Stack* s, int x) {
	s->top += 1;
	s->data[s->top] = x;
	s->len += 1;
}
int Pop(Stack* s) {
	if (isEmpty(s)) {
		return -1;
	}
	int top = s->data[s->top];
	s->top -= 1;
	s->len -= 1;
	return top;
}
int getTop(Stack* s) {
	return s->data[s->top];
}
void Destroy(Stack** s) {
	free(*s);
	*s = NULL;
}
typedef struct {
	Stack* pushStack;
	Stack* popStack;
	int len;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)calloc(1, sizeof(MyQueue));
	assert(obj);
	obj->popStack = CreateStack();
	obj->pushStack = CreateStack();
	obj->len = 0;
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	for (int i = obj->popStack->top; i >= 0; i--) {
		int x = Pop(obj->popStack);
		Push(obj->pushStack, x);
	}
	Push(obj->pushStack, x);
	obj->len += 1;
}

int myQueuePop(MyQueue* obj) {
	for (int i = obj->pushStack->top; i >= 0; i--) {
		int x = Pop(obj->pushStack);
		Push(obj->popStack, x);
	}
	int x = Pop(obj->popStack);
	obj->len -= 1;
	return x;
}

int myQueuePeek(MyQueue* obj) {
	for (int i = obj->pushStack->top; i >= 0; i--) {
		int x = Pop(obj->pushStack);
		Push(obj->popStack, x);
	}
	return getTop(obj->popStack);
}

bool myQueueEmpty(MyQueue* obj) {
	return obj->len == 0;
}

void myQueueFree(MyQueue* obj) {
	Destroy(&obj->popStack);
	Destroy(&obj->pushStack);
	free(obj);
	obj = NULL;
}