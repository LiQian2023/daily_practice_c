#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.05力扣网刷题
//61. 旋转链表——链表、双指针——中等
//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//示例 1：
//输入：head = [1, 2, 3, 4, 5], k = 2
//输出：[4, 5, 1, 2, 3]
//示例 2：
//输入：head = [0, 1, 2], k = 4
//输出：[2, 0, 1]
//提示：
//链表中节点的数目在范围[0, 500] 内
//- 100 <= Node.val <= 100
//0 <= k <= 2 * 10^9

struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode LN;

int getSize(LN* root) {
	if (!root) {
		return 0;
	}
	return getSize(root->next) + 1;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
	int size = getSize(head);
	if (size == 0 || k % size == 0) {
		return head;
	}
	int n = size - k % size;
	LN* pre = head;
	LN* p = pre->next;
	for (int i = 1; i < n; i++) {
		pre = p;
		p = p->next;
	}
	pre->next = NULL;
	pre = p;
	while (p && p->next) {
		p = p->next;
	}
	p->next = head;
	head = pre;
	return head;
}