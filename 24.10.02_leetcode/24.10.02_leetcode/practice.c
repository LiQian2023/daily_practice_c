#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2024.10.02力扣网刷题
//数组中的第K个最大元素——数组、分治、快速选择、排序、堆（优先队列）——中等
//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
//示例 1:
//输入: [3, 2, 1, 5, 6, 4] , k = 2
//输出 : 5
//示例 2 :
//输入 : [3, 2, 3, 1, 2, 4, 5, 5, 6] , k = 4
//输出 : 4
//提示：
//1 <= k <= nums.length <= 10^5
//- 10^4 <= nums[i] <= 10^4
void Swap(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void Adjust_Down(int* a, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		//找最大，建小堆
		if (child + 1 < len && a[child] > a[child + 1])
			child += 1;
		if (a[parent] > a[child])
			Swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
int findKthLargest(int* nums, int numsSize, int k) {
	int* ans = (int*)calloc(k, sizeof(int));
	assert(ans);
	int len = 0;
	//获取k个数据
	for (int i = 0; i < k; i++) {
		ans[i] = nums[i];
	}
	//建堆
	for (int i = (k - 1) / 2; i >= 0; i--) {
		Adjust_Down(ans, k, i);
	}
	//继续找最大
	for (int i = k; i < numsSize; i++) {
		if (nums[i] > ans[0]) {
			ans[0] = nums[i];
			Adjust_Down(ans, k, 0);
		}
	}
	//堆顶为第k个数
	int ret = ans[0];
	free(ans);
	return ret;
}