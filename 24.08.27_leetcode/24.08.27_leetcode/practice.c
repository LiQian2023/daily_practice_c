#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2024.08.27力扣网刷题
//检查数组是否是好的——数组、哈希、排序——简单
//给你一个整数数组 nums ，如果它是数组 base[n] 的一个排列，我们称它是个 好 数组。
//base[n] = [1, 2, ..., n - 1, n, n] 
//（换句话说，它是一个长度为 n + 1 且包含 1 到 n - 1 恰好各一次，包含 n  两次的一个数组）。
//比方说，base[1] = [1, 1] ，base[3] = [1, 2, 3, 3] 。
//如果数组是一个好数组，请你返回 true ，否则返回 false 。
//注意：数组的排列是这些数字按任意顺序排布后重新得到的数组。
//示例 1：
//输入：nums = [2, 1, 3]
//输出：false
//解释：因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 。
//但是 base[3] 有 4 个元素，但数组 nums 只有 3 个元素，所以无法得到 base[3] = [1, 2, 3, 3] 的排列，所以答案为 false 。
//示例 2：
//输入：nums = [1, 3, 3, 2]
//输出：true
//解释：因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 ，
//可以看出数组是 base[3] = [1, 2, 3, 3] 的一个排列（交换 nums 中第二个和第四个元素）。
//所以答案为 true 。
//示例 3：
//输入：nums = [1, 1]
//输出：true
//解释：因为数组的最大元素是 1 ，唯一可以构成这个数组的 base[n] 对应的 n = 1，可以看出数组是 base[1] = [1, 1] 的一个排列。所以答案为 true 。
//示例 4：
//输入：nums = [3, 4, 4, 1, 2, 1]
//输出：false
//解释：因为数组的最大元素是 4 ，唯一可以构成这个数组的 base[n] 对应的 n = 4 。但是 base[n] 有 5 个元素而 nums 有 6 个元素。所以答案为 false 。
//提示：
//1 <= nums.length <= 100
//1 <= num[i] <= 200

//方法一：计数排序
void CountSort(int* a, int n) {
	int nums[201] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		nums[a[i]] += 1;
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	n = 0;
	for (int i = min; i <= max; i++) {
		while (nums[i]) {
			a[n++] = i;
			nums[i] -= 1;
		}
	}
}

bool isGood(int* nums, int numsSize) {
	CountSort(nums, numsSize);
	int max = nums[numsSize - 1];
	if (numsSize != max + 1)
		return false;
	for (int i = 0; i < numsSize - 2; i++) {
		if (nums[i] != i + 1)
			return false;
	}
	if (nums[numsSize - 1] != nums[numsSize - 2])
		return false;
	return true;
}