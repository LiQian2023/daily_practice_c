#define _CRT_SECURE_NO_WARNINGS 1

#include "practice.h"

//2024.01.31力扣网刷题
//移除重复节点——哈希表、链表、双指针——简单
//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
//示例1:
//输入：[1, 2, 3, 3, 2, 1]
//输出：[1, 2, 3]
//示例2 :
//	输入：[1, 1, 1, 1, 2]
//	输出：[1, 2]
//	提示：
//	链表长度在[0, 20000]范围内。
//	链表元素在[0, 20000]范围内。
//	进阶：
//	如果不得使用临时缓冲区，该怎么解决？

struct ListNode* removeDuplicateNodes(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode* p = head, * q = head->next, * l = NULL;
	int len = 1;//记录当前排查结点位序
	while (p && q) {
		l = head;
		int flag = 1;//删除结点标志
		for (int i = 0; i < len; i++) {
			if (l->val == q->val) {
				p->next = q->next;
				free(q);
				q = p->next;
				flag = 0;//删除完结点后退出循环
				break;
			}
			else {
				l = l->next;
			}
		}
		if (flag)//没有删除结点
		{
			p = p->next;//排查下一个结点
			q = p->next;//下一个结点的后继结点
			len++;//记录排查结点的位序
		}
	}
	return head;
}