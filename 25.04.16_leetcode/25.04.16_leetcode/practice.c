#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2025.04.16力扣网刷题
//最小公共值——数组、哈希表、双指针、二分查找——简单
//给你两个整数数组 nums1 和 nums2 ，它们已经按非降序排序，请你返回两个数组的 最小公共整数 。如果两个数组 nums1 和 nums2 没有公共整数，请你返回 - 1 。
//如果一个整数在两个数组中都 至少出现一次 ，那么这个整数是数组 nums1 和 nums2 公共 的。
//示例 1：
//输入：nums1 = [1, 2, 3], nums2 = [2, 4]
//输出：2
//解释：两个数组的最小公共元素是 2 ，所以我们返回 2 。
//示例 2：
//输入：nums1 = [1, 2, 3, 6], nums2 = [2, 3, 4, 5]
//输出：2
//解释：两个数组中的公共元素是 2 和 3 ，2 是较小值，所以返回 2 。
//提示：
//1 <= nums1.length, nums2.length <= 10^5
//1 <= nums1[i], nums2[j] <= 10^9
//nums1 和 nums2 都是 非降序 的。

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int max = nums1[0], min = nums1[0];
	for (int i = 0; i < nums1Size; i++) {
		if (max < nums1[i]) {
			max = nums1[i];
		}
		else if (min > nums1[i]) {
			min = nums1[i];
		}
	}
	for (int i = 0; i < nums2Size; i++) {
		if (max < nums2[i]) {
			max = nums2[i];
		}
		else if (min > nums2[i]) {
			min = nums2[i];
		}
	}
	int size = max - min + 1;
	int* hash = (int*)calloc(size, sizeof(int));
	assert(hash);
	for (int i = 0; i < nums1Size; i++) {
		int key = nums1[i] - min;
		if (hash[key] == 0) {
			hash[key] = 1;
		}
	}
	for (int i = 0; i < nums2Size; i++) {
		int key = nums2[i] - min;
		if (hash[key] == 1) {
			hash[key] += 1;
		}
	}
	int ans = -1;
	for (int i = 0; i < size; i++) {
		if (hash[i] == 2) {
			ans = i + min;
			break;
		}
	}
	free(hash);
	return ans;
}