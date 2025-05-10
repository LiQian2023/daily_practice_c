#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.10力扣网刷题
//计算子数组的 x - sum I——数组、哈希表、滑动窗口、堆——简单
//给你一个由 n 个整数组成的数组 nums，以及两个整数 k 和 x。
//数组的 x - sum 计算按照以下步骤进行：
//统计数组中所有元素的出现次数。
//仅保留出现次数最多的前 x 个元素的每次出现。如果两个元素的出现次数相同，则数值 较大 的元素被认为出现次数更多。
//计算结果数组的和。
//注意，如果数组中的不同元素少于 x 个，则其 x - sum 是数组的元素总和。
//返回一个长度为 n - k + 1 的整数数组 answer，其中 answer[i] 是 子数组 nums[i..i + k - 1] 的 x - sum。
//子数组 是数组内的一个连续 非空 的元素序列。
//示例 1：
//输入：nums = [1, 1, 2, 2, 3, 4, 2, 3], k = 6, x = 2
//输出：[6, 10, 12]
//解释：
//对于子数组[1, 1, 2, 2, 3, 4]，只保留元素 1 和 2。因此，answer[0] = 1 + 1 + 2 + 2。
//对于子数组[1, 2, 2, 3, 4, 2]，只保留元素 2 和 4。因此，answer[1] = 2 + 2 + 2 + 4。注意 4 被保留是因为其数值大于出现其他出现次数相同的元素（3 和 1）。
//对于子数组[2, 2, 3, 4, 2, 3]，只保留元素 2 和 3。因此，answer[2] = 2 + 2 + 2 + 3 + 3。
//示例 2：
//输入：nums = [3, 8, 7, 8, 7, 5], k = 2, x = 2
//输出：[11, 15, 15, 15, 12]
//解释：
//由于 k == x，answer[i] 等于子数组 nums[i..i + k - 1] 的总和。
//提示：
//1 <= n == nums.length <= 50
//1 <= nums[i] <= 50
//1 <= x <= k <= nums.length

// 元素结点
typedef struct LinkNode {
	int val;				// 元素值
	struct LinkNode* next;	// 结点指针
}LNode;
// 频率结点
typedef struct CountNode {
	int n;					// 结点个数
	LNode* l;				// 元素链表
}CNode;
// 初始化频率表
void Initial(CNode** count) {
	for (int i = 0; i < 51; i++) {
		// 申请头结点
		(*count)[i].l = (LNode*)calloc(1, sizeof(LNode));
		assert((*count)[i].l);
		(*count)[i].l->val = 0;
		(*count)[i].l->next = NULL;
	}
}
void Destroy(CNode** count) {
	for (int i = 0; i < 51; i++) {
		LNode* head = (*count)[i].l;
		while ((*count)[i].n) {
			LNode* p = head->next;
			head->next = p->next;
			p->next = NULL;
			free(p);
			p = head->next;
			(*count)[i].n -= 1;
		}
		free(head);
		head = NULL;
		(*count)[i].l = head;
	}
	free(*count);
	*count = NULL;
}

void Count_Record(CNode* count, int begin, int end, int* hash) {
	for (int i = begin; i <= end; i++) {
		int key = hash[i];
		// 结点数量+1
		count[key].n += 1;
		LNode* q = count[key].l;
		LNode* p = q->next;
		while (p && p->val > i) {
			q = p;
			p = p->next;
		}
		// 后插
		p = (LNode*)calloc(1, sizeof(LNode));
		assert(p);
		p->val = i;
		p->next = q->next;
		q->next = p;
	}
}
void Get_Ans(CNode* count, int max_count, int* ans, int* returnSize, int k, int x) {
	int n1 = 0, n2 = 0;
	// 获取值
	for (int i = max_count; i > 0 && n1 < k && n2 < x; i--) {
		LNode* p = count[i].l->next;
		while (p && n1 < k && n2 < x) {
			ans[*returnSize] += p->val * i;
			n1 += i;
			n2 += 1;
			// 后删
			count[i].l->next = p->next;
			p->next = NULL;
			count[i].n -= 1;
			free(p);
			p = count[i].l->next;
		}
	}
	// 清空频率表
	for (int i = max_count; i > 0; i--) {
		LNode* head = count[i].l;
		while (count[i].n) {
			LNode* p = head->next;
			if (p) {
				head->next = p->next;
				p->next = NULL;
				free(p);
				p = NULL;
				count[i].n -= 1;
			}
		}
	}
}
void Boundary_Record(int* hash, int key, int* begin, int* end, int* max_count) {
	if (key < *begin) {
		*begin = key;
	}
	else if (key > *end) {
		*end = key;
	}
	if (hash[key] > *max_count) {
		*max_count = hash[key];
	}
}
int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
	int* ans = (int*)calloc(numsSize - k + 1, sizeof(int));
	assert(ans);
	*returnSize = 0;
	// 哈希表
	int* hash = (int*)calloc(51, sizeof(int));
	assert(hash);
	// 频率表
	CNode* count = (CNode*)calloc(51, sizeof(CNode));
	assert(count);
	Initial(&count);
	// 最大频率
	int max_count = 0;
	// 元素范围
	int begin = nums[0], end = nums[0];
	// 滑动窗口
	int i = 0, j = 0;
	for (; i < numsSize - k + 1 && j < numsSize; j++) {
		int key = nums[j];
		if (j < i + k) {
			hash[key] += 1;
		}
		else if (j == i + k) {
			// 频率记录
			Count_Record(count, begin, end, hash);
			// 答案获取
			Get_Ans(count, max_count, ans, returnSize, k, x);
			*returnSize += 1;
			// 哈希记录
			int del = nums[i];
			hash[del] -= 1;
			hash[key] += 1;
			// 窗口起始点移动
			i += 1;
		}
		// 边界记录
		Boundary_Record(hash, key, &begin, &end, &max_count);
	}
	// 频率记录
	Count_Record(count, begin, end, hash);
	// 答案获取
	Get_Ans(count, max_count, ans, returnSize, k, x);
	*returnSize += 1;
	free(hash);
	hash = NULL;
	Destroy(&count);
	return ans;
}