#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.03力扣网刷题
//删除链表的倒数第 N 个结点——链表、双指针——中等
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//示例 1：
//输入：head = [1, 2, 3, 4, 5], n = 2
//输出：[1, 2, 3, 5]
//示例 2：
//输入：head = [1], n = 1
//输出：[]
//示例 3：
//输入：head = [1, 2], n = 1
//输出：[1]
//提示：
//链表中结点的数目为 sz
//1 <= sz <= 30
//0 <= Node.val <= 100
//1 <= n <= sz
//进阶：你能尝试使用一趟扫描实现吗？

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* f = head, * s = head, * l = head;
	while (f && n) {
		f = f->next;
		n--;
	}
	while (f) {
		l = s;
		s = s->next;
		f = f->next;
	}
	if (l == s)
		head = head->next;
	l->next = s->next;
	free(s);
	return head;
}