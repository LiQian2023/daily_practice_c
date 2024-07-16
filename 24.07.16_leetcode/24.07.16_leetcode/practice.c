#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.07.16力扣网刷题
//找到两个数组中的公共元素——数组、哈希表——简单
//给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，它们分别含有 n 和 m 个元素。
//请你计算以下两个数值：
//统计 0 <= i < n 中的下标 i ，满足 nums1[i] 在 nums2 中 至少 出现了一次。
//	统计 0 <= i < m 中的下标 i ，满足 nums2[i] 在 nums1 中 至少 出现了一次。
//	请你返回一个长度为 2 的整数数组 answer ，按顺序 分别为以上两个数值。
//	示例 1：
//	输入：nums1 = [4, 3, 2, 3, 1], nums2 = [2, 2, 5, 2, 3, 6]
//	输出：[3, 4]
//	解释：分别计算两个数值：
//	- nums1 中下标为 1 ，2 和 3 的元素在 nums2 中至少出现了一次，所以第一个值为 3 。
//	- nums2 中下标为 0 ，1 ，3 和 4 的元素在 nums1 中至少出现了一次，所以第二个值为 4 。
//	示例 2：
//	输入：nums1 = [3, 4, 2, 3], nums2 = [1, 5]
//	输出：[0, 0]
//	解释：两个数组中没有公共元素，所以两个值都为 0 。
//	提示：
//	n == nums1.length
//	m == nums2.length
//	1 <= n, m <= 100
//	1 <= nums1[i], nums2[i] <= 100


//方法一：模拟
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	for (int i = 0; i < nums1Size; i++) {
		for (int j = 0; j < nums2Size; j++) {
			if (nums1[i] == nums2[j]) {
				ans[0]++;
				break;
			}
		}
	}
	for (int i = 0; i < nums2Size; i++) {
		for (int j = 0; j < nums1Size; j++) {
			if (nums2[i] == nums1[j]) {
				ans[1]++;
				break;
			}
		}
	}
	return ans;
}

//方法二：哈希表
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	int hash1[101] = { 0 };
	for (int i = 0; i < nums1Size; i++) {
		hash1[nums1[i]]++;
	}
	for (int i = 0; i < nums2Size; i++) {
		if (hash1[nums2[i]]) {
			ans[1]++;
		}
	}
	int hash2[101] = { 0 };
	for (int i = 0; i < nums2Size; i++) {
		hash2[nums2[i]]++;
	}
	for (int i = 0; i < nums1Size; i++) {
		if (hash2[nums1[i]]) {
			ans[0]++;
		}
	}
	return ans;
}


//方法二：哈希表
typedef struct HashNode {
	int value;
	bool add;
}Hash;
int* findIntersectionValues(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	Hash hash[100] = { 0 };
	for (int i = 0; i < nums1Size; i++) {
		int key = nums1[i] - 1;
		hash[key].value += 1;
		hash[key].add = true;
	}
	for (int i = 0; i < nums2Size; i++) {
		int key = nums2[i] - 1;
		if (hash[key].value) {
			ans[1]++;
			if (hash[key].add) {
				ans[0] += hash[key].value;
				hash[key].add = false;
			}
		}
	}
	return ans;
}