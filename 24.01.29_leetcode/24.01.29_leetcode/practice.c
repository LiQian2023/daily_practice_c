#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.01.29力扣网刷题
//训练计划 II——链表、双指针——简单
//给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第 cnt 个训练项目编号。
//示例 1：
//输入：head = [2, 4, 7, 8], cnt = 1
//输出：8
//提示：
//1 <= head.length <= 100
//0 <= head[i] <= 100
//1 <= cnt <= head.length


//法一：按位查找
struct ListNode* trainingPlan1(struct ListNode* head, int cnt) {
    int len = 0;
    struct ListNode* p = head;
    while (p) {
        len++;
        p = p->next;
    }
    int i = len - cnt + 1;
    int j = 1;
    p = head;
    while (j < i) {
        p = p->next;
        j++;
    }
    return p;
}
//法二：双指针
struct ListNode* trainingPlan(struct ListNode* head, int cnt) {
    struct ListNode* f = head, * l = head;
    for (cnt; cnt > 0; cnt--) {
        f = f->next;
    }
    while (f) {
        f = f->next;
        l = l->next;
    }
    return l;
}
