#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.10力扣网刷题
//重排链表——栈、递归、链表、双指针——中等
//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//L0 → L1 → … → Ln - 1 → Ln
//请将其重新排列后变为：
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//示例 1：
//输入：head = [1, 2, 3, 4]
//输出：[1, 4, 2, 3]
//示例 2：
//输入：head = [1, 2, 3, 4, 5]
//输出：[1, 5, 2, 4, 3]
//提示：
//链表的长度范围为[1, 5 * 10^4]
//1 <= node.val <= 1000

//法一：头尾链表合并
void reorderList(struct ListNode* head) {
	int len = 0;
	struct ListNode* p = head;
	while (p) {
		len++;
		p = p->next;
	}
	int len1 = len / 2;
	p = head;
	//找到头链表的尾结点
	if (len % 2) {
		for (int i = 1; i <= len1; i++) {
			p = p->next;
		}
	}
	else {
		for (int i = 1; i < len1; i++) {
			p = p->next;
		}
	}
	struct ListNode* l = (struct ListNode*)calloc(1, sizeof(struct ListNode)),
		* s = NULL, * q = p->next;
	p->next = NULL;//分割链表
	//头插法创建尾链表
	while (q) {
		s = q;//提取插入的结点
		q = q->next;//找到下一个结点
		s->next = l->next;
		l->next = s;
	}
	//合并链表
	p = head;//头链表的队头结点
	while (l->next) {
		s = l->next;//尾链表的队头结点
		l->next = s->next;//删除头结点
		//合并链表结点
		s->next = p->next;
		p->next = s;
		p = s->next;
	}
}