#define _CRT_SECURE_NO_WARNINGS 1
#include "practice.h"

//2024.02.13力扣网刷题
//排序链表——链表、双指针、分治、排序、归并排序——中等
//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//示例 1：
//输入：head = [4, 2, 1, 3]
//输出：[1, 2, 3, 4]
//示例 2：
//输入：head = [-1, 5, 3, 4, 0]
//输出：[-1, 0, 3, 4, 5]
//示例 3：
//输入：head = []
//输出：[]
//提示：
//链表中节点的数目在范围[0, 5 * 10^4] 内
//- 10^5 <= Node.val <= 10^5
//进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}

struct ListNode* sortList(struct ListNode* head) {
	int arr[50000] = { 0 };
	struct ListNode* p = head;
	int i = 0;
	while (p) {
		arr[i] = p->val;
		i++;
		p = p->next;
	}
	qsort(arr, i, 4, cmp);
	p = head;
	i = 0;
	while (p) {
		p->val = arr[i];
		p = p->next;
		i++;
	}
	return head;
}