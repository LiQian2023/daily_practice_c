#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.08.30力扣网刷题
//大于等于顺序前缀和的最小缺失整数——数组、哈希表、排序——简单
//给你一个下标从 0 开始的整数数组 nums 。
//如果一个前缀 nums[0..i] 满足对于 1 <= j <= i 的所有元素都有 nums[j] = nums[j - 1] + 1 ，
//那么我们称这个前缀是一个 顺序前缀 。特殊情况是，只包含 nums[0] 的前缀也是一个 顺序前缀 。
//请你返回 nums 中没有出现过的 最小 整数 x ，满足 x 大于等于 最长 顺序前缀的和。
//示例 1：
//输入：nums = [1, 2, 3, 2, 5]
//输出：6
//解释：nums 的最长顺序前缀是[1, 2, 3] ，和为 6 ，6 不在数组中，所以 6 是大于等于最长顺序前缀和的最小整数。
//示例 2：
//输入：nums = [3, 4, 5, 1, 12, 14, 13]
//输出：15
//解释：nums 的最长顺序前缀是[3, 4, 5] ，和为 12 ，12、13 和 14 都在数组中，但 15 不在，所以 15 是大于等于最长顺序前缀和的最小整数。
//提示：
//1 <= nums.length <= 50
//1 <= nums[i] <= 50
void CountSort(int* a, int n) {
	int nums[51] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		nums[a[i]] += 1;
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	n = 0;
	for (int i = min; i <= max; i++) {
		while (nums[i]) {
			a[n++] = i;
			nums[i] -= 1;
		}
	}
}
int missingInteger(int* nums, int numsSize) {
	int ans = nums[0];
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1] + 1) {
			ans += nums[i];
		}
		else {
			break;
		}
	}
	CountSort(nums, numsSize);
	int l = 0, r = numsSize - 1;
	while (l <= r) {
		int mid = (r - l) / 2 + l;
		if (nums[mid] <= ans)
			l = mid + 1;
		else {
			r = mid - 1;
		}
	}
	while (l < numsSize) {
		if (nums[l] > ans + 1)
			break;
		else {
			ans += 1;
			l++;
		}
	}
	if (nums[l - 1] == ans)
		ans += 1;
	return ans;
}