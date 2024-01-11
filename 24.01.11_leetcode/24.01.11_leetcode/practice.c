#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//24.01.11力扣网刷题
//两数相加——递归、链表、数学——中等
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//示例 1：
//输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
//输出：[7, 0, 8]
//解释：342 + 465 = 807.
//示例 2：
//输入：l1 = [0], l2 = [0]
//输出：[0]
//示例 3：
//输入：l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//输出：[8, 9, 9, 9, 0, 0, 0, 1]
//提示：
//每个链表中的节点数在范围[1, 100] 内
//0 <= Node.val <= 9
//题目数据保证列表表示的数字不含前导零

struct ListNode {
	int val;
	struct ListNode* next;
};
void InitList(struct ListNode** L) {
	assert(L);
	*L = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	assert(*L);
	(*L)->next = NULL;
	(*L)->val = 0;
}
void List_TailInsert(struct ListNode** L) {
	assert(L);
	struct ListNode* p = *L, * q = NULL;
	int x = 0;
	int len = 0;
	while (scanf("%d", &x) == 1) {
		q = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		assert(q);
		q->val = x;
		q->next = p->next;
		p->next = q;
		p = q;
		len++;
	}
	getchar();
	(*L)->val = len;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if ((!l1) && (!l2))
		return NULL;
	struct ListNode* p1 = l1->next, * p2 = l2->next;
	struct ListNode* l3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	if (!l3)
		return NULL;
	l3->next = NULL;
	l3->val = NULL;
	struct ListNode* p3 = l3, * q = NULL;
	while (p1 && p2) {
		q = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		if (!q)
			return NULL;
		q->val = p1->val + p2->val;
		q->next = p3->next;
		p3->next = q;
		p3 = q;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1)
		p3->next = p1;
	else if (p2)
		p3->next = p2;
	p3 = l3->next;
	while (p3) {
		if ((p3->next == NULL) && (p3->val > 9)) {
			q = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(q);
			q->val = 0;
			q->next = p3->next;
			p3->next = q;
		}
		if (p3->val > 9) {
			p3->val %= 10;
			p3->next->val += 1;
		}
		p3 = p3->next;
	}
	free(q);
	return l3;
}

int main() {
	struct ListNode* L1, * L2;
	InitList(&L1);
	InitList(&L2);
	List_TailInsert(&L1);
	List_TailInsert(&L2);
	struct LiseNode* ret = addTwoNumbers(L1, L2);
	assert(ret);
	return 0;
}