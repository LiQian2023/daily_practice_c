#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2025.09.21力扣网刷题
//子数组最大平均数 I——数组、滑动窗口——简单
//给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
//请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
//任何误差小于 10 - 5 的答案都将被视为正确答案。
//示例 1：
//输入：nums = [1, 12, -5, -6, 50, 3], k = 4
//输出：12.75
//解释：最大平均数(12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
//示例 2：
//输入：nums = [5], k = 1
//输出：5.00000
//提示：
//n == nums.length
//1 <= k <= n <= 10^5
//- 10^4 <= nums[i] <= 10^4

double findMaxAverage(int* nums, int numsSize, int k) {
	double ans = 0;
	double sub = 0;
	for (int i = 0; i < k; i++) {
		sub += nums[i];
	}
	ans = sub;
	for (int l = 0, r = k; r < numsSize; l += 1, r += 1) {
		double tmp = sub - nums[l] + nums[r];
		ans = fmax(ans, tmp);
		sub = tmp;
	}
	return ans / k;
}