#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
//2024.01.25力扣网刷题
//二进制链表转整数——链表、数学——简单
//给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。
//请你返回该链表所表示数字的 十进制值 。
//示例 1：
//输入：head = [1, 0, 1]
//输出：5
//解释：二进制数(101) 转化为十进制数(5)
//示例 2：
//输入：head = [0]
//输出：0
//示例 3：
//输入：head = [1]
//输出：1
//示例 4：
//输入：head = [1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0]
//输出：18880
//示例 5：
//输入：head = [0, 0]
//输出：0
//提示：
//链表不为空。
//链表的结点总数不超过 30。
//每个结点的值不是 0 就是 1。

struct ListNode {
    int val;
    struct ListNode* next;
};
void InitList(struct ListNode** L) {
    assert(L);
    *L = NULL;
}
bool List_TailInsert(struct ListNode** L) {
    assert(L);
    struct ListNode* l = *L, * r = NULL;
    int x = 0;
    while (scanf("%d", &x) == 1) {
        if (!l) {
            l = (struct ListNode*)calloc(1, sizeof(struct ListNode));
            if (!l)
                return false;
            l->val = x;
            l->next = NULL;
            *L = l;
        }
        else {
            r = (struct ListNode*)calloc(1, sizeof(struct ListNode));
            if (!r)
                return false;
            r->val = x;
            r->next = l->next;
            l->next = r;
            l = r;
        }
    }
    return true;
}
int getDecimalValue(struct ListNode* head) {
    int arr[30] = { 0 };
    int i = 0;
    for (i = 0; i < 30; i++) {
        if (!head)
            break;
        arr[i] = head->val;
        head = head->next;
    }
    int sum = 0;
    for (int j = 0; j < i; j++) {
        sum += arr[j] * pow(2, i - 1 - j);;
    }
    return sum;
}

int main() {
    struct ListNode* L = { 0 };
    InitList(&L);
    if (List_TailInsert(&L)) {
        getDecimalValue(L);
    }
    return 0;
}