#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"


//2024.02.20力扣网刷题
//链表求和——递归、链表、数学——中等
//给定两个用链表表示的整数，每个节点包含一个数位。
//这些数位是反向存放的，也就是个位排在链表首部。
//编写函数对这两个整数求和，并用链表形式返回结果。
//示例：
//输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
//输出：2 -> 1 -> 9，即912
//进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢 ?
//示例：
//输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
//输出：9 -> 1 -> 2，即912

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p1 = l1, * p2 = l2,
		* l3 = (struct ListNode*)calloc(1, sizeof(struct ListNode)),
		* p3 = NULL, * q = NULL;
	assert(l3);
	q = l3;//队尾指针
	while (p1 && p2) {
		p3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		assert(p3);
		p3->val = p1->val + p2->val;
		p1 = p1->next;
		p2 = p2->next;
		if (p3->val >= 10) {
			p3->val %= 10;
			if (p1)
				p1->val += 1;
			else {
				p1 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
				assert(p1);
				p1->val = 1;
				p1->next = NULL;
			}
		}
		p3->next = q->next;
		q->next = p3;
		q = p3;
	}
	if (p1) {
		q->next = p1;
		while (p1->val >= 10) {
			p1->val %= 10;
			if (p1->next)
			{
				p1->next->val += 1;
				p1 = p1->next;
			}
			else {
				p3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
				assert(p3);
				p3->val = 1;
				p3->next = p1->next;
				p1->next = p3;
				p1 = p3;
			}
		}
	}
	else if (p2) {
		q->next = p2;
	}
	q = l3;
	l3 = l3->next;
	free(q);
	return l3;
}