#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.01.30力扣网刷题
//训练计划 IV——递归、链表——简单
//给定两个以 有序链表 形式记录的训练计划 l1、l2，分别记录了两套核心肌群训练项目编号，请合并这两个训练计划，按训练项目编号 升序 记录于链表并返回。
//注意：新链表是通过拼接给定的两个链表的所有节点组成的。
//示例 1：
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]
//示例 2：
//输入：l1 = [], l2 = []
//输出：[]
//示例 3：
//输入：l1 = [], l2 = [0]
//输出：[0]
//提示：
//0 <= 链表长度 <= 1000

//法一：新链表
struct ListNode* trainningPlan(struct ListNode* l1, struct ListNode* l2) {
	if (!l1)
		return l2;
	if (!l2)
		return l1;
	struct ListNode* l3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	if (!l3)
		return NULL;
	l3->next = NULL;
	struct ListNode* p1 = l1, * p2 = l2, * p3 = l3, * q = NULL;
	while (p1 && p2) {
		if (p1->val > p2->val) {
			q = p2;
			p2 = p2->next;
			//尾插
			q->next = p3->next;
			p3->next = q;
			p3 = q;
		}
		else {
			q = p1;
			p1 = p1->next;
			//尾插
			q->next = p3->next;
			p3->next = q;
			p3 = q;
		}
	}
	if (p1)
		p3->next = p1;
	if (p2)
		p3->next = p2;
	p3 = l3->next;
	free(l3);
	return p3;
}
