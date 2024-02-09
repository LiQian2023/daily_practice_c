#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.09力扣网刷题
//合并两个链表——链表——中等
//给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
//请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。
//下图中蓝色边和节点展示了操作后的结果：
//请你返回结果链表的头指针。
//示例 1：
//输入：list1 = [0, 1, 2, 3, 4, 5], a = 3, b = 4, list2 = [1000000, 1000001, 1000002]
//输出：[0, 1, 2, 1000000, 1000001, 1000002, 5]
//解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
//示例 2：
//输入：list1 = [0, 1, 2, 3, 4, 5, 6], a = 2, b = 5, list2 = [1000000, 1000001, 1000002, 1000003, 1000004]
//输出：[0, 1, 1000000, 1000001, 1000002, 1000003, 1000004, 6]
//解释：上图中蓝色的边和节点为答案链表。
//提示：
//3 <= list1.length <= 10^4
//1 <= a <= b < list1.length - 1
//	1 <= list2.length <= 10^4

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
	struct ListNode* p1 = list1;
	int i = 0;
	//找到下标为a的前驱结点
	while (i < a - 1) {
		p1 = p1->next;
		i++;
	}
	struct ListNode* p2 = p1->next, * q = p1->next;
	//找到下标为b的结点
	while (p2 && i < b) {
		p2 = p2->next;
		i++;
	}
	i++;//i=a
	struct ListNode* p3 = list2;
	//找到list2的尾结点
	while (p3->next) {
		p3 = p3->next;
	}
	//插入链表
	p1->next = list2;
	p3->next = p2->next;
	//释放删除链表所占内存空间
	p2->next = NULL;
	free(p2);
	while (q) {
		p2 = q;
		q = q->next;
		free(p2);
	}
	return list1;
}