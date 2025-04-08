#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.04.08力扣网刷题
//使数组元素互不相同所需的最少操作次数——数组、哈希表——简单
//给你一个整数数组 nums，你需要确保数组中的元素 互不相同 。为此，你可以执行以下操作任意次：
//从数组的开头移除 3 个元素。如果数组中元素少于 3 个，则移除所有剩余元素。
//注意：空数组也视作为数组元素互不相同。返回使数组元素互不相同所需的 最少操作次数 。
//示例 1：
//输入： nums = [1, 2, 3, 4, 2, 3, 3, 5, 7]
//输出： 2
//解释：
//第一次操作：移除前 3 个元素，数组变为[4, 2, 3, 3, 5, 7]。
//第二次操作：再次移除前 3 个元素，数组变为[3, 5, 7]，此时数组中的元素互不相同。
//因此，答案是 2。
//示例 2：
//输入： nums = [4, 5, 6, 4, 4]
//输出： 2
//解释：
//第一次操作：移除前 3 个元素，数组变为[4, 4]。
//第二次操作：移除所有剩余元素，数组变为空。
//因此，答案是 2。
//示例 3：
//输入： nums = [6, 7, 8, 9]
//输出： 0
//解释：
//数组中的元素已经互不相同，因此不需要进行任何操作，答案是 0。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

typedef struct Hash {
	int pi;
	int count;
}Hash;

void GetSize(int* nums, int numsSize,int* max,int* min) {
	*max = nums[0], *min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > *max) {
			*max = nums[i];
		}
		else if (nums[i] < *min) {
			*min = nums[i];
		}
	}
}
int minimumOperations(int* nums, int numsSize) {
	int max = 0, min = 0;
	GetSize(nums, numsSize, &max, &min);
	int size = max - min + 1;
	Hash* hash = (Hash*)calloc(size, sizeof(Hash));
	assert(size);
	int ans = 0;
	int begin = 0;	// 记录起点
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		if (hash[key].count == 0) {
			hash[key].count = 1;
		}
		else {
			// 重复元素下标在计数范围内
			if (hash[key].pi >= begin) {
				int mod = hash[key].pi % 3;
				int del = hash[key].pi + 3 - mod;	// 需要删除的元素总长度
				ans = del / 3;
				begin = del;	// 计数起点
				if (begin > i) {
					i = begin - 1;
				}
			}
		}
		hash[key].pi = i;
	}
	free(hash);
	return ans;
}