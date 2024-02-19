#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.19力扣网刷题
//分割链表——链表、双指针——中等
//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//你不需要 保留 每个分区中各节点的初始相对位置。
//示例 1：
//输入：head = [1, 4, 3, 2, 5, 2], x = 3
//输出：[1, 2, 2, 4, 3, 5]
//示例 2：
//输入：head = [2, 1], x = 2
//输出：[1, 2]
//提示：
//链表中节点的数目在范围[0, 200] 内
//- 100 <= Node.val <= 100
//- 200 <= x <= 200

struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode* newhead = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	assert(newhead);
	struct ListNode* p = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	assert(p);
	p->next = head;
	head = p;
	struct ListNode* q = head->next, * l = newhead;
	while (q) {
		if (q->val >= x) {
			p->next = q->next;
			q->next = l->next;
			l->next = q;
			l = q;
			q = p->next;
		}
		else {
			p = q;
			q = q->next;
		}
	}
	if (p)
	{
		p->next = newhead->next;
		p = head;
		head = head->next;
		free(newhead);
		free(p);
	}
	return head;
}