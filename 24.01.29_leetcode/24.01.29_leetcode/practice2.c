#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.01.29力扣网刷题
//训练计划 III——递归、链表——简单
//给定一个头节点为 head 的单链表用于记录一系列核心肌群训练编号，请将该系列训练编号 倒序 记录于链表并返回。
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

//法一：新链表头插法
struct ListNode* trainningPlan1(struct ListNode* head) {
	if (!head)
		return head;
	struct ListNode* l = NULL, * p = head, * q = NULL;
	while (p) {
		q = p;
		p = p->next;
		q->next = l;
		l = q;
	}
	return l;
}
//法二：递归
struct ListNode* trainningPlan2(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode* l = trainningPlan(head->next);
	head->next->next = head;
	head->next = NULL;
	return l;
}
//法三：三指针
struct ListNode* trainningPlan(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode* p = head, * q = head->next, * l = NULL;
	while (p) {
		p->next = l;
		l = p;
		p = q;
		if (q)
			q = q->next;
	}
	return l;
}