#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2025.05.26力扣网刷题
//找出强数对的最大异或值 I——位运算、字典树、数组、哈希表、滑动窗口——简单
//给你一个下标从 0 开始的整数数组 nums 。如果一对整数 x 和 y 满足以下条件，则称其为 强数对 ：
//| x - y| <= min(x, y)
//你需要从 nums 中选出两个整数，且满足：这两个整数可以形成一个强数对，并且它们的按位异或（XOR）值是在该数组所有强数对中的 最大值 。
//返回数组 nums 所有可能的强数对中的 最大 异或值。
//注意，你可以选择同一个整数两次来形成一个强数对。
//示例 1：
//输入：nums = [1, 2, 3, 4, 5]
//输出：7
//解释：数组 nums 中有 11 个强数对：(1, 1), (1, 2), (2, 2), (2, 3), (2, 4), (3, 3), (3, 4), (3, 5), (4, 4), (4, 5) 和(5, 5) 。
//这些强数对中的最大异或值是 3 XOR 4 = 7 。
//示例 2：
//输入：nums = [10, 100]
//输出：0
//解释：数组 nums 中有 2 个强数对：(10, 10) 和(100, 100) 。
//这些强数对中的最大异或值是 10 XOR 10 = 0 ，数对(100, 100) 的异或值也是 100 XOR 100 = 0 。
//示例 3：
//输入：nums = [5, 6, 25, 30]
//输出：7
//解释：数组 nums 中有 6 个强数对：(5, 5), (5, 6), (6, 6), (25, 25), (25, 30) 和(30, 30) 。
//这些强数对中的最大异或值是 25 XOR 30 = 7 ；另一个异或值非零的数对是(5, 6) ，其异或值是 5 XOR 6 = 3 。
//提示：
//1 <= nums.length <= 50
//1 <= nums[i] <= 100
void Count_Sort(int* nums, int numsSize) {
	int max = nums[0], min = nums[0];
	bool flag = true;
	for (int i = 1; i < numsSize; i++) {
		if (max < nums[i]) {
			max = nums[i];
		}
		else if (min > nums[i]) {
			min = nums[i];
		}
		if (nums[i] < nums[i - 1]) {
			flag = false;
		}
	}
	if (flag) {
		return;
	}
	int size = max - min + 1;
	int* hash = (int*)calloc(size, sizeof(int));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
	}
	for (int i = 0,j = 0; i < size; i++) {
		while (hash[i]) {
			nums[j] = i + min;
			j += 1;
			hash[i] -= 1;
		}
	}
	free(hash);
	hash = NULL;
}
void Print(int* nums, int numsSize) {
	printf("[\t");
	for (int i = 0; i < numsSize; i++) {
		printf("%d\t", nums[i]);
	}
	printf("]\n");
}
int maximumStrongPairXor(int* nums, int numsSize) {
	Count_Sort(nums, numsSize);
	int ans = 0;
	for (int i = 0, j = 1; i < numsSize && j < numsSize;) {
		bool flag = false;
		if (nums[j] - nums[i] > nums[i]) {
			flag = true;
		}
		else {
			int x = nums[i] ^ nums[j];
			if (x > ans) {
				ans = x;
			}
		}
		if (j == numsSize - 1 || flag) {
			i += 1;
			j = i + 1;
		}
		else {
			j += 1;
		}
	}
	return ans;
}