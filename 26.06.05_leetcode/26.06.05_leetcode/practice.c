#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.06.05力扣网刷题
//面试题 03.01.三合一 —— 栈、设计、数组——简单
//三合一。描述如何只用一个数组来实现三个栈。
//你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。
//构造函数会传入一个stackSize参数，代表每个栈的大小。
//示例 1：
//输入：
//["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
//[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
//输出：
//[null, null, null, 1, -1, -1, true]
//说明：当栈为空时`pop, peek`返回 - 1，当栈满时`push`不压入元素。
//示例 2：
//输入：
//["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
//[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
//输出：
//[null, null, null, null, 2, 1, -1, -1]
//提示：
//0 <= stackNum <= 2




typedef struct {
	int size;
	int index[3];
	int top[3];
	int* stack;
} TripleInOne;

void Print(int* num, int len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		if (i != len - 1) {
			printf("%d, ", num[i]);

		}
		else {
			printf("%d", num[i]);
		}
	}
	printf("]\n\n");
}

TripleInOne* tripleInOneCreate(int stackSize) {
	TripleInOne* obj = (TripleInOne*)calloc(1, sizeof(TripleInOne));
	assert(obj);
	obj->size = stackSize;
	for (int i = 0; i < 3; i++) {
		obj->index[i] = stackSize * i;
		obj->top[i] = stackSize * i;
	}
	obj->stack = (int*)calloc(obj->size * 3, sizeof(int));
	assert(obj->stack);
	return obj;
}

void tripleInOnePush(TripleInOne* obj, int stackNum, int value) {
	if (obj->top[stackNum] == obj->index[stackNum] + obj->size) {
		return;
	}
	obj->stack[obj->top[stackNum]] = value;
	obj->top[stackNum] += 1;
}

int tripleInOnePop(TripleInOne* obj, int stackNum) {
	if (obj->top[stackNum] == obj->index[stackNum]) {
		return -1;
	}
	int ans = obj->stack[obj->top[stackNum] - 1];
	obj->top[stackNum] -= 1;
	return ans;
}

int tripleInOnePeek(TripleInOne* obj, int stackNum) {
	if (obj->top[stackNum] == obj->index[stackNum]) {
		return -1;
	}
	return obj->stack[obj->top[stackNum] - 1];
}

bool tripleInOneIsEmpty(TripleInOne* obj, int stackNum) {
	return obj->top[stackNum] == obj->index[stackNum];
}

void tripleInOneFree(TripleInOne* obj) {
	free(obj->stack);
	obj->stack = NULL;
	free(obj);
	obj = NULL;
}

/**
 * Your TripleInOne struct will be instantiated and called as such:
 * TripleInOne* obj = tripleInOneCreate(stackSize);
 * tripleInOnePush(obj, stackNum, value);

 * int param_2 = tripleInOnePop(obj, stackNum);

 * int param_3 = tripleInOnePeek(obj, stackNum);

 * bool param_4 = tripleInOneIsEmpty(obj, stackNum);

 * tripleInOneFree(obj);
*/