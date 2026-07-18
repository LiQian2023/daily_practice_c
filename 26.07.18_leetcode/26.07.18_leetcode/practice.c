#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.07.18力扣网刷题
//1979. 找出数组的最大公约数——中级工程师、数组、数学、数论、第255场周赛——简单
//给你一个整数数组 nums ，返回数组中最大数和最小数的 最大公约数 。
//两个数的 最大公约数 是能够被两个数整除的最大正整数。
//示例 1：
//输入：nums = [2, 5, 6, 9, 10]
//输出：2
//解释：
//nums 中最小的数是 2
//nums 中最大的数是 10
//2 和 10 的最大公约数是 2
//示例 2：
//输入：nums = [7, 5, 6, 8, 3]
//输出：1
//解释：
//nums 中最小的数是 3
//nums 中最大的数是 8
//3 和 8 的最大公约数是 1
//示例 3：
//输入：nums = [3, 3]
//输出：3
//解释：
//nums 中最小的数是 3
//nums 中最大的数是 3
//3 和 3 的最大公约数是 3
//提示：
//2 <= nums.length <= 1000
//1 <= nums[i] <= 1000

int GCD(int a, int b) {
	while (b % a) {
		int tmp = b % a;
		b = a;
		a = tmp;
	}
	return a;
}
int findGCD(int* nums, int numsSize) {
	int a = nums[0], b = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (a > nums[i]) {
			a = nums[i];
		}
		else if (b < nums[i]) {
			b = nums[i];
		}
	}
	return GCD(a, b);
}