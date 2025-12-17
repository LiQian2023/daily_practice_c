#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.12.17力扣网刷题
//3731. 找出缺失的元素——数组、哈希表、排序、第474场周赛——简单
//给你一个整数数组 nums ，数组由若干 互不相同 的整数组成。
//数组 nums 原本包含了某个范围内的 所有整数 。但现在，其中可能 缺失 部分整数。
//该范围内的 最小 整数和 最大 整数仍然存在于 nums 中。
//返回一个 有序 列表，包含该范围内缺失的所有整数，并 按从小到大排序。如果没有缺失的整数，返回一个 空 列表。
//示例 1：
//输入： nums = [1, 4, 2, 5]
//输出：[3]
//解释：
//最小整数为 1，最大整数为 5，因此完整的范围应为[1, 2, 3, 4, 5]。其中只有 3 缺失。
//示例 2：
//输入： nums = [7, 8, 6, 9]
//输出：[]
//解释：
//最小整数为 6，最大整数为 9，因此完整的范围为[6, 7, 8, 9]。所有整数均已存在，因此没有缺失的整数。
//示例 3：
//输入： nums = [5, 1]
//输出：[2, 3, 4]
//解释：
//最小整数为 1，最大整数为 5，因此完整的范围应为[1, 2, 3, 4, 5]。缺失的整数为 2、3 和 4。
//提示：
//2 <= nums.length <= 100
//1 <= nums[i] <= 100

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
	*returnSize = 0;
	int min = nums[0], max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	int size = max - min + 1;
	int* ans = (int*)calloc(size, sizeof(int));
	assert(ans);
	int* hash = (int*)calloc(max + 1, sizeof(int));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i];
		hash[key] += 1;
	}
	for (int i = min; i <= max; i++) {
		if (hash[i] == 0) {
			ans[*returnSize] = i;
			*returnSize += 1;
		}
	}
	free(hash);
	hash = NULL;
	return ans;
}