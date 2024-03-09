#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//2024.03.09力扣网刷题
//三个数的最大乘积——数组、数学、排序——简单
//给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//示例 1：
//输入：nums = [1, 2, 3]
//输出：6
//示例 2：
//输入：nums = [1, 2, 3, 4]
//输出：24
//示例 3：
//输入：nums = [-1, -2, -3]
//输出： - 6
//提示：
//3 <= nums.length <= 10^4
//- 1000 <= nums[i] <= 1000

int cmp(const void* p1, const void* p2) {
	return *(int*)p2 - *(int*)p1;
}

int maximumProduct(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp);
	if (nums[numsSize - 1] >= 0 || nums[0] < 0)
		return nums[0] * nums[1] * nums[2];
	int count = 0;
	for (int i = numsSize - 1; i >= 0 && nums[i] < 0; i--) {
		count++;
	}
	int mul = nums[0] * nums[numsSize - 1];
	return (mul * nums[1] >= mul * nums[numsSize - 2] ? mul * nums[1] : mul * nums[numsSize - 2]);
}