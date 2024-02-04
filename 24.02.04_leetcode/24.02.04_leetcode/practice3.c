#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.04力扣网刷题
//反转链表 II——链表——中等
//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
//示例 1：
//输入：head = [1, 2, 3, 4, 5], left = 2, right = 4
//输出：[1, 4, 3, 2, 5]
//示例 2：
//输入：head = [5], left = 1, right = 1
//输出：[5]
//提示：
//链表中节点数目为 n
//1 <= n <= 500
//- 500 <= Node.val <= 500
//1 <= left <= right <= n
//进阶： 你可以使用一趟扫描完成反转吗？

void List_TailInsert(struct ListNode** L) {
	if (!L)
		perror("List_TailInsert():L");
	struct ListNode* l = *L, * r = NULL;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		if (!l) {
			l = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			if (!l)
				perror("List_TailInsert():calloc");
			l->val = x;
			l->next = NULL;
			*L = l;
		}
		else {
			r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			if(!r)
				perror("List_TailInsert():calloc");
			r->val = x;
			r->next = l->next;
			l->next = r;
			l = r;
		}
	}
}

//方法一：双链表合并
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
	if (!(left - right))
		return head;
	struct ListNode* l = NULL;
	struct ListNode* ph = head, * qh = NULL, * pl = NULL;
	//给链表申请头结点
	qh = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	if (!qh)
		return NULL;
	qh->next = head;
	head = qh;
	for (int i = 0; qh && i < left; i++) {
		ph = qh;//记录前驱结点
		qh = qh->next;//往后遍历
	}
	for (int i = left; i <= right; i++) {
		ph->next = qh->next;//删除结点
		qh->next = l;//插入新链表
		l = qh;//头插
		if (!qh->next)
			pl = qh;//记录表尾
		qh = ph->next;//往后遍历
	}
	if (pl) {
		pl->next = qh;//表尾指针指向原链表
		ph->next = l;//合并链表
	}
	ph = head;
	head = head->next;
	free(ph);
	return head;
}
void DestroyList(struct ListNode** L) {
	struct ListNode* p = *L;
	while (p) {
		*L = p->next;
		free(p);
		p = *L;
	}
}
int main() {
	struct ListNode* L = { 0 };
	L = NULL;
	List_TailInsert(&L);
	L = reverseBetween(L, 1, 2);
	DestroyList(&L);
	return 0;
}