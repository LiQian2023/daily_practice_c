#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//2026.07.07力扣网刷题
//4. 寻找两个正序数组的中位数——高级工程师、二分查找、分治、数组——困难
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//算法的时间复杂度应该为 O(log(m + n)) 。
//示例 1：
//输入：nums1 = [1, 3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1, 2, 3] ，中位数 2
//示例 2：
//输入：nums1 = [1, 2], nums2 = [3, 4]
//输出：2.50000
//解释：合并数组 = [1, 2, 3, 4] ，中位数(2 + 3) / 2 = 2.5
//提示：
//nums1.length == m
//nums2.length == n
//0 <= m <= 1000
//0 <= n <= 1000
//1 <= m + n <= 2000
//- 10^6 <= nums1[i], nums2[i] <= 10^6
void Copy(int* src, int len, int* dis, int pi) {
	for (int i = 0; i < len; i++) {
		dis[pi++] = src[i];
	}
}
void Merge(int* nums, int l, int r, int* b) {
	if (r - l <= 1) {
		return;
	}

	// 拆分
	int key = (r - l) / 2 + l;
	Merge(nums, l, key, b);
	Merge(nums, key, r, b);

	// 合并
	int i = l, j = key, z = l;
	while (i < key && j < r) {
		if (nums[i] <= nums[j]) {
			b[z++] = nums[i++];
		}
		else {
			b[z++] = nums[j++];
		}
	}
	while (i < key && i < r) {
		b[z++] = nums[i++];
	}
	while (j < r) {
		b[z++] = nums[j++];
	}

	// 复制
	Copy(b + l, r - l, nums, l);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int size = nums1Size + nums2Size;
	int* tmp = (int*)calloc(size, sizeof(int));
	assert(tmp);
	Copy(nums1, nums1Size, tmp, 0);
	Copy(nums2, nums2Size, tmp, nums1Size);
	int* b = (int*)calloc(size, sizeof(int));
	assert(b);
	Merge(tmp, 0, size, b);
	int target = size / 2;
	double ans = tmp[target];
	if (size % 2 == 0) {
		ans += tmp[target - 1];
		ans /= 2.0;
	}
	free(tmp);
	return ans;
}