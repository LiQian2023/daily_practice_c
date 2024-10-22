#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
//2024.10.21力扣网刷题
//最小差值 II——贪心、数组、数学、排序——中等
//给你一个整数数组 nums，和一个整数 k 。
//对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成 nums[i] + k 或 nums[i] - k 。
//nums 的 分数 是 nums 中最大元素和最小元素的差值。
//在更改每个下标对应的值之后，返回 nums 的最小 分数 。
//示例 1：
//输入：nums = [1], k = 0
//输出：0
//解释：分数 = max(nums) - min(nums) = 1 - 1 = 0 。
//示例 2：
//输入：nums = [0, 10], k = 2
//输出：6
//解释：将数组变为[2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
//示例 3：
//输入：nums = [1, 3, 6], k = 3
//输出：3
//解释：将数组变为[4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
//提示：
//1 <= nums.length <= 10^4
//0 <= nums[i] <= 10^4
//0 <= k <= 10^4

void Swap(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void CountSort(int* a, int len) {
	int count[10001] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < len; i++) {
		count[a[i]] += 1;
		if (a[i] < min)
			min = a[i];
		else if (a[i] > max)
			max = a[i];
	}
	len = 0;
	for (int i = min; i <= max; i++) {
		while (count[i]) {
			a[len] = i;
			len += 1;
			count[i] -= 1;
		}
	}
}
void deal_arr(int* a, int len, int k, int min, int max) {
	for (int i = 0; i < len; i++) {
			a[i] += k;
	}
}
int get_Min(int a, int b, int c) {
	int min = 0;
	if (a > b) {
		if (b > c)
			min = c;
		else
			min = b;
	}
	else {
		if (a > c)
			min = c;
		else
			min = a;
	}
	return min;
}
int get_Max(int a, int b, int c) {
	int max = 0;
	if (a > b) {
		if (a > c)
			max = a;
		else
			max = c;
	}
	else {
		if (b > c)
			max = b;
		else
			max = c;
	}
	return max;
}
int smallestRangeII(int* nums, int numsSize, int k) {
	CountSort(nums, numsSize);
	int min = nums[0], max = nums[numsSize - 1];
	int ans = max - min;
	for (int i = 0; i < numsSize - 1; i++) {
		int a = nums[i], b = nums[i + 1];
		ans = fmin(ans, fmax(max - k, a + k) - fmin(min + k, b - k));
	}
	return ans;
}