#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.01.21力扣网刷题
//链表的中间结点——链表、双指针——简单
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
//示例 1：
//输入：head = [1, 2, 3, 4, 5]
//输出：[3, 4, 5]
//解释：链表只有一个中间结点，值为 3 。
//示例 2：
//输入：head = [1, 2, 3, 4, 5, 6]
//输出：[4, 5, 6]
//解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
//提示：
//链表的结点数范围是[1, 100]
//1 <= Node.val <= 100

struct ListNode {
	int val;
	struct ListNode* next;
};
//链表初始化——不带头结点
void InitList(struct ListNode** L) {
	assert(L);
	*L = NULL;
}
//尾插法创建链表
bool List_TailInsert(struct ListNode** L) {
	if (!L)
		return false;
	struct ListNode* l = *L, * r = NULL;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		if (!(*L)) {
			*L = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			if (!(*L))
				return false;
			(*L)->val = x;
			(*L)->next = NULL;
			l = *L;
		}
		else {
			r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			if (!r)
				return false;
			r->val = x;
			r->next = l->next;
			l->next = r;
			l = r;
		}
	}
	getchar();
	return true;
}
struct ListNode* middleNode(struct ListNode* head) {
	if (!head)
		return head;
	struct ListNode* f = head, * s = head;
	while (f && f->next) {
		f = f->next->next;
		s = s->next;
	}
	return s;
}
//打印链表
void Print_List(struct ListNode* L) {
	printf("链表元素为>:");
	while (L) {
		printf("%d->", L->val);
		L = L->next;
	}
	printf("NULL\n");
}
int main() {
	struct ListNode* L;
	InitList(&L);
	if (List_TailInsert(&L)) {
		printf("寻找中间结点前");
		Print_List(L);
		struct ListNode* p = middleNode(L);
		printf("寻找中间结点后");
		Print_List(p);
	}
	return 0;
}