#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.02.17力扣网刷题
//两数相加 II——栈、链表、数学——中等
// 2024.04.16完成解题——解题方法——法一：新链表、法二：顺序表
//给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//可以假设除了数字 0 之外，这两个数字都不会以零开头。
//示例1：
//输入：l1 = [7, 2, 4, 3], l2 = [5, 6, 4]
//输出：[7, 8, 0, 7]
//示例2：
//输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
//输出：[8, 0, 7]
//示例3：
//输入：l1 = [0], l2 = [0]
//输出：[0]
//提示：
//链表的长度范围为[1, 100]
//0 <= node.val <= 9
//输入数据保证链表代表的数字无前导 0
//进
#if 0
struct ListNode* addTwoNumbers0(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* S1 = NULL, * S2 = NULL, * p1 = l1, * p2 = l2;
	//入栈
	while (p1) {
		l1 = l1->next;
		p1->next = S1;
		S1 = p1;
		p1 = l1;
	}
	while (p2) {
		l2 = l2->next;
		p2->next = S2;
		S2 = p2;
		p2 = l2;
	}
	//相加
	struct ListNode* l3 = NULL;
	while (S1 && S2) {
		l1 = S1;
		S1 = S1->next;
		l2 = S2;
		S2 = S2->next;
		l1->val += l2->val;
		if (l1->val > 9) {
			l1->val %= 10;
			if (!S1)
			{
				S1 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
				S1->next = NULL;
			}
			S1->val += 1;
		}
		l1->next = l3;
		l3 = l1;
	}
	while (S1) {
		p1 = S1;
		S1 = S1->next;
		p1->next = l3;
		l3 = p1;
	}
	while (S2) {
		p2 = S2;
		S2 = S2->next;
		p2->next = l3;
		l3 = p2;
	}
	return l3;
}

//方法一：翻转链表
void reverseList(struct ListNode** L, int* len) {
	struct ListNode* l = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	if (!l)
		return;
	l->next = NULL;
	struct ListNode* p = *L;
	while (p) {
		(*len)++;
		*L = (*L)->next;
		p->next = l->next;
		l->next = p;
		p = *L;
	}
	*L = l->next;
	free(l);
}

struct ListNode* Add(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p = l1, * q = l2;
	while (p && q) {
		p->val += q->val;
		if (p->val > 9) {
			p->val %= 10;
			if (p->next == NULL) {
				struct ListNode* s = (struct ListNode*)calloc(1, sizeof(struct ListNode));
				if (!s)
					return NULL;
				s->next = NULL;
				p->next = s;
			}
			p->next->val += 1;
		}
		p = p->next;
		q = q->next;
	}
	while (p) {
		if (p->val > 9) {
			p->val %= 10;
			if (p->next == NULL) {
				struct ListNode* s = (struct ListNode*)calloc(1, sizeof(struct ListNode));
				if (!s)
					return NULL;
				s->next = NULL;
				p->next = s;
			}
			p->next->val += 1;
		}
		p = p->next;
	}
	return l1;
}

struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2){
	//翻转链表
	int len1 = 0, len2 = 0;
	reverseList(&l1, &len1);
	Print(l1);
	reverseList(&l2, &len2);
	Print(l2);
	//相加
	struct ListNode* max = (len1 > len2 ? l1 : l2);
	struct ListNode* min = (len1 > len2 ? l2 : l1);
	struct LitNode* ans = Add(max, min);
	int len3 = 0;
	reverseList(&ans, &len3);
	return ans;
}

//方法二：顺序表
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
	int len1 = 0, len2 = 0;
	struct ListNode* p = l1;
	while (p) {
		len1++;
		p = p->next;
	}
	p = l2;
	while (p) {
		len2++;
		p = p->next;
	}
	int size1 = len1 > len2 ? len1 + 1 : len2 + 1;
	int size2 = len1 > len2 ? len2 : len1;
	struct ListNode* max = len1 > len2 ? l1 : l2;
	struct ListNode* min = len1 > len2 ? l2 : l1;
	int* num1 = (int*)calloc(size1, sizeof(int));
	if (!num1)
		return NULL;
	p = max;
	for (int i = size1 - 2; i >= 0; i--) {
		num1[i] = p->val;
		p = p->next;
	}
	int* num2 = (int*)calloc(size1, sizeof(int));
	if (!num2)
		return NULL;
	p = min;
	for (int i = size2 - 1; i >= 0; i--) {
		num2[i] = p->val;
		p = p->next;
	}
	for (int i = 0; i < size1; i++) {
		num1[i] += num2[i];
		if (num1[i] > 9) {
			num1[i] %= 10;
			num1[i + 1] += 1;
		}
	}
	struct ListNode* l3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	if (!l3)
		return NULL;
	for (int i = 0; i < size1; i++) {
		p = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		if (!p)
			return NULL;
		p->next = l3->next;
		l3->next = p;
		p->val = num1[i];
	}
	p = l3->next;
	free(l3);//释放头结点
	free(num1);
	free(num2);
	l3 = p;
	p = l3->next;
	if (l3->val == 0) {
		free(l3);
		l3 = p;
	}
	return l3;
}
#endif

void test() {
	struct ListNode* l1, * l2;
	int x1 = 0, x2 = 0;
	InitList(&l1);
	TailInsert(&l1);
	InitList(&l2);
	TailInsert(&l2);
	Print(l1);
	Print(l2);
	struct ListNode* ret = addTwoNumbers2(l1, l2);
	Print(ret);
	Destroy(&l1);
	Destroy(&l2);
}

int main() {
	test();
	return 0;
}