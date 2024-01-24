#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.01.24力扣网刷题
//回文链表——栈、递归、链表、双指针——简单
//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
//示例 1：
//输入：head = [1, 2, 2, 1]
//输出：true
//示例 2：
//输入：head = [1, 2]
//输出：false
//提示：
//链表中节点数目在范围[1, 10^5] 内
//0 <= Node.val <= 9
//进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


 //Definition for singly-linked list.
 struct ListNode {
      int val;
      struct ListNode *next;
 };
 void InitList(struct ListNode** L) {
     assert(L);
     *L = NULL;
 }
 bool List_TailInsert(struct List** L) {
     assert(L);
     struct ListNode* l = *L,* r = NULL;
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
     getchar();
     return true;
 }
bool isPalindrome(struct ListNode* head) {
    if (!head)
        return false;
    struct ListNode* p = head;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    int* arr = (int*)calloc(len, sizeof(int));
    if (!arr)
        return false;
    p = head;
    for (int i = 0; p; i++) {
        arr[i] = p->val;
        p = p->next;
    }
    //二分查找
    int l = 0, r = len - 1;
    while (l < r) {
        if (arr[l] != arr[r])
            return false;
        l++, r--;
    }
    free(arr);
    return true;
}

int main() {
    struct ListNode* L;
    InitList(&L);
    if (List_TailInsert(&L)) {
        if (isPalindrome(L)) {
            printf("true\n");
        }
        else
            printf("false\n");
    }
    free(L);
    return 0;
}