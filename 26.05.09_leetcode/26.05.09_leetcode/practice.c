#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.09力扣网刷题
//LCR 125. 图书整理 II——栈、设计、队列——简单
//读者来到图书馆排队借还书，图书管理员使用两个书车来完成整理借还书的任务。书车中的书从下往上叠加存放，图书管理员每次只能拿取书车顶部的书。排队的读者会有两种操作：
//push(bookID)：把借阅的书籍还到图书馆。
//pop()：从图书馆中借出书籍。
//为了保持图书的顺序，图书管理员每次取出供读者借阅的书籍是 最早 归还到图书馆的书籍。你需要返回 每次读者借出书的值 。
//如果没有归还的书可以取出，返回 - 1 。
//示例 1：
//输入：
//["BookQueue", "push", "push", "pop"]
//[[], [1], [2], []]
//输出：[null, null, null, 1]
//解释：
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.pop(); // return 1, queue is [2]
//提示：
//1 <= bookID <= 10000
//最多会对 push、pop 进行 10000 次调用




typedef struct {
	int* data;
	int front;
	int rear;
	int baseSize;
} CQueue;


CQueue* cQueueCreate() {
	CQueue* obj = (CQueue*)calloc(1, sizeof(CQueue));
	assert(obj);
	obj->baseSize = 10;
	obj->front = 0;
	obj->rear = 0;
	obj->data = (int*)calloc(obj->baseSize, sizeof(int));
	assert(obj->data);
	return obj;
}

void cQueueAppendTail(CQueue* obj, int value) {
	if ((obj->rear + 1) % obj->baseSize == obj->front) {
		int newSize = obj->baseSize + obj->baseSize / 2;
		int* tmp = (int*)calloc(newSize, sizeof(int));
		if (!tmp) {
			perror("calloc(tmp)");
			return;
		}
		int pi = 0;
		for (int i = obj->front; i != obj->rear; i = (i + 1) % obj->baseSize) {
			tmp[pi] = obj->data[i];
			pi += 1;
		}
		obj->front = 0;
		obj->rear = pi;
		obj->data = tmp;
		obj->baseSize = newSize;
	}
	obj->data[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->baseSize;
}

int cQueueDeleteHead(CQueue* obj) {
	if (obj->front == obj->rear) {
		return -1;
	}
	int res = obj->data[obj->front];
	obj->front = (obj->front + 1) % obj->baseSize;
	return res;
}

void cQueueFree(CQueue* obj) {
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);

 * int param_2 = cQueueDeleteHead(obj);

 * cQueueFree(obj);
*/