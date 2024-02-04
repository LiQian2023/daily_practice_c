#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.04力扣网刷题
// 两两交换链表中的节点——递归、链表——中等
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//示例 1：
//输入：head = [1, 2, 3, 4]
//输出：[2, 1, 4, 3]
//示例 2：
//输入：head = []
//输出：[]
//示例 3：
//输入：head = [1]
//输出：[1]
//提示：
//链表中节点的数目在范围[0, 100] 内
//0 <= Node.val <= 100

struct ListNode* swapPairs(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode* l = head, * r = head->next, * p = head;
	while (l && r) {
		//交换结点
		l->next = r->next;
		r->next = l;
		if (head == l) {
			head = r;
		}
		else {
			p->next = r;
		}
		l = r;
		r = l->next;
		//移动结点
		p = r;
		l = r->next;
		if (l)
			r = l->next;
	}
	return head;
}