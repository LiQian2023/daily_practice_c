#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

//2026.10.16力扣网刷题
//4074. 和为目标值的最大乘积对——中级工程师、第193场双周赛——简单
//给你一个整数数组 nums 和一个整数 target。
//当一个由 不同 下标组成的二元组(i, j) 满足以下条件，称它是 有效的 ：
//nums[i] + nums[j] == target
//nums[i] > nums[j]
//返回一个 有效的 二元组[i, j]，使其 乘积 nums[i] * nums[j] 在所有有效二元组中是 最大 的。如果不存在有效的二元组，返回[-1, -1]。
//如果有多个有效二元组都能达到 最大 乘积，你可以返回其中的 任意一个 。
//示例 1：
//输入： nums = [1, 2, 3, 4], target = 5
//输出：[2, 1]
//解释：
//存在 2 个有效的二元组：
//序号(i, j)	nums[i]	nums[j]	和	积
//1	(3, 0)	4	1	5	4
//2	(2, 1)	3	2	5	6
//两个二元组的和均为 5 且满足 nums[i] > nums[j]。第二个二元组的乘积更大，3 * 2 = 6，因此答案是[2, 1]。
//示例 2：
//输入： nums = [-3, -1, 4, 2], target = 1
//输出：[3, 1]
//解释：
//存在 2 个有效的二元组：
//序号(i, j)	nums[i]	nums[j]	和	积
//1	(2, 0)	4 - 3	1 - 12
//2	(3, 1)	2 - 1	1 - 2
//由于 - 2 > -12，因此选择下标(3, 1) 对应的二元组，答案是[3, 1]。
//示例 3：
//输入： nums = [3, 3, 5], target = 6
//输出：[-1, -1]
//解释：
//不存在有效的二元组，因为 nums[0] 和 nums[1] 的和虽然为 6，但它们是相等的。
//提示：
//2 <= nums.length <= 100
//- 100 <= nums[i], target <= 100

int* maxProductPair(int* nums, int numsSize, int target, int* returnSize) {
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
	int* hash = (int*)calloc(size, sizeof(int));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		hash[key] = 1;
	}
	int tmp[3] = { 1, -1, -1 };
	for (int i = 0; i < numsSize; i++) {
		int num1 = nums[i], num2 = target - nums[i];
		int key = num2 - min;
		if (key >= 0 && key < size && hash[key] && num1 != num2) {
			int mul = num1 * num2;
			if (tmp[0] == 1 || mul > tmp[0]) {
				tmp[0] = mul;
				tmp[1] = num1 > num2 ? num1 - min : num2 - min;
				tmp[2] = num1 > num2 ? num2 - min : num1 - min;
			}
		}
	}
	free(hash);
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	ans[0] = ans[1] = -1;
	if (tmp[0] != 1) {
		for (int i = 0; i < numsSize; i++) {
			if (nums[i] == tmp[1] + min) {
				ans[0] = i;
			}
			else if (nums[i] == tmp[2] + min) {
				ans[1] = i;
			}
			if (ans[0] != -1 && ans[1] != -1) {
				break;
			}
		}
	}
	return ans;
}