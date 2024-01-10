#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.01.10力扣网刷题
//反转链表——递归、链表——简单
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//示例 1：
//输入：head = [1, 2, 3, 4, 5]
//输出：[5, 4, 3, 2, 1]
//示例 2：
//输入：head = [1, 2]
//输出：[2, 1]
//示例 3：
//输入：head = []
//输出：[]
//提示：
//链表中节点的数目范围是[0, 5000]
//- 5000 <= Node.val <= 5000
struct ListNode {
	int val;
	struct ListNode* next;
};
//初始化单链表
void InitList(struct ListNode** L) {
	assert(L);
	*L = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	assert(*L);
	(*L)->next = NULL;
	(*L)->val = 0;
}
//尾插法建立单链表
void List_TailInsert(struct ListNode** L) {
	assert(L);
	struct ListNode* l = *L;
	struct ListNode* r = NULL;
	int x = 0;
	int len = 0;
	while (scanf("%d", &x) == 1) {
		r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		assert(r);
		r->val = x;
		r->next = l->next;
		l->next = r;
		l = r;
		len++;
	}
	(*L)->val = len;
}
//使用头插法反转单链表
struct ListNode* reverseList(struct ListNode* head) {
	if (!head)
		return NULL;
	struct ListNode* L = (struct ListNode*)calloc(1, sizeof(struct ListNode));//创建新链表
	if (!L)
		return NULL;
	L->next = NULL;//初始化后继指针
	struct ListNode* p = NULL;//指向新结点的指针
	struct ListNode* q = head->next;//指向表头结点的指针
	while (q) {
		p = q;//指针p指向插入新链表的结点
		q = q->next;//指针q指向下一个需要插入的结点
		p->next = L->next;//头插法插入结点
		L->next = p;//新结点称为新的表头结点
	}
	return L;
}

int main() {
	struct ListNode* L;
	InitList(&L);
	List_TailInsert(&L);
	L = reverseList(L);
	return 0;
}