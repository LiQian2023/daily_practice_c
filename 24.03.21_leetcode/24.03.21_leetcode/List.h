#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAXSIZE 10//最大表长
typedef int Elemtype;
typedef struct SqList {
	int data[MAXSIZE];//数据域
	int len;//当前表长
}SqList;

//顺序表的初始化
bool InitList(SqList* L);
//顺序表的打印
void PrintList(SqList L);
//顺序表顺序表添加元素
bool ListInsert(SqList* L, int i, Elemtype e);

struct ListNode {
	int val;
	struct ListNode* next;
};

//链表初始化
void ListInit(struct ListNode** L);
//尾插法创建链表
void TailInsert(struct ListNode** L);
//打印链表
void ListPrint(struct ListNode* L);
//销毁链表
void DestroyList(struct ListNode** L);

