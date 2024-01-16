#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.01.16力扣网刷题
//合并两个有序数组——数组、双指针、排序——简单
//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
//示例 1：
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//解释：需要合并[1, 2, 3] 和[2, 5, 6] 。
//合并结果是[1, 2, 2, 3, 5, 6] ，其中斜体加粗标注的为 nums1 中的元素。
//示例 2：
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]
//解释：需要合并[1] 和[] 。
//合并结果是[1] 。
//示例 3：
//输入：nums1 = [0], m = 0, nums2 = [1], n = 1
//输出：[1]
//解释：需要合并的数组是[] 和[1] 。
//合并结果是[1] 。
//注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
//提示：
//nums1.length == m + n
//nums2.length == n
//0 <= m, n <= 200
//1 <= m + n <= 200
//- 109 <= nums1[i], nums2[j] <= 109
//进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
//法一：qsort排序
void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	assert(nums1 && nums2);
	for (int i = m; i < nums1Size; i++) {
		nums1[i] = nums2[nums2Size - n];
		nums2Size++;
	}
	qsort(nums1, nums1Size, sizeof(int), cmp);
}
//法二：分情况讨论
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	if (nums2Size != 0 && m != 0) {
		if (nums1[0] >= nums2[nums2Size - 1])
		{
			for (int i = m, j = 0; i < nums1Size; i++, j++) {
				nums1[i] = nums1[j];
				nums1[j] = nums2[j];
			}
		}
		else if (nums2[0] >= nums1[m - 1]) {
			for (int i = m, j = 0; i < nums1Size; i++, j++) {
				nums1[i] = nums2[j];
			}
		}
		else {
			if (nums1[m - 1] > nums2[nums2Size - 1]) {
				nums1[nums1Size - 1] = nums1[m - 1];
				int i = m - 2, j = n - 1;
				for (i, j; i >= 0 && j >= 0;) {
					if (nums1[i] > nums2[j]) {
						nums1[i + j + 1 ] = nums1[i];
						i--;
					}
					else {
						nums1[i + j + 1 ] = nums2[j];
						j--;
					}
				}
				if (j >= 0) {
					for (j; j >= 0; j--) {
						nums1[i + j + 1] = nums2[j];
					}
				}
			}
			else {
				nums1[nums1Size - 1] = nums2[n - 1];
				int i = m - 1, j = n - 2;
				for (i, j; i >= 0 && j >= 0;) {
					if (nums1[i] > nums2[j]) {
						nums1[i + j + 1 ] = nums1[i];
						i--;
					}
					else {
						nums1[i + j + 1 ] = nums2[j];
						j--;
					}
				}
				if (j >= 0) {
					for (j; j >= 0; j--) {
						nums1[i + j + 1] = nums2[j];
					}
				}
			}
		}
	}
	else if (m == 0) {
		for (int i = 0; i < nums1Size; i++) {
			nums1[i] = nums2[i];
		}
	}
}
int main() {
	int m = 0, n = 0;
	while (scanf("%d%d", &m, &n)) {
		int* nums1 = (int*)calloc(n + m, sizeof(int));
		assert(nums1);
		int* nums2 = (int*)calloc(n, sizeof(int));
		assert(nums2);
		for (int i = 0; i < m; i++) {
			scanf("%d", &nums1[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &nums2[i]);
		}
		merge(nums1, m + n, m, nums2, n, n);
		for (int i = 0; i < m + n; i++) {
			printf("%d ", nums1[i]);
		}
		printf("\n");
		free(nums1);
		free(nums2);
	}
	return 0;
}