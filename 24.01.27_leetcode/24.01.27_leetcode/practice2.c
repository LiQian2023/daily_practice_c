#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.01.27力扣网刷题
//回文链表——栈、递归、链表、双指针——简单
//给定一个链表的 头节点 head ，请判断其是否为回文链表。
//如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
//示例 1：
//输入: head = [1, 2, 3, 3, 2, 1]
//输出 : true
//示例 2：
//输入: head = [1, 2]
//输出 : false
//提示：
//链表 L 的长度范围为[1, 10^5]
//0 <= node.val <= 9
//进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


struct ListNode {
	int val;
	struct ListNode* next;
};
//法一：顺序表
bool isPalindrome1(struct ListNode* head) {
	int arr[1000000] = { 0 };
	int i = 0;
	struct ListNode* p = head;
	for (i = 0; p; i++) {
		arr[i] = p->val;
		p = p->next;
	}
	int l = 0, r = i - 1;
	while (l < r) {
		if (arr[l] != arr[r])
			return false;
		l++, r--;
	}
	return true;
}
//法二：栈
#define MaxSize 50000
typedef struct Stack {
	int data[MaxSize];
	int top;
}Stack;
bool isPalindrome(struct ListNode* head) {
	Stack S = { 0 };
	struct ListNode* p = head;
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	int i = 0;
	p = head;
	if (len % 2 == 0) {
		for (i = 0; i < len / 2; i++) {
			S.data[S.top] = p->val;
			S.top++;
			p = p->next;
		}
		S.top--;
		for (i; i >= 0; i--) {
			if (p->val != S.data[S.top])
				return false;
			p = p->next;
			S.top--;
		}
	}
	else {
		for (i = 0; i < len / 2; i++) {
			S.data[S.top] = p->val;
			S.top++;
			p = p->next;
		}
		S.top--;
		p = p->next;
		for (i; i >= 0; i--) {
			if (p->val != S.data[S.top])
				return false;
			p = p->next;
			S.top--;
		}
	}
	return true;
}
//法三：