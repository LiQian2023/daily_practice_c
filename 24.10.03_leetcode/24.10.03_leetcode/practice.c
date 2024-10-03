#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//2024.10.03力扣网刷题
//多数元素 II——数组、哈希表、计数、排序——简单
//给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n / 3 ⌋ 次的元素。
//示例 1：
//输入：nums = [3, 2, 3]
//输出：[3]
//示例 2：
//输入：nums = [1]
//输出：[1]
//示例 3：
//输入：nums = [1, 2]
//输出：[1, 2]
//提示：
//1 <= nums.length <= 5 * 10^4
//- 10^9 <= nums[i] <= 10^9
//进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

typedef struct Hash {
	int value;
	int count;
}Hash;

int Find_key(Hash* h, int len, int x) {
	//除留取余法
	int key = abs(x) % len;
	//开放定址法
	for (int i = key; i < len; i++) {
		if (!h[i].count || h[i].value == x) {
			key = i;
			break;
		}
	}
	return key;
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
	*returnSize = 0;
	int base = numsSize;
	Hash* h = (Hash*)calloc(base, sizeof(Hash));
	assert(h);
	int* ans = (int*)calloc(base, sizeof(int));
	assert(h);
	int tag = numsSize / 3;
	//元素录入哈希表
	for (int i = 0; i < numsSize; i++) {
		int key = Find_key(h, base, nums[i]);
		h[key].value = nums[i];
		h[key].count += 1;
	}
	//查找元素
	for (int key = 0; key < base; key++) {
		if (h[key].count > tag) {
			ans[*returnSize] = h[key].value;
			*returnSize += 1;
		}
	}
	free(h);
	return ans;
}