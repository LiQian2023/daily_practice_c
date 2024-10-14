#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.10.14力扣网刷题
//排序数组——数组、分治、桶排序、计数排序、基数排序、排序、堆（优先队列）、归并排序——中等
//给你一个整数数组 nums，请你将该数组升序排列。
//你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。
//示例 1：
//输入：nums = [5, 2, 3, 1]
//输出：[1, 2, 3, 5]
//示例 2：
//输入：nums = [5, 1, 1, 2, 0, 0]
//输出：[0, 0, 1, 1, 2, 5]
//提示：
//1 <= nums.length <= 5 * 10^4
//- 5 * 10^4 <= nums[i] <= 5 * 10^4

// 方法一：归并排序
void MergeSort(int* a, int len, int* b) {
	//分区大小
	for (int key = 1; key < len; key *= 2) {
		int size = 0;
		int begin1 = 0, begin2 = begin1 + key;
		//归并分区
		for (begin1, begin2; begin1 < len && begin2 < len; begin1 += 2 * key, begin2 += 2 * key) {
			int l = begin1, r = begin2;
			while (l < begin1 + key && r < begin2 + key && l < len && r < len) {
				if (a[l] <= a[r]) {
					b[size++] = a[l];
					l += 1;
				}
				else {
					b[size++] = a[r];
					r += 1;
				}
			}
			while (l < len && l < begin1 + key) {
				b[size++] = a[l];
				l += 1;
			}
			while (r < len && r < begin2 + key) {
				b[size++] = a[r];
				r += 1;
			}
		}
		while(begin1 < len) {
			b[size++] = a[begin1];
			begin1 += 1;
		}
		while(begin2 < len) {
			b[size++] = a[begin2];
			begin2 += 1;
		}
		//复制
		for (int i = 0; i < len; i++) {
			a[i] = b[i];
		}
	}
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
	int* ans = (int*)calloc(numsSize, sizeof(int));
	assert(ans);
	*returnSize = numsSize;
	MergeSort(nums, numsSize, ans);
	return ans;
}

void test() {
	int nums[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int len = 10;
	int size = 0;
	int* ret = sortArray(nums, len, &size);
	for (int i = 0; i < size; i++) {
		printf("%d ", ret[i]);
	}
	printf("\n");
	free(ret);
}

int main() {
	test();
	return 0;
}