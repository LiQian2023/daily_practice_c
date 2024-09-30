#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


//2024.03.14力扣网刷题——2024.09.30完成解答
//丑数 II——哈希表、数字、动态规划、堆（优先队列）——中等
//给你一个整数 n ，请你找出并返回第 n 个 丑数 。
//丑数 就是质因子只包含 2、3 和 5 的正整数。
//示例 1：
//输入：n = 10
//输出：12
//解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
//示例 2：
//输入：n = 1
//输出：1
//解释：1 通常被视为丑数。
//提示：
//1 <= n <= 1690

//方法一：模拟——超时
bool isUgly(int n) {
	while (n >= 2 && n % 2 == 0) {
		n /= 2;
	}
	while (n >= 3 && n % 3 == 0) {
		n /= 3;
	}
	while (n >= 5 && n % 5 == 0) {
		n /= 5;
	}
	if (n < 5)
		return true;
	return false;
}

int nthUglyNumber1(int n) {
	int* num = (int*)calloc(n, sizeof(int));
	assert(num);
	int i = 0;
	for (int x = 1; x < INT_MAX && i < n; x++) {
		if (isUgly(x))
			num[i++] = x;
	}
	return num[n - 1];
}
//方法二：动态规划
int nthUglyNumber(int n) {
	int* nums = (int*)calloc(n, sizeof(int));
	assert(nums);
	nums[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;
	for (int i = 1; i < n;) {
		if (nums[p2] * 2 <= nums[p3] * 3 && nums[p2] * 2 <= nums[p5] * 5) {
			nums[i] = nums[p2] * 2;
			p2 += 1;
		}
		else if (nums[p3] * 3 <= nums[p2] * 2 && nums[p3] * 3 <= nums[p5] * 5) {
			nums[i] = nums[p3] * 3;
			p3 += 1;
		}
		else if (nums[p5] * 5 <= nums[p3] * 3 && nums[p5] * 5 <= nums[p2] * 2) {
			nums[i] = nums[p5] * 5;
			p5 += 1;
		}
		//去重
		if (nums[i] != nums[i - 1])
			i += 1;
	}
	int ans = nums[n - 1];
	free(nums);
	return ans;
}

void test() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", nthUglyNumber(n));
	}
}

int main() {
	test();
	return 0;
}