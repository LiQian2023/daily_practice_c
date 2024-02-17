#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.17力扣网刷题
//两数相加 II——栈、链表、数学——中等
//给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//可以假设除了数字 0 之外，这两个数字都不会以零开头。
//示例1：
//输入：l1 = [7, 2, 4, 3], l2 = [5, 6, 4]
//输出：[7, 8, 0, 7]
//示例2：
//输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
//输出：[8, 0, 7]
//示例3：
//输入：l1 = [0], l2 = [0]
//输出：[0]
//提示：
//链表的长度范围为[1, 100]
//0 <= node.val <= 9
//输入数据保证链表代表的数字无前导 0
//进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* S1 = NULL, * S2 = NULL, * p1 = l1, * p2 = l2;
	//入栈
	while (p1) {
		l1 = l1->next;
		p1->next = S1;
		S1 = p1;
		p1 = l1;
	}
	while (p2) {
		l2 = l2->next;
		p2->next = S2;
		S2 = p2;
		p2 = l2;
	}
	//相加
	struct ListNode* l3 = NULL;
	while (S1 && S2) {
		l1 = S1;
		S1 = S1->next;
		l2 = S2;
		S2 = S2->next;
		l1->val += l2->val;
		if (l1->val > 9) {
			l1->val %= 10;
			if (!S1)
			{
				S1 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
				S1->next = NULL;
			}
			S1->val += 1;
		}
		l1->next = l3;
		l3 = l1;
	}
	while (S1) {
		p1 = S1;
		S1 = S1->next;
		p1->next = l3;
		l3 = p1;
	}
	while (S2) {
		p2 = S2;
		S2 = S2->next;
		p2->next = l3;
		l3 = p2;
	}
	return l3;
}