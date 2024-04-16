#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"


//2024.03.21力扣网刷题
// 排序链表——链表、双指针、分治、排序、归并排序——中等
// 2024.04.17完成解题——解题方法：顺序表
//给定链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
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

//冒泡排序(更改结点数据）
struct ListNode* sortList1(struct ListNode* head) {
	assert(head);
	struct ListNode* l = head, * f = NULL;
	int len = 0;
	while (l) {
		len++;
		l = l->next;
	}
	for (int i = 0; i < len - 1; i++) {
		int flag = 1;
		if (head && head->next) {
			l = head;
			f = head->next;
		}
		else {
			break;
		}
		for (int j = 0; j < len - i - 1; j++) {
			if (l->val > f->val) {
				int tmp = l->val;
				l->val = f->val;
				f->val = tmp;
				flag = 0;
			}
			l = f;
			f = f->next;
		}
		if (flag)
			break;
	}
	return head;
}

//冒泡排序(移动结点）
struct ListNode* sortList1(struct ListNode* head) {
	assert(head);
	struct ListNode* l = head, * f = NULL;
	int len = 0;
	while (l) {
		len++;
		l = l->next;
	}
	struct ListNode* p = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	assert(p);
	p->next = head;
	head = p;
	while (head->next && head->next->next) {
		int flag = 1;
		p = head, l = head->next, f = head->next->next;
		while (l && f) {
			if (l->val > f->val) {
				l->next = f->next;
				f->next = p->next;
				p->next = f;
				flag = 0;
			}
			p = l;
			l = p->next;
			if (l)
				f = l->next;
		}
		if (flag) {
			break;
		}
	}
	p = head;
	head = head->next;
	free(p);
	return head;
}

//顺序表
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
struct ListNode* sortList(struct ListNode* head) {
	int num[50000] = { 0 };
	struct ListNode* p = head;
	int i = 0;
	while (p) {
		num[i++] = p->val;
		p = p->next;
	}
	qsort(num, i, sizeof(int), cmp);
	p = head;
	for (int j = 0; j < i; j++) {
		p->val = num[j];
		p = p->next;
	}
	return head;
}



void test1() {
	struct ListNode* L;
	ListInit(&L);
	TailInsert(&L);
	ListPrint(L);
	struct ListNode* p = sortList(L);
	ListPrint(p);
	DestroyList(&p);
	DestroyList(&L);
}




//顺序表的遍历输出
void test() {
	SqList L;
	InitList(&L);//对顺序表进行初始化
	int i = 0;//需要插入的位序
	Elemtype e = 0;//需要插入的元素
	while (scanf("%d%d", &i, &e) == 2)//通过多组输入来插入元素
	{
		if (ListInsert(&L, i, e))
			PrintList(L);
		else {
			printf("插入失败\n");
			break;
		}
	}
}

int main() {
	test1();
	return 0;
}