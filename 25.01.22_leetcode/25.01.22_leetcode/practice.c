#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.01.22力扣网刷题
//设计哈希映射——设计、数组、哈希表、链表、哈希函数——简单
//不使用任何内建的哈希表库设计一个哈希映射（HashMap）。
//实现 MyHashMap 类：
//MyHashMap() 用空映射初始化对象
//void put(int key, int value) 向 HashMap 插入一个键值对(key, value) 。如果 key 已经存在于映射中，则更新其对应的值 value 。
//int get(int key) 返回特定的 key 所映射的 value ；如果映射中不包含 key 的映射，返回 - 1 。
//void remove(key) 如果映射中存在 key 的映射，则移除 key 和它所对应的 value 。
//示例：
//输入：
//["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
//[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
//输出：
//[null, null, null, 1, -1, null, 1, null, -1]
//解释：
//MyHashMap myHashMap = new MyHashMap();
//myHashMap.put(1, 1); // myHashMap 现在为 [[1,1]]
//myHashMap.put(2, 2); // myHashMap 现在为 [[1,1], [2,2]]
//myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
//myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
//myHashMap.put(2, 1); // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
//myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
//myHashMap.remove(2); // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
//myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
//提示：
//0 <= key, value <= 10^6
//最多调用 10^4 次 put、get 和 remove 方法

typedef struct LinkNode {
	int key;
	int value;
	struct LinkNode* next;
}LN;

typedef struct {
	LN* head;
} MyHashMap;

LN* LinkListCreat() {
	LN* l = (LN*)calloc(1, sizeof(LN));
	assert(l);
	return l;
}
void LinkListPut(LN* l, int key, int value) {
	assert(l);
	LN* q = l;
	while (q->next && q->next->key < key) {
		q = q->next;
	}
	if (q->next && q->next->key == key) {
		q->next->value = value;
	}
	else {
		LN* p = (LN*)calloc(1, sizeof(LN));
		assert(p);
		p->key = key;
		p->value = value;
		p->next = q->next;
		q->next = p;
	}
}

int LinkListGet(LN* l, int key) {
	assert(l);
	LN* p = l->next;
	while (p && p->key < key) {
		p = p->next;
	}
	return p && p->key == key ? p->value : -1;
}
void LinkListRemove(LN* l, int key) {
	assert(l);
	LN* p = l->next;
	while (p && p->key < key) {
		l = p;
		p = p->next;
	}
	if (p && p->key == key) {
		l->next = p->next;
		p->next = NULL;
		free(p);
	}
}
void LinkListFree(LN* l) {
	assert(l);
	while (l->next) {
		LN* p = l->next;
		l->next = p->next;
		p->next = NULL;
		free(p);
	}
	free(l);
}
#define HASHSIZE 1000
MyHashMap* myHashMapCreate() {
	MyHashMap* hash = (MyHashMap*)calloc(HASHSIZE, sizeof(MyHashMap));
	assert(hash);
	for (int i = 0; i < HASHSIZE; i++) {
		(hash[i]).head = LinkListCreat();
	}
	return hash;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
	int hash_key = key % HASHSIZE;
	LinkListPut(obj[hash_key].head, key, value);
}

int myHashMapGet(MyHashMap* obj, int key) {
	int hash_key = key % HASHSIZE;
	return LinkListGet(obj[hash_key].head, key);
}

void myHashMapRemove(MyHashMap* obj, int key) {
	int hash_key = key % HASHSIZE;
	LinkListRemove(obj[hash_key].head, key);
}

void myHashMapFree(MyHashMap* obj) {
	for (int i = 0; i < HASHSIZE; i++) {
		LinkListFree(obj[i].head);
	}
}