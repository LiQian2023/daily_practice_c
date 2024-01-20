#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.01.20力扣网刷题
//旋转链表——链表、双指针——中等
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
//初始化
void InitList(struct ListNode** L) {
	assert(L);
	*L = NULL;
}
//创建链表——尾插法
bool List_TailInsert(struct ListNode** L) {
	if (!L)
		return false;
	struct ListNode* l = *L, * r = NULL;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		if (!(*L)) {
			*L = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(*L);
			(*L)->next = NULL;
			(*L)->val = x;
			l = *L;
		}
		else {
			r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(r);
			r->val = x;
			r->next = l->next;
			l->next = r;
			l = r;
		}
	}
	getchar();
	return true;
}
struct ListNode* rotateRight(struct ListNode* head, int k) {
	if (!head || !k)
		return head;
	struct ListNode* l = head, * r = head;
	int len = 1;
	while (r->next) {
		r = r->next;
		len++;
	}
	int num = k % len;//得出最终旋转次数
	if (!num)
		return head;
	int i = len - num;//开始旋转的结点位序
	int j = 1;
	while (j < i) {
		l = l->next;//找到对应的结点
		j++;
	}
	struct ListNode* p = l->next;
	r->next = head;
	l->next = NULL;
	head = p;
	return head;
}
void Print_List(struct ListNode* p) {
	while (p) {
		printf("%d->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}
int main() {
	struct ListNode* L;
	InitList(&L);
	if (List_TailInsert(&L)) {
		int k = 0;
		scanf("%d", &k);
		struct ListNode* p = rotateRight(L, k);
		Print_List(p);
	}
	return 0;
}