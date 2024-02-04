#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.04力扣网刷题
//分隔链表——链表、双指针——中等
//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//你应当 保留 两个分区中每个节点的初始相对位置。
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

//方法一：大小链表
struct ListNode* partition1(struct ListNode* head, int x) {
	if (!head || !head->next)
		return head;
	struct ListNode* l = (struct ListNode*)calloc(1, sizeof(struct ListNode)),
		* s = (struct ListNode*)calloc(1, sizeof(struct ListNode)),
		* ph = head, * pl = l, * ps = s;
	if (!l || !s)
		return NULL;
	while (ph) {
		//尾插法创建大小链表
		if (ph->val >= x) {
			pl->next = ph;
			pl = ph;
			ph = ph->next;
			pl->next = NULL;
		}
		else {
			ps->next = ph;
			ps = ph;
			ph = ph->next;
			ps->next = NULL;
		}
	}
	//合并链表
	ps->next = l->next;
	pl = s->next;
	free(l);
	free(s);
	return pl;
}
//方法二：哨兵位尾插法
struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode* p = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	if (!p)
		return NULL;
	p->next = head;
	head = p;//创建哨兵位
	struct ListNode* l = head, * r = head->next;
	while (r) {
		if (r->val < x) {
			if (l->next == r) {
				l = r;
			}
			else {
				p->next = r->next;
				r->next = l->next;
				l->next = r;
				l = r;
			}
		}
		p = r;
		r = p->next;
	}
	p = head;
	head = p->next;
	free(p);
	return head;
}