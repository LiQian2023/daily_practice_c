#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.10.06力扣网刷题
//统计位数为偶数的数字——数组、数学——简单
//给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。
//示例 1：
//输入：nums = [12, 345, 2, 6, 7896]
//输出：2
//解释：
//12 是 2 位数字（位数为偶数）
//345 是 3 位数字（位数为奇数）
//2 是 1 位数字（位数为奇数）
//6 是 1 位数字 位数为奇数）
//7896 是 4 位数字（位数为偶数）
//因此只有 12 和 7896 是位数为偶数的数字
//示例 2：
//输入：nums = [555, 901, 482, 1771]
//输出：1
//解释：
//只有 1771 是位数为偶数的数字。
//提示：
//1 <= nums.length <= 500
//1 <= nums[i] <= 10^5


int findNumbers(int* nums, int numsSize) {
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		int n = 0;
		while (nums[i]) {
			n += 1;
			nums[i] /= 10;
		}
		if (n % 2 == 0)
			ans += 1;
	}
	return ans;
}

#if 0
//最大整除子集——数组、数学、动态规划、排序——中等
//给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对(answer[i], answer[j]) 都应当满足：
//answer[i] % answer[j] == 0 ，或
//answer[j] % answer[i] == 0
//如果存在多个有效解子集，返回其中任何一个均可。
//示例 1：
//输入：nums = [1, 2, 3]
//输出：[1, 2]
//解释：[1, 3] 也会被视为正确答案。
//示例 2：
//输入：nums = [1, 2, 4, 8]
//输出：[1, 2, 4, 8]
//提示：
//1 <= nums.length <= 1000
//1 <= nums[i] <= 2 * 10^9
//nums 中的所有整数 互不相同


int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {

}
#endif