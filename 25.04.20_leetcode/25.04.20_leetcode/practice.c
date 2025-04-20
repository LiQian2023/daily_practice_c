#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2025.04.20力扣网刷题
//找出两数组的不同——数组、哈希表——简单
//给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，请你返回一个长度为 2 的列表 answer ，其中：
//answer[0] 是 nums1 中所有 不 存在于 nums2 中的 不同 整数组成的列表。
//answer[1] 是 nums2 中所有 不 存在于 nums1 中的 不同 整数组成的列表。
//注意：列表中的整数可以按 任意 顺序返回。
//示例 1：
//输入：nums1 = [1, 2, 3], nums2 = [2, 4, 6]
//输出： [[1, 3], [4, 6]]
//解释：
//对于 nums1 ，nums1[1] = 2 出现在 nums2 中下标 0 处，然而 nums1[0] = 1 和 nums1[2] = 3 没有出现在 nums2 中。因此，answer[0] = [1, 3]。
//对于 nums2 ，nums2[0] = 2 出现在 nums1 中下标 1 处，然而 nums2[1] = 4 和 nums2[2] = 6 没有出现在 nums2 中。因此，answer[1] = [4, 6]。
//示例 2：
//输入：nums1 = [1, 2, 3, 3], nums2 = [1, 1, 2, 2]
//输出： [[3], []]
//解释：
//对于 nums1 ，nums1[2] 和 nums1[3] 没有出现在 nums2 中。由于 nums1[2] == nums1[3] ，二者的值只需要在 answer[0] 中出现一次，故 answer[0] = [3]。
//nums2 中的每个整数都在 nums1 中出现，因此，answer[1] = [] 。
//提示：
//1 <= nums1.length, nums2.length <= 1000
//- 1000 <= nums1[i], nums2[i] <= 1000

typedef struct Hash {
	int num;
	bool record;
}Hash;
int** Prepare(int* returnSize, int** returnColumnSizes, int nums1Size, int nums2Size) {
	*returnSize = 2;
	*returnColumnSizes = (int*)calloc(2, sizeof(int));
	assert(*returnColumnSizes);
	int** ans = (int**)calloc(2, sizeof(int*));
	assert(ans);
	ans[0] = (int*)calloc(nums1Size, sizeof(int));
	assert(ans[0]);
	ans[1] = (int*)calloc(nums2Size, sizeof(int));
	assert(ans[1]);
	return ans;
}
void Get_limit(int* nums, int numsSize, int* max, int* min) {
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > *max) {
			*max = nums[i];
		}
		else if (nums[i] < *min) {
			*min = nums[i];
		}
	}
}
Hash* Hash_Record(int* nums, int numsSize, int max, int min) {
	int size = max - min + 1;
	Hash* hash = (Hash*)calloc(size, sizeof(Hash));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key].num += 1;
	}
	return hash;
}
void Get_Ans(Hash* hash, int* nums, int numsSize, int** returnColumnSizes, int** ans, int row, int col, int min) {
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		if (hash[key].num == 0) {
			if (hash[key].record == false) {
				ans[row][col] = key + min;
				hash[key].record = true;
				col += 1;
			}
		}
	}
	(*returnColumnSizes)[row] = col;
}
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
	int** ans = Prepare(returnSize, returnColumnSizes, nums1Size, nums2Size);
	int max = nums1[0], min = nums1[0];
	Get_limit(nums1, nums1Size, &max, &min);
	Get_limit(nums2, nums2Size, &max, &min);
	Hash* hash1 = Hash_Record(nums1, nums1Size, max, min);
	Hash* hash2 = Hash_Record(nums2, nums2Size, max, min);
	Get_Ans(hash2, nums1, nums1Size, returnColumnSizes, ans, 0, 0, min);
	Get_Ans(hash1, nums2, nums2Size, returnColumnSizes, ans, 1, 0, min);
	free(hash1);
	free(hash2);
	return ans;
}