#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2024.01.13力扣网刷题
//删除排序链表中的重复元素——链表——简单
//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
//示例 1：
//输入：head = [1, 1, 2]
//输出：[1, 2]
//示例 2：
//输入：head = [1, 1, 2, 3, 3]
//输出：[1, 2, 3]
//提示：
//链表中节点数目在范围[0, 300] 内
//- 100 <= Node.val <= 100
//题目数据保证链表已经按升序 排列

struct ListNode {
	int val;
	struct ListNode* next;
};
//初始化链表
void InitList(struct ListNode** L) {
	assert(L);
	*L = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	assert(*L);
	(*L)->next = NULL;
}
//尾插法创建链表
void List_TailInsert(struct ListNode** L) {
	assert(L);
	struct ListNode* l = *L, * r = NULL;
	int x = 0, len = 0;
	while (scanf("%d", &x) == 1) {
		r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		assert(r);
		r->next = l->next;
		l->next = r;
		l = r;
		r->val = x;
		len++;
	}
	(*L)->val = len;
}
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head)
		return NULL;
	struct ListNode* p = head, * q = p->next;
	while (q) {
		if (p->val == q->val) {
			//后删
			p->next = q->next;
			q->next = NULL;
			free(q);
			q = p->next;
		}
		else {
			p = q;
			q = p->next;
		}
	}
	return head;
}
int main() {
	struct ListNode* L;
	InitList(&L);
	List_TailInsert(&L);
	struct ListNode* ret = deleteDuplicates(L);
	return 0;
}