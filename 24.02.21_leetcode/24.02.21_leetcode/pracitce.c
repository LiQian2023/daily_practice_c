#define _CRT_SECURE_NO_WARNINGS 1

#include"practice.h"

//2024.02.21力扣网刷题
//奇偶链表——链表——中等
//给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。
//第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。
//请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。
//你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。
//示例 1:
//输入: head = [1, 2, 3, 4, 5]
//输出 : [1, 3, 5, 2, 4]
//示例 2 :
//输入: head = [2, 1, 3, 5, 6, 4, 7]
//输出 : [2, 3, 6, 7, 1, 5, 4]
//提示 :
//	n == 链表中的节点数
//	0 <= n <= 10^4
//	- 106 <= Node.val <= 10^6

struct ListNode* oddEvenList(struct ListNode* head) {
	struct ListNode* ph = head, * q = NULL, * str = (struct LsitNode*)calloc(1, sizeof(struct ListNode));
	assert(str);
	str->next = head;
	head = str;
	struct ListNode* l = (struct ListNode*)calloc(1, sizeof(struct ListNode)), * pl = NULL;
	assert(l);
	l->next = NULL;
	pl = l;
	while (ph && ph->next) {
		q = ph->next;
		ph->next = q->next;
		q->next = pl->next;
		pl->next = q;
		pl = q;
		str = ph;
		ph = ph->next;
	}
	if (!ph) {
		str->next = l->next;
	}
	else if (ph) {
		ph->next = l->next;
	}
	free(l);
	str = head;
	head = head->next;
	free(str);
	return head;
}