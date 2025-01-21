#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2025.01.21力扣网刷题
//设计哈希集合——设计、哈希表、链表、哈希函数、数组——简单
//不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
//实现 MyHashSet 类：
//void add(key) 向哈希集合中插入值 key 。
//bool contains(key) 返回哈希集合中是否存在这个值 key 。
//void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
//示例：
//输入：
//["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
//[[], [1], [2], [1], [3], [2], [2], [2], [2]]
//输出：
//[null, null, null, true, false, null, true, null, false]
//解释：
//MyHashSet myHashSet = new MyHashSet();
//myHashSet.add(1);      // set = [1]
//myHashSet.add(2);      // set = [1, 2]
//myHashSet.contains(1); // 返回 True
//myHashSet.contains(3); // 返回 False ，（未找到）
//myHashSet.add(2);      // set = [1, 2]
//myHashSet.contains(2); // 返回 True
//myHashSet.remove(2);   // set = [1]
//myHashSet.contains(2); // 返回 False ，（已移除）
//提示：
//0 <= key <= 10^6
//最多调用 10^4 次 add、remove 和 contains

typedef struct LinkNode {
	int key;
	struct LinkNode* next;
}LN;

typedef struct {
	LN* head;
} MyHashSet;


MyHashSet* myHashSetCreate() {
	//创建头结点
	MyHashSet* obj = (MyHashSet*)calloc(1, sizeof(MyHashSet));
	assert(obj);
	obj->head = (LN*)calloc(1, sizeof(LN));
	assert(obj->head);
	return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
	assert(obj);
	LN* p = (LN*)calloc(1, sizeof(LN));
	assert(p);
	p->key = key;
	p->next = NULL;
	LN* L = obj->head;
	while (L->next && L->next->key < p->key) {
		L = L->next;
	}
	if (L->next == NULL || L->next->key > p->key) {
		p->next = L->next;
		L->next = p;
	}
}

void myHashSetRemove(MyHashSet* obj, int key) {
	assert(obj);
	LN* L = obj->head;
	while (L->next && L->next->key != key) {
		L = L->next;
	}
	if (L->next) {
		LN* p = L->next;
		L->next = p->next;
		p->next = NULL;
		free(p);
		p = NULL;
	}
}

bool myHashSetContains(MyHashSet* obj, int key) {
	assert(obj);
	LN* L = obj->head;
	while (L->next && L->next->key != key) {
		L = L->next;
	}
	return L->next != NULL;
}

void myHashSetFree(MyHashSet* obj) {
	assert(obj);
	LN* p = obj->head;
	while (p->next) {
		LN* tmp = p->next;
		p->next = tmp->next;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
	free(p);
	p = NULL;
	free(obj);
	obj = NULL;
}