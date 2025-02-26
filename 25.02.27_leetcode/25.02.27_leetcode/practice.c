#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

//2025.02.27力扣网刷题
//数组中第 K 个独一无二的字符串——数组、哈希表、字符串、计数——简单
//独一无二的字符串 指的是在一个数组中只出现过 一次 的字符串。
//给你一个字符串数组 arr 和一个整数 k ，请你返回 arr 中第 k 个 独一无二的字符串 。如果 少于 k 个独一无二的字符串，那么返回 空字符串 "" 。
//注意，按照字符串在原数组中的 顺序 找到第 k 个独一无二字符串。
//示例 1:
//输入：arr = ["d", "b", "c", "b", "c", "a"], k = 2
//输出："a"
//解释：
//arr 中独一无二字符串包括 "d" 和 "a" 。
//"d" 首先出现，所以它是第 1 个独一无二字符串。
//"a" 第二个出现，所以它是 2 个独一无二字符串。
//由于 k == 2 ，返回 "a" 。
//示例 2:
//输入：arr = ["aaa", "aa", "a"], k = 1
//输出："aaa"
//解释：
//arr 中所有字符串都是独一无二的，所以返回第 1 个字符串 "aaa" 。
//示例 3：
//输入：arr = ["a", "b", "a"], k = 3
//输出：""
//解释：
//唯一一个独一无二字符串是 "b" 。由于少于 3 个独一无二字符串，我们返回空字符串 "" 。
//提示：
//1 <= k <= arr.length <= 1000
//1 <= arr[i].length <= 5
//arr[i] 只包含小写英文字母。
typedef struct LinkNode {
	int count;//字符串次数
	int pi;//字符串下标
	struct LinkNode* next;//相同关键字的不同字符串
}LN;

typedef struct Hash {
	int num;//字符个数
	LN* list;//字符串信息表
}Hash;

void CreateHash(Hash** h) {
	for (int i = 0; i < 6; i++) {
		(*h)[i].num = 0;
		(*h)[i].list = (LN*)calloc(i * 26, sizeof(LN));
		assert((*h)[i].list);
	}
}
void Hash_Insert(Hash** h, int key1, int key2, int i) {
	LN* p = (LN*)calloc(1, sizeof(LN));
	assert(p);
	p->count = 1;
	p->pi = i;
	//头插法
	p->next = (*h)[key1].list[key2].next;
	(*h)[key1].list[key2].next = p;
	(*h)[key1].list[key2].count += 1;
}
void Destroy(Hash** h) {
	for (int i = 0; i < 6; i++) {
		free((*h)[i].list);
	}
	free(*h);
	*h = NULL;
}
char* kthDistinct(char** arr, int arrSize, int k) {
	Hash* h = (Hash*)calloc(6, sizeof(Hash));
	assert(h);
	CreateHash(&h);
	//哈希记录
	for (int i = 0; i < arrSize; i++) {
		int key1 = strlen(arr[i]);
		h[key1].num += 1;
		int key2 = 0;
		for (int j = 0; j < key1; j++) {
			key2 += arr[i][j] - 'a';
		}
		LN* p = h[key1].list[key2].next;
		while (p && strcmp(arr[p->pi], arr[i])) {
			p = p->next;
		}
		if (p) {
			p->count += 1;
		}
		else {
			Hash_Insert(&h, key1, key2, i);
		}
	}
	int* pi = (int*)calloc(arrSize, sizeof(int));
	assert(pi);
	int size = 0;
	for (int i = 0; i < 6; i++) {
		if (h[i].num) {
			for (int j = 0; j < i * 26; j++) {
				if (h[i].list[j].count) {
					LN* p = h[i].list[j].next;
					while (p) {
						if (p->count == 1) {
							pi[size] = p->pi;
							size += 1;
						}
						p = p->next;
					}
				}
			}
		}
	}
	if (size < k) {
		return "";
	}
	Destroy(&h);
	h = NULL;
	int* nums = (int*)calloc(1000, sizeof(int));
	assert(nums);
	for (int i = 0; i < size; i++) {
		int key = pi[i];
		nums[key] += 1;
	}
	free(pi);
	pi = NULL;
	int ans = -1;
	for (int i = 0, n = 0; i < 1000; i++) {
		if (nums[i]) {
			n += 1;
		}
		if (n == k) {
			ans = i;
			break;
		}
	}
	free(nums);
	nums = NULL;
	return arr[ans];
}