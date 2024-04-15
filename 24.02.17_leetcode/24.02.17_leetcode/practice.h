#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

void InitList(struct ListNode** L);
void TailInsert(struct ListNode** L);
void Destroy(struct ListNode** L);
void Print(struct ListNode* L);
