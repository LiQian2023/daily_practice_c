#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.04.30力扣网刷题
//和相等的子数组——数组、哈希表——简单
//给你一个下标从 0 开始的整数数组 nums ，判断是否存在 两个 长度为 2 的子数组且它们的 和 相等。注意，这两个子数组起始位置的下标必须 不相同 。
//如果这样的子数组存在，请返回 true，否则返回 false 。
//子数组 是一个数组中一段连续非空的元素组成的序列。
//示例 1：
//输入：nums = [4, 2, 4]
//输出：true
//解释：元素为[4, 2] 和[2, 4] 的子数组有相同的和 6 。
//示例 2：
//输入：nums = [1, 2, 3, 4, 5]
//输出：false
//解释：没有长度为 2 的两个子数组和相等。
//示例 3：
//输入：nums = [0, 0, 0]
//输出：true
//解释：子数组[nums[0], nums[1]] 和[nums[1], nums[2]] 的和相等，都为 0 。
//注意即使子数组的元素相同，这两个子数组也视为不相同的子数组，因为它们在原数组中的起始位置不同。
//提示：
//2 <= nums.length <= 1000
//- 10^9 <= nums[i] <= 10^9


typedef struct LinkNode {
	int value;
	int count;
	struct LinkNode* next;
}LNode;
typedef struct HashNode {
	int n;
	LNode* l;
}HashNode;
typedef struct Hash {
	HashNode* h;
}Hash;
Hash* Create(int len) {
	Hash* hash = (Hash*)calloc(1, sizeof(Hash));
	assert(hash);
	hash->h = (HashNode*)calloc(len, sizeof(HashNode));
	assert(hash->h);
	for (int i = 0; i < len; i++) {
		(hash->h)[i].n = 0;
		(hash->h)[i].l = (LNode*)calloc(1, sizeof(LNode));
		assert((hash->h)[i].l);
		(hash->h)[i].l->count = 0;
		(hash->h)[i].l->value = 0;
		(hash->h)[i].l->next = NULL;
	}
	return hash;
}
LNode* HashRecord(int x, int key, Hash* hash) {
	(hash->h)[key].n += 1;
	LNode* head = (hash->h)[key].l;
	LNode* p = head->next;
	LNode* q = head;
	while (p && p->value < x) {
		q = p;
		p = p->next;
	}
	if (p == NULL || p->value > x) {
		p = (LNode*)calloc(1, sizeof(LNode));
		assert(p);
		p->value = x;
		p->count = 1;
		p->next = q->next;
		q->next = p;
	}
	else {
		p->count += 1;
	}
	return p;
}
void Destroy(Hash** hash, int len) {
	for (int i = 0; i < len; i++) {
		LNode* head = ((*hash)->h)[i].l;
		if (((*hash)->h)[i].n) {
			LNode* p = head->next;
			while (p) {
				head->next = p->next;
				p->next = NULL;
				free(p);
				p = head->next;
			}
		}
		free(head);
		head = NULL;
	}
	free(*hash);
	*hash = NULL;
}
bool findSubarrays(int* nums, int numsSize) {
	int* tmp = (int*)calloc(numsSize - 1, sizeof(int));
	assert(tmp);
	for (int i = 0; i < numsSize - 1; i++) {
		tmp[i] = nums[i] + nums[i + 1];
	}
	Hash* hash = Create(numsSize);
	bool ans = false;
	for (int i = 0; i < numsSize - 1; i++) {
		int key = abs(tmp[i] % numsSize);
		LNode* p = HashRecord(tmp[i], key, hash);
		if (p->count == 2) {
			ans = true;
			break;
		}
	}
	free(tmp);
	Destroy(&hash, numsSize);
	return ans;
}