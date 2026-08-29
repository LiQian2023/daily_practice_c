#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.08.29力扣网刷题
//2948. 交换得到字典序最小的数组——资深工程师、并查集、数组、排序、第373场周赛——中等
//给你一个下标从 0 开始的 正整数 数组 nums 和一个 正整数 limit 。
//在一次操作中，你可以选择任意两个下标 i 和 j，如果 满足 | nums[i] - nums[j]| <= limit ，则交换 nums[i] 和 nums[j] 。
//返回执行任意次操作后能得到的 字典序最小的数组 。
//如果在数组 a 和数组 b 第一个不同的位置上，数组 a 中的对应元素比数组 b 中的对应元素的字典序更小，则认为数组 a 就比数组 b 字典序更小。例如，数组[2, 10, 3] 比数组[10, 2, 3] 字典序更小，下标 0 处是两个数组第一个不同的位置，且 2 < 10 。
//示例 1：
//输入：nums = [1, 5, 3, 9, 8], limit = 2
//输出：[1, 3, 5, 8, 9]
//解释：执行 2 次操作：
//- 交换 nums[1] 和 nums[2] 。数组变为[1, 3, 5, 9, 8] 。
//- 交换 nums[3] 和 nums[4] 。数组变为[1, 3, 5, 8, 9] 。
//即便执行更多次操作，也无法得到字典序更小的数组。
//注意，执行不同的操作也可能会得到相同的结果。
//示例 2：
//输入：nums = [1, 7, 6, 18, 2, 1], limit = 3
//输出：[1, 6, 7, 18, 1, 2]
//解释：执行 3 次操作：
//- 交换 nums[1] 和 nums[2] 。数组变为[1, 6, 7, 18, 2, 1] 。
//- 交换 nums[0] 和 nums[4] 。数组变为[2, 6, 7, 18, 1, 1] 。
//- 交换 nums[0] 和 nums[5] 。数组变为[1, 6, 7, 18, 1, 2] 。
//即便执行更多次操作，也无法得到字典序更小的数组。
//示例 3：
//输入：nums = [1, 7, 28, 19, 10], limit = 3
//输出：[1, 7, 28, 19, 10]
//解释：[1, 7, 28, 19, 10] 是字典序最小的数组，因为不管怎么选择下标都无法执行操作。
//提示：
//1 <= nums.length <= 10^5
//1 <= nums[i] <= 10^9
//1 <= limit <= 10^9
int cmp(const void* p1, const void* p2) {
	return (*(int**)p1)[0] - (*(int**)p2)[0];
}
int int_cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
	int** h = (int**)calloc(numsSize, sizeof(int*));
	assert(h);
	for (int i = 0; i < numsSize; i++) {
		h[i] = (int*)calloc(2, sizeof(int));
		assert(h[i]);
	}
	for (int i = 0; i < numsSize; i++) {
		h[i][0] = nums[i];
		h[i][1] = i;
	}
	qsort(h, numsSize, sizeof(int*), cmp);
	int* index = (int*)calloc(numsSize, sizeof(int));
	assert(index);
	index[0] = h[0][1];
	int top = 1;
	int* ans = (int*)calloc(numsSize, sizeof(int));
	assert(ans);
	*returnSize = numsSize;
	for (int l = 0, r = 1; r <= numsSize; r++) {
		if (r < numsSize && h[r][0] - h[r - 1][0] <= limit && h[r][0] - h[r - 1][0] >= -limit) {
			index[top] = h[r][1];
			top += 1;
		}
		else {
			qsort(index, r - l, sizeof(int), int_cmp);
			for (int i = 0; i < top; i++, l++) {
				ans[index[i]] = h[l][0];
			}
			top = 0;
			if (r < numsSize) {
				index[top] = h[r][1];
				top += 1;
			}
		}
	}
	free(index);
	for (int i = 0; i < numsSize; i++) {
		free(h[i]);
	}
	free(h);
	return ans;
}