#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.08.04力扣网刷题
//3731. 找出缺失的元素——中级工程师、数组、哈希表、排序、第474场周赛——简单
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
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	int size = max - min + 1;
	bool* hash = (bool*)calloc(size, sizeof(bool));
	assert(hash);
	int n = size;
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key] = true;
		n -= 1;
	}
	*returnSize = n;
	int* ans = (int*)calloc(n, sizeof(int));
	assert(ans);
	for (int i = min, j = 0; i <= max; i++) {
		if (hash[i - min] == false) {
			ans[j] = i;
			j += 1;
		}
	}
	return ans;
}