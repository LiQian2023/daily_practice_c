#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.06.27力扣网刷题
//21. 合并两个有序链表——递归、链表——简单
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
//两个链表的节点数目范围是[0, 50]
//- 100 <= Node.val <= 100
//l1 和 l2 均按 非递减顺序 排列

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode LN;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (!list1) {
		return list2;
	}
	if (!list2) {
		return list1;
	}
	if (list1->val <= list2->val) {
		list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	}
	list2->next = mergeTwoLists(list1, list2->next);
	return list2;
}