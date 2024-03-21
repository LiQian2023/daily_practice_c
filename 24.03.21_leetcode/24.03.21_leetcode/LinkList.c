#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//链表初始化
void ListInit(struct ListNode** L) {
	assert(L);
	(*L) = NULL;
}

//尾插法创建链表
void TailInsert(struct ListNode** L) {
	assert(L);
	struct ListNode* l = *L;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		struct ListNode* p = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		assert(p);
		p->val = x;
		if (l) {
			p->next = l->next;
			l->next = p;
			l = p;
		}
		else {
			*L = p;
			l = *L;
		}
	}
	printf("完成创建\n");
}

//打印链表
void ListPrint(struct ListNode* L) {
	struct ListNode* p = L;
	while (p) {
		printf("%d->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}

//销毁链表
void DestroyList(struct ListNode** L) {
	struct ListNode* p = (*L);
	while (*L) {
		(*L) = (*L)->next;
		free(p);
		p = *L;
	}
	printf("完成销毁\n");
}