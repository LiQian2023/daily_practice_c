#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.01.22力扣网刷题
//移除链表元素——递归、链表——简单
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//示例 1：
//输入：head = [1, 2, 6, 3, 4, 5, 6], val = 6
//输出：[1, 2, 3, 4, 5]
//示例 2：
//输入：head = [], val = 1
//输出：[]
//示例 3：
//输入：head = [7, 7, 7, 7], val = 7
//输出：[]
//提示：
//列表中的节点数目在范围[0, 104] 内
//1 <= Node.val <= 50
//0 <= val <= 50

struct ListNode {
	int val;
	struct ListNode* next;
};
void InitList(struct ListNode** L) {
	assert(L);
	*L = NULL;
}
void List_TailInsert(struct ListNode** L) {
	assert(L);
	struct ListNode* l = *L, * r = NULL;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		if (!l) {
			l = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(l);
			l->val = x;
			l->next = NULL;
			*L = l;
		}
		else {
			r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(r);
			r->val = x;
			r->next = l->next;
			l->next = r;
			l = r;
		}
	}
	getchar();
}
//法一：按值查找+删除
struct ListNode* removeElements1(struct ListNode* head, int val) {
	if (!head)
		return head;
	struct ListNode* p = head, * q = NULL;
	while (p && p->next) {
		if (head->val == val) {
			head = head->next;
			p->next = NULL;
			free(p);
			p = head;
		}
		else if (p->next->val == val) {
			q = p->next;
			p->next = q->next;
			q->next = NULL;
			free(q);
			q = NULL;
		}
		else
			p = p->next;
	}
	if (head->val == val) {
		free(head);
		head = NULL;
	}
	return head;
}
//法二：新链表
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (!head)
		return head;
	struct ListNode* p = head, * q = NULL, * L = NULL;
	while (p) {
		if (p->val != val) {
			if (!L) {
				L = p;
				p = p->next;
				L->next = NULL;
				q = L;
			}
			else {
				q->next = p;
				q = p;
				p = p->next;
				q->next = NULL;
			}
		}
		else
			p = p->next;
	}
	return L;
}
void Print_List(struct ListNode* L) {
	assert(L);
	while (L) {
		printf("%d->", L->val);
		L = L->next;
	}
	printf("NULL\n");
}
void DestroyList(struct ListNode** L) {
	assert(L);
	struct ListNode* p = *L;
	while (*L) {
		*L = (*L)->next;
		p->next = NULL;
		free(p);
		p = *L;
	}
}
int main() {
	struct ListNode* L;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		InitList(&L);
		List_TailInsert(&L);
		L=removeElements(L, x);
		Print_List(L);
		DestroyList(&L);
	}
	return 0;
}