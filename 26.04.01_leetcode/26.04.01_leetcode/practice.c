#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.04.01力扣网刷题
//3880. 两个值之间的最小绝对差值——中级工程师、第179场双周赛——简单
//给你一个只包含 0、1 和 2 的整数数组 nums。
//如果 nums[i] == 1 且 nums[j] == 2，则称下标对(i, j) 为 有效 的。
//请返回所有有效下标对中 i 和 j 之间的 最小 绝对差。如果不存在有效下标对，则返回 - 1。
//下标 i 和 j 之间的绝对差定义为 abs(i - j)。
//示例 1：
//输入： nums = [1, 0, 0, 2, 0, 1]
//输出： 2
//解释：
//有效下标对有：
//(0, 3)，其绝对差为 abs(0 - 3) = 3。
//(5, 3)，其绝对差为 abs(5 - 3) = 2。
//因此，结果是 2。
//示例 2：
//输入： nums = [1, 0, 1, 0]
//输出： - 1
//解释：
//数组中不存在有效下标对，因此结果是 - 1。
//提示：
//1 <= nums.length <= 100
//0 <= nums[i] <= 2

int minAbsoluteDifference(int* nums, int numsSize) {
	int* one = (int*)calloc(numsSize, sizeof(int));
	assert(one);
	int* two = (int*)calloc(numsSize, sizeof(int));
	assert(two);
	int size1 = 0, size2 = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == 1) {
			one[size1] = i;
			size1 += 1;
		}
		else if (nums[i] == 2) {
			two[size2] = i;
			size2 += 1;
		}
	}
	if (size1 == 0 || size2 == 0) {
		return -1;
	}
	int ans = abs(one[0] - two[0]);
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (abs(one[i] - two[j]) < ans) {
				ans = abs(one[i] - two[j]);
			}
		}
	}
	free(one);
	free(two);
	return ans;
}