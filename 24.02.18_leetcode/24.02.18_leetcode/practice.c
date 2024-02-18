#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.18力扣网刷题
//重排链表——栈、递归、链表、双指针——中等
//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//L0 → L1 → … → Ln - 1 → Ln
//请将其重新排列后变为：
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//示例 1:
//输入: head = [1, 2, 3, 4]
//输出 : [1, 4, 2, 3]
//示例 2 :
//输入: head = [1, 2, 3, 4, 5]
//输出 : [1, 5, 2, 4, 3]
//提示：
//链表的长度范围为[1, 5 * 10^4]
//1 <= node.val <= 1000

void reorderList(struct ListNode* head) {
	int len = 0;
	struct ListNode* p = head;
	while (p) {
		len++;
		p = p->next;
	}
	if (len < 3)
		return;
	struct ListNode* l1 = head;//前半段链表
	struct ListNode* p1 = head;//前半段尾指针
	int a = len / 2;
	while (--a) {
		p1 = p1->next;
	}
	if (len % 2)
		p1 = p1->next;
	head = p1->next;
	p1->next = NULL;//切割链表
	struct ListNode* l2 = NULL;//后半段链表
	struct ListNode* p2 = head;//后半段尾指针
	while (head) {
		p2 = head;
		head = head->next;
		//头插法创建后半段链表
		p2->next = l2;
		l2 = p2;
	}
	//顺序合并两链表
	while (l2) {
		p1 = l1;
		l1 = l1->next;
		if (!head) {
			p1->next = head;
			head = p1;
			p = head;
		}
		else {
			//尾插
			p1->next = p->next;
			p->next = p1;
			p = p1;
		}
		p2 = l2;
		l2 = l2->next;
		p2->next = p->next;
		p->next = p2;
		p = p2;
	}
	p->next = l1;
}
