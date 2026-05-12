#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.12力扣网刷题
//3925. 连接逆序数组——中级工程师、第501场周赛——简单
//给你一个长度为 n 的整数数组 nums。
//构造一个新的长度为 2 * n 的数组 ans，其中前 n 个元素与 nums 相同，后 n 个元素为 nums 的逆序。
//具体而言，对于 0 <= i <= n - 1：
//ans[i] = nums[i]
//ans[i + n] = nums[n - i - 1]
//返回整数数组 ans。
//示例 1：
//输入： nums = [1, 2, 3]
//输出：[1, 2, 3, 3, 2, 1]
//解释：
//ans 的前 n 个元素与 nums 相同。
//接下来的 n = 3 个元素按照 nums 的逆序填入：
//ans[3] = nums[2] = 3
//ans[4] = nums[1] = 2
//ans[5] = nums[0] = 1
//因此，ans = [1, 2, 3, 3, 2, 1]。
//示例 2：
//输入： nums = [1]
//输出：[1, 1]
//解释：
//数组逆序后保持不变。因此，ans = [1, 1]。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* concatWithReverse(int* nums, int numsSize, int* returnSize) {
	int* ans = (int*)calloc(2 * numsSize, sizeof(int));
	assert(ans);
	*returnSize = 2 * numsSize;
	for (int i = 0; i < numsSize; i++) {
		ans[i] = nums[i];
		ans[*returnSize - i - 1] = nums[i];
	}
	return ans;
}