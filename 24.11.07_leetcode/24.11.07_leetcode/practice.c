#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.11.07力扣网刷题
//长度为 K 的子数组的能量值 II——数组、滑动窗口——中等
//给你一个长度为 n 的整数数组 nums 和一个正整数 k 。
//一个数组的 能量值 定义为：
//如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。
//否则为 - 1 。
//你需要求出 nums 中所有长度为 k 的子数组的能量值。
//请你返回一个长度为 n - k + 1 的整数数组 results ，其中 results[i] 是子数组 nums[i..(i + k - 1)] 的能量值。
//示例 1：
//输入：nums = [1, 2, 3, 4, 3, 2, 5], k = 3
//输出：[3, 4, -1, -1, -1]
//解释：
//nums 中总共有 5 个长度为 3 的子数组：
//[1, 2, 3] 中最大元素为 3 。
//[2, 3, 4] 中最大元素为 4 。
//[3, 4, 3] 中元素 不是 连续的。
//[4, 3, 2] 中元素 不是 上升的。
//[3, 2, 5] 中元素 不是 连续的。
//示例 2：
//输入：nums = [2, 2, 2, 2, 2], k = 4
//输出：[-1, -1]
//示例 3：
//输入：nums = [3, 2, 3, 2, 3, 2], k = 2
//输出：[-1, 3, -1, 3, -1]
//提示：
//1 <= n == nums.length <= 10^5
//1 <= nums[i] <= 10^6
//1 <= k <= n

int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
	*returnSize = 0;
	int base = numsSize - k + 1;
	printf("base = %d\n", base);
	int* ans = (int*)calloc(base, sizeof(int));
	assert(ans);
	if (numsSize == 1) {
		ans[*returnSize] = nums[0];
		*returnSize += 1;
	}
	else if (k == 1) {
		for (int i = 0; i < numsSize; i++) {
			ans[*returnSize] = nums[i];
			*returnSize += 1;
		}
	}
	else {
		for (int i = 1, n = 1; i < numsSize; i += 1) {
			if (n) {
				if (nums[i] == nums[i - 1] + 1) {
					n += 1;
					if (n == k) {
						ans[*returnSize] = nums[i];
						n -= 1;
						*returnSize += 1;
					}
				}
				else{
					while (n && *returnSize != base) {
						ans[*returnSize] = -1;
						*returnSize += 1;
						n -= 1;
					}
					n += 1;
				}
			}
			if (*returnSize == base) {
				break;
			}
		}
	}
	return ans;
}