#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2024.06.17力扣网刷题
//两个数组的交集 II——数组、双指针、二分查找、哈希表、排序——简单
//给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
//返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。
//可以不考虑输出结果的顺序。
//示例 1：
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2, 2]
//示例 2:
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[4, 9]
//提示：
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000
//进阶：
//如果给定的数组已经排好序呢？你将如何优化你的算法？
//如果 nums1 的大小比 nums2 小，哪种方法更优？
//如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？


//方法一：排序+模拟
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	qsort(nums1, nums1Size, sizeof(int), cmp);
	qsort(nums2, nums2Size, sizeof(int), cmp);
	int* ans = (int*)calloc(nums1Size, sizeof(int));
	assert(ans);
	int i = 0;
	for (int j = 0, z = 0; j < nums1Size && z < nums2Size;) {
		if (nums1[j] == nums2[z]) {
			ans[i++] = nums1[j];
			j++, z++;
		}
		else if (nums1[j] < nums2[z])
			j++;
		else if(nums1[j] > nums2[z])
			z++;
	}
	*returnSize = i;
	return ans;
}