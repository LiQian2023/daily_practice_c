#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//回文链表——栈、递归、链表、双指针——简单
//编写一个函数，检查输入的链表是否是回文的。
//示例 1：
//输入： 1->2
//输出： false
//示例 2：
//输入： 1->2->2->1
//输出： true
//进阶：
//你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

bool isPalindrome(struct ListNode* head) {
	if (!head)
		return false;
	int len = 0;
	struct ListNode* p = head;
	while (p) {
		len++;
		p = p->next;
	}
	p = head;
	int* stack = (int*)calloc(len / 2, sizeof(int));
	if (!stack)
		return false;
	int top = 0;
	for (top = 0; top < len / 2; top++) {
		stack[top] = p->val;
		p = p->next;
	}
	if (0 == len % 2) {
		for (--top; top >= 0; top--) {
			if (p->val != stack[top])
				return false;
			p = p->next;
		}
	}
	else {
		p = p->next;
		for (--top; p && top >= 0; top--) {
			if (p->val != stack[top])
				return false;
			p = p->next;
		}
	}
	return true;
}