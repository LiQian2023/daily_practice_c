#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.02力扣网刷题
//从两个数字数组里生成最小数字——数组、哈希表、枚举——简单
//给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，请你返回 最小 的数字，两个数组都 至少 包含这个数字的某个数位。
//示例 1：
//输入：nums1 = [4, 1, 3], nums2 = [5, 7]
//输出：15
//解释：数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
//示例 2：
//输入：nums1 = [3, 5, 2, 6], nums2 = [3, 1, 7]
//输出：3
//解释：数字 3 的数位 3 在两个数组中都出现了。
//提示：
//1 <= nums1.length, nums2.length <= 9
//1 <= nums1[i], nums2[i] <= 9
//每个数组中，元素 互不相同 。

int Hash_Record(int* nums, int numsSize, int* hash) {
	int min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i];
		hash[key] += 1;
		if (min > key) {
			min = key;
		}
	}
	return min;
}
int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int hash[10] = { 0 };
	int min1 = Hash_Record(nums1, nums1Size, hash);
	int min2 = Hash_Record(nums2, nums2Size, hash);
	int ans = -1;
	for (int i = 0; i < 10; i++) {
		if (hash[i] == 2) {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		ans = min1 < min2 ? min1 * 10 + min2 : min2 * 10 + min1;
	}
	return ans;
}