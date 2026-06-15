#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.06.15力扣网刷题
//2095. 删除链表的中间节点——高级工程师、链表、双指针、第270场周赛——中等
//给你一个链表的头节点 head 。删除 链表的 中间节点 ，并返回修改后的链表的头节点 head 。
//长度为 n 链表的中间节点是从头数起第 ⌊n / 2⌋ 个节点（下标从 0 开始），其中 ⌊x⌋ 表示小于或等于 x 的最大整数。
//对于 n = 1、2、3、4 和 5 的情况，中间节点的下标分别是 0、1、1、2 和 2 。
//示例 1：
//输入：head = [1, 3, 4, 7, 1, 2, 6]
//输出：[1, 3, 4, 1, 2, 6]
//解释：
//上图表示给出的链表。节点的下标分别标注在每个节点的下方。
//由于 n = 7 ，值为 7 的节点 3 是中间节点，用红色标注。
//返回结果为移除节点后的新链表。
//示例 2：
//输入：head = [1, 2, 3, 4]
//输出：[1, 2, 4]
//解释：
//上图表示给出的链表。
//对于 n = 4 ，值为 3 的节点 2 是中间节点，用红色标注。
//示例 3：
//输入：head = [2, 1]
//输出：[2]
//解释：
//上图表示给出的链表。
//对于 n = 2 ，值为 1 的节点 1 是中间节点，用红色标注。
//值为 2 的节点 0 是移除节点 1 后剩下的唯一一个节点。
//提示：
//链表中节点的数目在范围[1, 10^5] 内
//1 <= Node.val <= 10^5

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode LN;
int getSize(LN* head) {
	int n = 0;
	LN* p = head;
	while (p) {
		n += 1;
		p = p->next;
	}
	return n;
}
void Delete(LN* head, int index) {
	LN* p = head;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}
	LN* node = p->next;
	p->next = node->next;
	node->next = NULL;
	free(node);
}
struct ListNode* deleteMiddle1(struct ListNode* head) {
	int size = getSize(head);
	Delete(head, size / 2 - 1);
	return head;
}

struct ListNode* deleteMiddle(struct ListNode* head) {
	if (!(head->next)) {
		return NULL;
	}
	LN* pre = NULL, * slow = head, * fast = head;
	while (fast && fast->next) {
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = slow->next;
	slow->next = NULL;
	return head;
}