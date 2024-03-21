#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"


//顺序表的初始化
bool InitList(SqList* L) {
	assert(L);//避免空指针，用assert进行断言
	L->len = 0;//将当前表长初始化为0
}

//顺序表的打印
void PrintList(SqList L) {
	printf("打印当前顺序表中的元素:");
	for (int i = 0; i < L.len; i++) {
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

//顺序表顺序表添加元素
bool ListInsert(SqList* L, int i, Elemtype e) {
	if (L == NULL)//对指针参数进行判空
	{
		printf("传参对象为空指针\n");
		return false;
	}
	if (L->len == MAXSIZE)//对顺序表进行判满
	{
		printf("顺序表已满\n");
		return false;
	}
	if (i<1 || i>L->len + 1)//对插入位序的合理性进行判断
	{
		printf("插入位序不合理\n");
		return false;
	}
	for (int j = L->len; j > i - 1; j--) {
		L->data[j] = L->data[j - 1];//移动元素
	}
	L->data[i - 1] = e;//插入新元素
	L->len++;
	return true;
}
