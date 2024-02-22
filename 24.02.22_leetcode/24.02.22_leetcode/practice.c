#define _CRT_SECURE_NO_WARNINGS 1


#include "practice.h"


//2024.02.22力扣网刷题
//环路检测——哈希表、链表、双指针——中等
//给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。若环不存在，请返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
//示例 2：
//输入：head = [1, 2], pos = 0
//输出：tail connects to node index 0
//解释：链表中有一个环，其尾部连接到第一个节点。
//示例 3：
//输入：head = [1], pos = -1
//输出：no cycle
//解释：链表中没有环。
//进阶：
//你是否可以不用额外空间解决此题？

struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* f = head, * s = head;
	while (f && f->next) {
		f = f->next->next;
		s = s->next;
		if (f == s)
			break;
	}
	if (!f || !f->next) {
		return NULL;
	}
	struct ListNode* str = head;
	while (str != f) {
		str = str->next;
		f = f->next;
	}
	return f;
}