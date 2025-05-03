#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.03力扣网刷题
//数组中的最大数对和——数组、哈希表——简单
//给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。
//返回最大和，如果不存在满足题意的数字对，返回 - 1 。
//示例 1：
//输入：nums = [51, 71, 17, 24, 42]
//输出：88
//解释：
//i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。
//i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
//可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。
//示例 2：
//输入：nums = [1, 2, 3, 4]
//输出： - 1
//解释：不存在数对满足数位上最大的数字相等。
//提示：
//2 <= nums.length <= 100
//1 <= nums[i] <= 10^4

typedef struct HashNode {
	int value;
	struct HashNode* next;
}HashNode;
typedef struct Hash {
	int n;
	HashNode* head;
}Hash;
Hash* CreatHash() {
	Hash* h = (Hash*)calloc(10, sizeof(Hash));
	assert(h);
	for (int i = 0; i < 10; i++) {
		h[i].n = 0;
		h[i].head = (HashNode*)calloc(1, sizeof(HashNode));
		assert(h[i].head);
	}
	return h;
}
int Get_Key(int num) {
	int max = num % 10;
	while (num) {
		if (num % 10 > max) {
			max = num % 10;
		}
		num /= 10;
	}
	return max;
}
void HashRecord(Hash* h, int value, int key) {
	h[key].n += 1;
	HashNode* q = h[key].head;
	HashNode* p = q->next;
	while (p && p->value > value) {
		q = p;
		p = p->next;
	}
	p = (HashNode*)calloc(1, sizeof(HashNode));
	assert(p);
	p->value = value;
	p->next = q->next;
	q->next = p;
}
void Destroy(Hash** h) {
	for (int i = 0; i < 10; i++) {
		HashNode* head = (*h)[i].head;
		while ((*h)[i].n) {
			HashNode* p = head->next;
			head->next = p->next;
			p->next = NULL;
			free(p);
			p = NULL;
			(*h)[i].n -= 1;
		}
		free(head);
		head = NULL;
		(*h)[i].head = NULL;
	}
	free(*h);
	*h = NULL;
}
int maxSum(int* nums, int numsSize) {
	Hash* h = CreatHash();
	for (int i = 0; i < numsSize; i++) {
		int key = Get_Key(nums[i]);
		HashRecord(h, nums[i], key);
	}
	int ans = -1;
	for (int i = 0; i < 10; i++) {
		if (h[i].n > 1) {
			HashNode* p1 = h[i].head->next;
			HashNode* p2 = p1->next;
			int tmp = p1->value + p2->value;
			if (tmp > ans) {
				ans = tmp;
			}
		}
	}
	Destroy(&h);
	return ans;
}