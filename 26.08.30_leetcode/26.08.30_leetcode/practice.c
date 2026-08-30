#include <stdio.h>

//2026.08.30力扣网刷题
//2091. 从数组中移除最大值和最小值——资深工程师、贪心、数组、第269场周赛——中等
//给你一个下标从 0 开始的数组 nums ，数组由若干 互不相同 的整数组成。
//nums 中有一个值最小的元素和一个值最大的元素。分别称为 最小值 和 最大值 。你的目标是从数组中移除这两个元素。
//一次 删除 操作定义为从数组的 前面 移除一个元素或从数组的 后面 移除一个元素。
//返回将数组中最小值和最大值 都 移除需要的最小删除次数。
//示例 1：
//输入：nums = [2, 10, 7, 5, 4, 1, 8, 6]
//输出：5
//解释：
//数组中的最小元素是 nums[5] ，值为 1 。
//数组中的最大元素是 nums[1] ，值为 10 。
//将最大值和最小值都移除需要从数组前面移除 2 个元素，从数组后面移除 3 个元素。
//结果是 2 + 3 = 5 ，这是所有可能情况中的最小删除次数。
//示例 2：
//输入：nums = [0, -4, 19, 1, 8, -2, -3, 5]
//输出：3
//解释：
//数组中的最小元素是 nums[1] ，值为 - 4 。
//数组中的最大元素是 nums[2] ，值为 19 。
//将最大值和最小值都移除需要从数组前面移除 3 个元素。
//结果是 3 ，这是所有可能情况中的最小删除次数。
//示例 3：
//输入：nums = [101]
//输出：1
//解释：
//数组中只有这一个元素，那么它既是数组中的最小值又是数组中的最大值。
//移除它只需要 1 次删除操作。
//提示：
//1 <= nums.length <= 10^5
//- 10^5 <= nums[i] <= 10^5
//nums 中的整数 互不相同

int minimumDeletions(int* nums, int numsSize) {
	int ind_max = 0, ind_min = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > nums[ind_max]) {
			ind_max = i;
		}
		else if (nums[i] < nums[ind_min]) {
			ind_min = i;
		}
	}
	int a = ind_min + 1, b = numsSize - ind_min, c = ind_max + 1, d = numsSize - ind_max;
	int left = ind_min > ind_max ? a : c;
	int right = ind_min > ind_max ? d : b;
	int both = a + d < b + c ? a + d : b + c;
	int ans = left < right ? left : right;
	ans = ans < both ? ans : both;
	return ans;
}