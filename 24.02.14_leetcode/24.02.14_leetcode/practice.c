#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.14力扣网刷题
//从链表中移除节点——栈、递归、链表、单调栈——中等
//给你一个链表的头节点 head 。
//移除每个右侧有一个更大数值的节点。
//返回修改后链表的头节点 head 。
//示例 1：
//输入：head = [5, 2, 13, 3, 8]
//输出：[13, 8]
//解释：需要移除的节点是 5 ，2 和 3 。
//- 节点 13 在节点 5 右侧。
//- 节点 13 在节点 2 右侧。
//- 节点 8 在节点 3 右侧。
//示例 2：
//输入：head = [1, 1, 1, 1]
//输出：[1, 1, 1, 1]
//解释：每个节点的值都是 1 ，所以没有需要移除的节点。
//提示：
//给定列表中的节点数目在范围[1, 10^5] 内
//1 <= Node.val <= 10^5

//链栈
struct ListNode* removeNodes(struct ListNode* head) {
	struct ListNode* Stack = NULL;
	struct ListNode* p = head;
	while (head) {
		if (!Stack) {
			//栈为空栈时进行入栈
			p = head;
			head = head->next;
			p->next = Stack;
			Stack = p;
		}
		else {
			//栈为非空时进行判断
			if (head->val > Stack->val) {
				//待入栈元素的数值大于栈顶，进行出栈操作
				p = Stack;
				Stack = Stack->next;
				free(p);
			}
			else {
				//待入栈元素的数组小于等于栈顶，进行入栈操作
				p = head;
				head = head->next;
				p->next = Stack;
				Stack = p;
			}
		}
	}
	while (Stack) {
		p = Stack;
		Stack = Stack->next;
		p->next = head;
		head = p;
	}
	return head;
}