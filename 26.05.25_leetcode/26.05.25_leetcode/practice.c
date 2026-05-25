#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.25力扣网刷题
//3940. 限制有序数组中的元素出现次数——中级工程师、第503场周赛——简单
//给你一个 按升序排序 的整数数组 nums 和一个整数 k。
//返回一个数组，使得每个 不同 元素最多出现 k 次，同时保持 nums 中元素的相对顺序不变。
//示例 1：
//输入： nums = [1, 1, 1, 2, 2, 3], k = 2
//输出：[1, 1, 2, 2, 3]
//解释：
//每个元素最多可以出现 2 次。
//元素 1 出现了 3 次，因此只保留其中 2 次。
//元素 2 出现了 2 次，因此全部保留。
//元素 3 出现了 1 次，因此保留。
//因此，结果数组为[1, 1, 2, 2, 3]。
//示例 2：
//输入： nums = [1, 2, 3], k = 1
//输出：[1, 2, 3]
//解释：
//所有元素都互不相同，且已经最多只出现一次，因此数组保持不变。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
//nums 按非递减顺序排序。
//1 <= k <= nums.length
//进阶：
//你能使用原地算法，并仅使用 O(1) 额外空间解决该问题吗？
//注意：用于返回结果或调整结果大小所占用的空间不计入上述空间复杂度，因为有些语言不支持原地调整数组大小。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* limitOccurrences(int* nums, int numsSize, int k, int* returnSize) {
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	int* hash = (int*)calloc(max - min + 1, sizeof(int));
	assert(hash);
	int size = 0;
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key] += 1;
		if (hash[key] > k) {
			hash[key] = k;
		}
		else {
			size += 1;
		}
	}
	int* ans = (int*)calloc(size, sizeof(int));
	assert(ans);
	*returnSize = 0;
	for (int i = min; i <= max; i++) {
		while (hash[i - min]) {
			ans[*returnSize] = i;
			*returnSize += 1;
			hash[i - min] -= 1;
		}
	}
	free(hash);
	return ans;
}