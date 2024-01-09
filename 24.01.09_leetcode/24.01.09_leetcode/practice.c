#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2024.01.09力扣网刷题
//合并两个有序链表——递归、链表——简单
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//1->2->3
//1->3->4
//1->1->2->3->3->4
//示例 1：
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]
//示例 2：
//输入：l1 = [], l2 = []
//输出：[]
//示例 3：
//输入：l1 = [], l2 = [0]
//输出：[0]
//提示：
//两个链表的节点数目范围是[0, 50]
//- 100 <= Node.val <= 100
//l1 和 l2 均按 非递减顺序 排列

//typedef struct LNode {
//	int val;
//	struct LNode* next;
//}LNode, * LinkList;
////初始化链表
//bool InitList(LinkList* L) {
//	assert(L);
//	(*L) = (LNode*)calloc(1, sizeof(LNode));
//	assert(*L);
//	(*L)->next = NULL;
//	(*L)->val = 0;
//	return true;
//}
////合并两个链表
//LinkList mergeTwoLists(LinkList L1, LinkList L2) {
//	assert(L1 && L2);
//	LNode* p1 = L1->next;
//	LNode* p2 = L2->next;
//	assert(p1 && p2);
//	LinkList L3 = (LNode*)calloc(1, sizeof(LNode));//头结点
//	assert(L3);
//	if (p1->val > p2->val) {
//		L3->next = p2;
//		p2 = p2->next;
//	}
//	else {
//		L3->next = p1;
//		p1 = p1->next;
//	}
//	LNode* p3 = L3->next;//表头结点
//	assert(p3);
//	LNode* p4 = NULL;//后继结点
//	while (p1 && p2) {
//		if (p1->val >= p2->val) {
//			p4 = p2;
//			p2 = p2->next;
//			if (p3->next == p4) {
//				p3 = p4;
//				continue;
//			}
//			p4->next = p3->next;
//			p3->next = p4;
//			p3 = p4;
//		}
//		else {
//			p4 = p1;
//			p1 = p1->next;
//			if (p3->next == p4) {
//				p3 = p4;
//				continue;
//			}
//			p4->next = p3->next;
//			p3->next = p4;
//			p3 = p4;
//		}
//	}
//	if (p1 == NULL && p2) {
//		p3->next = p2;
//	}
//	else if (p2 == NULL && p1) {
//		p3->next = p1;
//	}
//	return L3;
//}
////创建链表
//LinkList List_TailInsert(LinkList* L) {
//	assert(L);
//	LNode* l = NULL;
//	LNode* r = (*L);
//	int x = 0;
//	while (scanf("%d", &x) == 1) {
//		l = (LNode*)calloc(1, sizeof(LNode));
//		assert(l);
//		l->next = r->next;
//		r->next = l;
//		r = l;
//		l->val = x;
//	}
//	getchar();
//	return *L;
//}
////打印链表
//void PrintList(LinkList L) {
//	assert(L);
//	LNode* p = L->next;
//	while (p) {
//		printf("%d,", p->val);
//		p = p->next;
//	}
//}
//
//int main() {
//	LinkList L1, L2;
//	if (InitList(&L1) && InitList(&L2)) {
//		L1 = List_TailInsert(&L1);
//		assert(L1);
//		L2 = List_TailInsert(&L2);
//		assert(L2);
//		LinkList L3 = mergeTwoLists(L1, L2);
//		PrintList(L3);
//	}
//	return 0;
//}

//合并两个链表——无头结点
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode* p1 = list1;
	struct ListNode* p2 = list2;
	struct ListNode* L3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));//头结点
	if (p1 == NULL && p2) {
		L3->next = p2;
	}
	else if (p2 == NULL && p1) {
		L3->next = p1;
	}
	else if ((!p1) && (!p2)) {
		L3->next = NULL;
	}
	else {
		if (p1->val > p2->val) {
			L3->next = p2;
			p2 = p2->next;
		}
		else {
			L3->next = p1;
			p1 = p1->next;
		}
		struct ListNode* p3 = L3->next;//表头结点
		struct ListNode* p4 = NULL;//后继结点
		while (p1 && p2) {
			if (p1->val >= p2->val) {
				p4 = p2;
				p2 = p2->next;
				if (p3->next == p4) {
					p3 = p4;
					continue;
				}
				p4->next = p3->next;
				p3->next = p4;
				p3 = p4;
			}
			else {
				p4 = p1;
				p1 = p1->next;
				if (p3->next == p4) {
					p3 = p4;
					continue;
				}
				p4->next = p3->next;
				p3->next = p4;
				p3 = p4;
			}
		}
		if (p1 == NULL && p2) {
			p3->next = p2;
		}
		else if (p2 == NULL && p1) {
			p3->next = p1;
		}
	}
	return L3->next;
}