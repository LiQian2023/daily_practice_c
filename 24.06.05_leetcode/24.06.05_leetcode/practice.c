#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.06.05力扣网刷题
//轮转数组——数组、数学、双指针——中等
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//示例 1:
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//	向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//	示例 2 :
//	输入：nums = [-1, -100, 3, 99], k = 2
//	输出：[3, 99, -1, -100]
//	解释 :
//	向右轮转 1 步 : [99, -1, -100, 3]
//	向右轮转 2 步 : [3, 99, -1, -100]
//	提示：
//	1 <= nums.length <= 10^5
//	- 2^31 <= nums[i] <= 2^31 - 1
//	0 <= k <= 10^5
//	进阶：
//	尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
//	你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

//方法一：暴力求解
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	for (int i = 0; i < k; i++) {
		int tmp = nums[numsSize - 1];//获取最后一个元素
		for (int j = numsSize - 1; j > 0; j--) {
			nums[j] = nums[j - 1];
		}
		nums[0] = tmp;
	}
}

//方法二：中间数组
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	int tmp[110000] = { 0 };
	int i = 0;
	int j = numsSize - k;
	while (j < numsSize)
		tmp[i++] = nums[j++];
	j = 0;
	while (i < numsSize)
		tmp[i++] = nums[j++];
	i = 0;
	j = 0;
	while (i < numsSize) {
		nums[i++] = tmp[j++];
	}
}

//方法三：内存函数
void rotate(int* nums, int numsSize, int k) {
	k %= numsSize;
	int tmp[100000] = { 0 };
	memcpy(tmp, nums + (numsSize - k), k * sizeof(int));
	memmove(nums + k, nums, (numsSize - k) * sizeof(int));
	memcpy(nums, tmp, k * sizeof(int));
}