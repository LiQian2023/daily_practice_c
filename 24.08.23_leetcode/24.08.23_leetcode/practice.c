#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.08.23力扣网刷题
//数组中不等三元组的数目——数组、哈希表、排序——简单
//给你一个下标从 0 开始的正整数数组 nums 。请你找出并统计满足下述条件的三元组 (i, j, k) 的数目：
//0 <= i < j < k < nums.length
//nums[i]、nums[j] 和 nums[k] 两两不同 。
//换句话说：nums[i] != nums[j]、nums[i] != nums[k] 且 nums[j] != nums[k] 。
//返回满足上述条件三元组的数目。
//示例 1：
//输入：nums = [4, 4, 2, 4, 3]
//输出：3
//解释：下面列出的三元组均满足题目条件：
//- (0, 2, 4) 因为 4 != 2 != 3
//- (1, 2, 4) 因为 4 != 2 != 3
//- (2, 3, 4) 因为 2 != 4 != 3
//共计 3 个三元组，返回 3 。
//注意(2, 0, 4) 不是有效的三元组，因为 2 > 0 。
//示例 2：
//输入：nums = [1, 1, 1, 1, 1]
//输出：0
//解释：不存在满足条件的三元组，所以返回 0 。
//提示：
//3 <= nums.length <= 100
//1 <= nums[i] <= 1000

//方法一：计数排序
void CountSort(int* a, int n) {
	int nums[1001] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		nums[a[i]] += 1;
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
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

//方法二：哈希表
int unequalTriplets(int* nums, int numsSize) {
	CountSort(nums, numsSize);
	int a1 = nums[0], a2 = nums[1], a3 = nums[2];
	int ans = 0;
	for (int i = 0; i < numsSize - 2; i++) {
		a1 = nums[i];
		for (int j = i + 1; j < numsSize - 1; j++) {
			a2 = nums[j];
			if (a2 != a1) {
				for (int z = j + 1; z < numsSize; z++) {
					a3 = nums[z];
					if (a3 != a2) {
						ans += 1;
					}
				}
			}
		}
	}
	return ans;
}

int unequalTriplets(int* nums, int numsSize) {
	int count[1001] = { 0 };
	int min = nums[0], max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		count[nums[i]] += 1;
		if (min > nums[i])
			min = nums[i];
		if (max < nums[i])
			max = nums[i];
	}
	int ans = 0, x = 0, y = 0, n = numsSize;
	for (int i = min; i <= max; i++) {
		y = count[i];
		ans += x * y * (n - x - y);
		x += y;
	}
	return ans;
}