#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2024.01.12力扣网刷题
//两数相加 II——栈、链表、数学——中等
//给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
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
//进阶：如果输入链表不能翻转该如何解决？


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
//初始化
void InitList(struct ListNode** L) {
    assert(L);
    *L = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    assert(*L);
    (*L)->next = NULL;
}
void List_TailInsert(struct ListNode** L) {
    assert(L);
    struct ListNode* p = *L, * q = NULL;
    int x = 0;
    int len = 0;
    while (scanf("%d", &x) == 1) {
        q = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        assert(q);
        q->next = p->next;
        p->next = q;
        p = q;
        q->val = x;
        len++;
    }
    getchar();
    (*L)->val = len;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if ((!l1) && (!l2))
        return NULL;
    struct ListNode* l3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    if (!l3)
        return NULL;
    l3->next = NULL;
    struct ListNode* l4 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    if (!l4)
        return NULL;
    l3->next = NULL;
    struct ListNode* p1 = l1->next, * p2 = l2->next, * p3 = l3, * q3 = NULL, * p4 = l4, * q4 = NULL;
    //逆置l1
    while (p1) {
        q3 = p1;//指向要插入的结点
        p1 = p1->next;//p1指针指向下一个结点
        //通过头插法进行逆置
        q3->next = p3->next;//将q3指向的结点插入l3中
        p3->next = q3;//q3结点成为新的表头结点
    }
    //逆置l2
    while (p2) {
        q4 = p2;//指向要插入的结点
        p2 = p2->next;//p2指针指向下一个结点
        //通过头插法进行逆置
        q4->next = p4->next;//将q4指向的结点插入l4中
        p4->next = q4;//q4指向的结点成为新的表头结点
    }
    p3 = l3, q3 = p3->next, p4 = l4, q4 = p4->next;
    //相加
    while (q3 && q4) {
        q3->val = q3->val + q4->val;//将l3作为求和链表
        p3 = q3;//前驱结点
        q3 = q3->next;//q3指向后继结点
        q4 = q4->next;//q4指向后继结点
    }
    if (q4) {//l4的链表长度大于l3的链表长度
        p3->next = q4;//将q4及其后继结点插入到l3中
    }
    p4 = l4->next;//找到表头结点
    free(p4);//释放l4中的所有结点空间
    p4 = NULL;//置空，避免出现野指针
    l4->next = p4;//l4链表置为空表
    p3 = l3, q3 = NULL;//回到表头
    //进位
    while (p3) {
        if (p3->next == NULL && p3->val > 9) {
            q3 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
            assert(q3);
            //插入新结点
            q3->next = p3->next;
            p3->next = q3;
        }
        if (p3->val > 9) {
            p3->val %= 10;//取个位
            p3->next->val += 1;//进位
        }
        p3 = p3->next;//找到后继结点
    }
    //逆置l3
    p3 = l3->next, p4 = l4, q4 = NULL;//将链表l4作为返回链表
    while (p3) {
        q4 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        assert(q4);
        //通过头插法逆置
        q4 = p3;//q4指向需要插入的结点
        p3 = p3->next;//p3指向后继结点
        q4->next = p4->next;
        p4->next = q4;
    }
    free(l3);
    return l4;
}

int main() {
    struct ListNode* L1, * L2, * L3 = NULL;
    InitList(&L1);
    InitList(&L2);
    List_TailInsert(&L1);
    List_TailInsert(&L2);
    L3 = addTwoNumbers(L1, L2);
    return 0;
}
