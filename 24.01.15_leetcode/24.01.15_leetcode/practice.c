#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.01.15力扣网刷题
//删除排序链表中的重复元素 II——链表、双指针——中等
//给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
//示例 1：
//输入：head = [1, 2, 3, 3, 4, 4, 5]
//输出：[1, 2, 5]
//示例 2：
//输入：head = [1, 1, 1, 2, 3]
//输出：[2, 3]
//提示：
//链表中节点数目在范围[0, 300] 内
//- 100 <= Node.val <= 100
//题目数据保证链表已经按升序 排列
struct ListNode {
	int val;
	struct ListNode* next;
};
void InitList(struct ListNode** L) {
	assert(L);
	*L = NULL;
}
void List_TailInsert(struct ListNode** L) {
	assert(L);
	struct ListNode* l = *L, * r = NULL;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		if (!l) {
			*L = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(*L);
			(*L)->next = NULL;
			(*L)->val = x;
			l = *L;
		}
		else {
			r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(r);
			r -> val = x;
			r->next = l->next;
			l->next = r;
			l = r;
		}
	}
}
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head)
		return NULL;
	struct ListNode* l = head, * r = NULL, * p = head;
	int flag = 0, x = 0;
	while (l->next) {
		r = l->next;
		if (r->val == l->val) {
			x = l->val;
			l->next = r->next;
			r->next = NULL;
			free(r);
			r = NULL;
			flag = 1;
		}
		else {
			if (flag) {
				l->val = r->val;
				l->next = r->next;
				r->next = NULL;
				free(r);
				r = NULL;
				flag--;
			}
			else {
				p = l;
				l = r;
			}
		}
	}
	if (l->val == x) {
		p->next = l->next;
		//free(l);
		l = NULL;
	}
	if (head->val == x && flag) {
		head = NULL;
	}
	return head;
}

int main() {
	struct ListNode* L;
	InitList(&L);
	List_TailInsert(&L);
	struct ListNode* p = deleteDuplicates(L);

	return 0;
}