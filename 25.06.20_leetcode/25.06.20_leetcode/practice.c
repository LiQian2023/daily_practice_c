#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

//2025.06.20力扣网刷题
//最长乘积等价子数组——数组、数学、数论、枚举、滑动窗口——简单
//给你一个由 正整数 组成的数组 nums。
//如果一个数组 arr 满足 prod(arr) == lcm(arr) * gcd(arr)，则称其为 乘积等价数组 ，其中：
//prod(arr) 表示 arr 中所有元素的乘积。
//gcd(arr) 表示 arr 中所有元素的最大公因数(GCD)。
//lcm(arr) 表示 arr 中所有元素的最小公倍数(LCM)。
//返回数组 nums 的 最长 乘积等价 子数组 的长度。
//示例 1：
//输入： nums = [1, 2, 1, 2, 1, 1, 1]
//输出： 5
//解释：
//最长的乘积等价子数组是[1, 2, 1, 1, 1]，其中 prod([1, 2, 1, 1, 1]) = 2， gcd([1, 2, 1, 1, 1]) = 1，以及 lcm([1, 2, 1, 1, 1]) = 2。
//示例 2：
//输入： nums = [2, 3, 4, 5, 6]
//输出： 3
//解释：
//最长的乘积等价子数组是[3, 4, 5]。
//示例 3：
//输入： nums = [1, 2, 3, 1, 4, 5, 1]
//输出： 5
//提示：
//2 <= nums.length <= 100
//1 <= nums[i] <= 10

void Get_gcd_lcm(int* gcd,int*lcm,int b) {
	int a = *lcm;
	while (*lcm % a || *lcm % b || *lcm % *gcd) {
		*lcm += 1;
		if (a % *gcd || b % *gcd) {
			*gcd -= 1;
		}
	}
	while (a % *gcd || b % *gcd) {
		*gcd -= 1;
	}
}
int Get_prod(int* nums, int begin, int end) {
	int prod = 1;
	for (int i = begin; i <= end; i++) {
		prod *= nums[i];
	}
	return prod;
}
int maxLength(int* nums, int numsSize) {
	int gcd = nums[0], lcm = nums[0];
	int i = 0, j = 1;
	int ans = 0;
	while (i <= j && j < numsSize) {
		printf("i = %d\tj = %d\n", i, j);
		Get_gcd_lcm(&gcd, &lcm, nums[j]);
		printf("gcd = %d\tlcm = %d\n", gcd, lcm);
		int prod1 = gcd * lcm;
		int prod2 = Get_prod(nums, i, j);
		printf("prod1 = %d\tprod2 = %d\n", prod1, prod2);
		if (prod1 == prod2) {
			if (j - i + 1 > ans) {
				ans = j - i + 1;
				printf("ans = %d\n", ans);
			}
			j += 1;
		}
		else {
			i += 1;
			gcd = nums[i];
			lcm = nums[i];
			j = i + 1;
		}
	}
	return ans;
}
void test() {
	int gcd = 3, lcm = 3;
	Get_gcd_lcm(&gcd, &lcm, 1);
	printf("gcd = %d\tlcm = %d\n", gcd, lcm);
}

int main() {
	test();
	return 0;
}