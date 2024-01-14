#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.01.14力扣网刷题
//环形链表——哈希表、链表、双指针——简单
//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
//示例 2：
//输入：head = [1, 2], pos = 0
//输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
//示例 3：
//输入：head = [1], pos = -1
//输出：false
//解释：链表中没有环。
//提示：
//链表中节点的数目范围是[0, 10^4]
//- 10^5 <= Node.val <= 10^5
//pos 为 - 1 或者链表中的一个 有效索引 。
//进阶：你能用 O(1)（即，常量）内存解决此问题吗？

struct ListNode {
	int val;
	struct ListNode* next;
};
//初始化
void InitList(struct ListNode** L) {
	assert(L);
	*L = NULL;
}
//建立链表
void List_TailInsert(struct ListNode** L) {
	assert(L);
	int x = 0;
	struct ListNode* l = *L, * r = NULL;
	while (scanf("%d", &x) == 1) {
		if (!l)
		{
			l = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			assert(l);
			l->next = NULL;
			l->val = x;
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
}
struct ListNode* GetElem(struct ListNode* L, int i) {
	assert(L);
	if (i < 0)
		return NULL;
	struct ListNode* p = L;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (j == i) {
		return p;
	}
	else
		return NULL;
}
void ModifyList(struct ListNode** L, struct ListNode* p) {
	assert(L);
	int j = 0;
	struct ListNode* l = p;
	while (l->next) {
		l = l->next;
	}
	l->next = p;
}

bool hasCycle(struct ListNode* head) {
	if (!head)
		return false;
	struct ListNode* p = head;
	while (p && p->val != 100001) {
		p->val = 100001;
		p = p->next;
	}
	if (p) {
		return true;
	}
	else
		return false;
}
int main() {
	struct ListNode* L;
	InitList(&L);
	List_TailInsert(&L);
	int post = 0;
	scanf("%d", &post);
	struct ListNode* p = GetElem(L, post);
	if (p) {
		ModifyList(&L, p);
	}
	else {
		return 0;
	}
	if (hasCycle(L)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
	return 0;
}