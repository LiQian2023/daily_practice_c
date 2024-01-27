#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.01.27力扣网刷题
//反转链表——递归、链表——简单
//给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。
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
//进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

struct ListNode {
	int val;
	struct ListNode* next;
};
//法一：头插法反转链表
struct ListNode* reverseList1(struct ListNode* head) {
	if (!head)
		return head;
	struct ListNode* ph = head, * pl = NULL;
	struct ListNode* l = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	if (!l)
		return NULL;
	l->next = NULL;
	while (ph) {
		pl = ph;
		ph = ph->next;
		pl->next = l->next;
		l->next = pl;
	}
	return l->next;
}
//法二：递归
struct ListNode* reverseList(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode* l = reverseList(head->next);
	head->next->next = head;//翻转单个结点
	head->next = NULL;
	return l;
}