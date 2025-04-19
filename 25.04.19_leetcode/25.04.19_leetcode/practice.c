#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.19力扣网刷题
//至少在两个数组中出现的值——位运算、数组、哈希表——简单
//给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 元素各不相同的 数组，且由 至少 在 两个 数组中出现的所有值组成。数组中的元素可以按 任意 顺序排列。
//示例 1：
//输入：nums1 = [1, 1, 3, 2], nums2 = [2, 3], nums3 = [3]
//输出：[3, 2]
//解释：至少在两个数组中出现的所有值为：
//- 3 ，在全部三个数组中都出现过。
//- 2 ，在数组 nums1 和 nums2 中出现过。
//示例 2：
//输入：nums1 = [3, 1], nums2 = [2, 3], nums3 = [1, 2]
//输出：[2, 3, 1]
//解释：至少在两个数组中出现的所有值为：
//- 2 ，在数组 nums2 和 nums3 中出现过。
//- 3 ，在数组 nums1 和 nums2 中出现过。
//- 1 ，在数组 nums1 和 nums3 中出现过。
//示例 3：
//输入：nums1 = [1, 2, 2], nums2 = [4, 3, 3], nums3 = [5]
//输出：[]
//解释：不存在至少在两个数组中出现的值。
//提示：
//1 <= nums1.length, nums2.length, nums3.length <= 100
//1 <= nums1[i], nums2[j], nums3[k] <= 100

int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
	int** hash = (int**)calloc(101, sizeof(int*));
	assert(hash);
	for (int i = 0; i < 101; i++) {
		hash[i] = (int*)calloc(3, sizeof(int));
		assert(hash[i]);
	}
	for (int i = 0; i < nums1Size; i++) {
		int key = nums1[i];
		if (hash[key][0] == 0) {
			hash[key][0] += 1;
		}
	}
	for (int i = 0; i < nums2Size; i++) {
		int key = nums2[i];
		if (hash[key][1] == 0) {
			hash[key][1] += 1;
		}
	}
	for (int i = 0; i < nums3Size; i++) {
		int key = nums3[i];
		if (hash[key][2] == 0) {
			hash[key][2] += 1;
		}
	}
	int size = 0;
	for (int i = 0; i < 101; i++) {
		int sum = hash[i][0] + hash[i][1] + hash[i][2];
		if (sum >= 2) {
			size += 1;
		}
	}
	int* ans = (int*)calloc(size, sizeof(int));
	assert(ans);
	*returnSize = 0;
	for (int i = 0; i < 101; i++) {
		int sum = hash[i][0] + hash[i][1] + hash[i][2];
		if (sum >= 2) {
			ans[*returnSize] = i;
			*returnSize += 1;
		}
		free(hash[i]);
	}
	free(hash);
	return ans;
}