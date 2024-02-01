#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.01力扣网刷题
//返回倒数第 k 个节点——链表、双指针——简单
//实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
//注意：本题相对原题稍作改动
//示例：
//输入： 1->2->3->4->5 和 k = 2
//输出： 4
//说明：
//给定的 k 保证是有效的。

//双指针
int kthToLast(struct ListNode* head, int k) {
	if (!head || !k)
		return 0;
	struct ListNode* f = head, * s = head;
	for (int i = 0; f && i < k; i++) {
		f = f->next;
	}
	while (f) {
		s = s->next;
		f = f->next;
	}
	return s->val;
}