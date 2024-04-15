#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

void InitList(struct ListNode** L) {
	assert(L);
	*L = NULL;//不带头结点
}

void TailInsert(struct ListNode** L) {
	assert(L);
	struct ListNode* l = *L;
	int x = 0;
	while (scanf("%d", &x) == 1) {
		struct ListNode* s = (struct ListNode*)calloc(1, sizeof(struct ListNode));
		assert(s);
		s->val = x;
		s->next = NULL;
		if (l == NULL) {
			l = s;
			*L = s;
		}
		else {
			l->next = s;
			l = s;
		}
	}
	getchar();
}

void Destroy(struct ListNode** L) {
	assert(L);
	struct ListNode* p = *L;
	while (p) {
		*L = p->next;
		free(p);
		p = *L;
	}
}

void Print(struct ListNode* L) {
	assert(L);
	struct ListNode* p = L;
	while (p) {
		printf("%d->", p->val);
		p = p->next;
	}
	printf("NULL\n");
}