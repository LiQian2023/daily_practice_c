#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2024.01.26力扣网刷题
//相交链表——哈希表、链表、双指针——简单
//给定两个单链表的头节点 headA 和 headB ，请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
//图示两个链表在节点 c1 开始相交：
//题目数据 保证 整个链式结构中不存在环。
//注意，函数返回结果后，链表必须 保持其原始结构 。
//示例 1：
//输入：intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 0, 1, 8, 4, 5], skipA = 2, skipB = 3
//输出：Intersected at '8'
//解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
//从各自的表头开始算起，链表 A 为[4, 1, 8, 4, 5]，链表 B 为[5, 0, 1, 8, 4, 5]。
//在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
//示例 2：
//输入：intersectVal = 2, listA = [0, 9, 1, 2, 4], listB = [3, 2, 4], skipA = 3, skipB = 1
//输出：Intersected at '2'
//解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
//从各自的表头开始算起，链表 A 为[0, 9, 1, 2, 4]，链表 B 为[3, 2, 4]。
//在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
//示例 3：
//输入：intersectVal = 0, listA = [2, 6, 4], listB = [1, 5], skipA = 3, skipB = 2
//输出：null
//解释：从各自的表头开始算起，链表 A 为[2, 6, 4]，链表 B 为[1, 5]。
//由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
//这两个链表不相交，因此返回 null 。
//提示：
//listA 中节点数目为 m
//listB 中节点数目为 n
//0 <= m, n <= 3 * 10^4
//1 <= Node.val <= 10^5
//0 <= skipA <= m
//0 <= skipB <= n
//如果 listA 和 listB 没有交点，intersectVal 为 0
//如果 listA 和 listB 有交点，intersectVal == listA[skipA + 1] == listB[skipB + 1]
//进阶：能否设计一个时间复杂度 O(n) 、仅用 O(1) 内存的解决方案？

struct ListNode {
    int val;
    struct ListNode* next;
};
void InitList(struct ListNode** L) {
    assert(L);
    *L = NULL;
}
bool List_TailInsert(struct ListNode** L) {
    if (!L)
        return false;
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
            l->next = r->next;
            l = r;
        }
    }
    return true;
}
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if ((!headA) && (!headB))
        return NULL;
    int len1 = 0, len2 = 0;
    struct ListNode* pa = headA, * pb = headB;
    while (pa) {
        len1++;
        pa = pa->next;
    }
    while (pb) {
        len2++;
        pb = pb->next;
    }
    pa = headA, pb = headB;
    int tmp = len1 - len2;
    if (tmp > 0) {
        while (tmp--) {
            pa = pa->next;
        }
    }
    else if (tmp < 0) {
        while (tmp++) {
            pb = pb->next;
        }
    }
    while (len2--) {
        if (pa == pb)
            break;
        pa = pa->next;
        pb = pb->next;
    }
    if ((!pa) || (!pb)) {
        return NULL;
    }
    return pa;
}

void Print_List(struct ListNode* L) {
    while (L) {
        printf("%d->", L->val);
        L = L->next;
    }
}
