#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"


//2024.01.28力扣网刷题
//图书整理 I——栈、递归、链表、双指针——简单
//书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。
//为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。
//示例 1：
//输入：head = [3, 6, 4, 1]
//输出：[1, 4, 6, 3]
//提示：
//0 <= 链表长度 <= 10000

struct ListNode {
    int val;
    struct ListNode* next;
};

//法一：动态顺序表
int* reverseBookList1(struct ListNode* head, int* returnSize) {
    int len = 0;
    struct ListNode* p = head;
    while (p) {
        len++;
        p = p->next;
    }
    p = head;
    int* ans = (int*)calloc(len, sizeof(int));
    if (!ans)
        return NULL;
    for (int i = len - 1; i >= 0; i--) {
        ans[i] = p->val;
        p = p->next;
    }
    *returnSize = len;
    return ans;
}
//法二:静态顺序表
int* reverseBookList1(struct ListNode* head, int* returnSize) {
    int* ans = (int*)calloc(10000, sizeof(int));
    if (!ans)
        return NULL;
    struct ListNode* p = head;
    int i = 0;
    for (i = 0; p; i++) {
        ans[i] = p->val;
        p = p->next;
    }
    int l = 0, r = i - 1;
    while (l < r) {
        int tmp = ans[l];
        ans[l] = ans[r];
        ans[r] = tmp;
        l++;
        r--;
    }
    *returnSize = i;
    return ans;
}