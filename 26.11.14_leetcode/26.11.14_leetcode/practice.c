#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.11.14力扣网刷题
//3364. 最小正和子数组——中级工程师、数组、前缀和、滑动窗口、第425场周赛——简单
//给你一个整数数组 nums 和 两个 整数 l 和 r。你的任务是找到一个长度在 l 和 r 之间（包含）且和大于 0 的 子数组 的 最小 和。
//返回满足条件的子数组的 最小 和。如果不存在这样的子数组，则返回 - 1。
//子数组 是数组中的一个连续 非空 元素序列。
//示例 1：
//输入： nums = [3, -2, 1, 4], l = 2, r = 3
//输出： 1
//解释：
//长度在 l = 2 和 r = 3 之间且和大于 0 的子数组有：
//[3, -2] 和为 1
//[1, 4] 和为 5
//[3, -2, 1] 和为 2
//[-2, 1, 4] 和为 3
//其中，子数组[3, -2] 的和为 1，是所有正和中最小的。因此，答案为 1。
//示例 2：
//输入： nums = [-2, 2, -3, 1], l = 2, r = 3
//输出： - 1
//解释：
//不存在长度在 l 和 r 之间且和大于 0 的子数组。因此，答案为 - 1。
//示例 3：
//输入： nums = [1, 2, 3, 4], l = 2, r = 4
//输出： 3
//解释：
//子数组[1, 2] 的长度为 2，和为 3，是所有正和中最小的。因此，答案为 3。
//提示：
//1 <= nums.length <= 100
//1 <= l <= r <= nums.length
//- 1000 <= nums[i] <= 1000

int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
	int* prefix = (int*)calloc(numsSize + 1, sizeof(int));
	assert(prefix);
	for (int i = 0; i <= numsSize; i++) {
		if (i == 0) {
			prefix[i] = 0;
		}
		else {
			prefix[i] = prefix[i - 1] + nums[i - 1];
		}
	}
	int size = r - l + 1;
	int* tmp = (int*)calloc(size, sizeof(int));
	assert(tmp);
	int* tmp2 = (int*)calloc(numsSize + 1, sizeof(int));
	assert(tmp2);
	for (int i = 0; i <= numsSize; i++) {
		int begin = i - r, end = i - l;
		if (end < 0) {
			continue;
		}
		for (int j = begin, z = 0; j <= end; j++) {
			if (j < 0) {
				continue;
			}
			tmp[z++] = prefix[j];
		}
		int max = tmp[0];
		for (int j = 0; j < size; j++) {
			if (tmp[j] < prefix[i] && (max >= prefix[i] || tmp[j] > max)) {
				max = tmp[j];
			}
		}
		if (max >= prefix[i]) {
			if (i == 0) {
				tmp2[i] = -1;
			}
			else {
				tmp2[i] = tmp2[i - 1];
			}
		}
		else {
			tmp2[i] = prefix[i] - max;
		}
	}
	int ans = -1;
	for (int i = 0; i < numsSize + 1; i++) {
		if (tmp2[i] > 0 && (ans <= 0 || tmp2[i] < ans)) {
			ans = tmp2[i];
		}
	}
	free(prefix);
	free(tmp);
	free(tmp2);
	return ans;
}