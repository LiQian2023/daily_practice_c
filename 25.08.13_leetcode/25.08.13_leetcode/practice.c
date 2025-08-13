#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//2025.08.13力扣网刷题
//3 的幂——递归、数学——简单
//给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
//整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
//示例 1：
//输入：n = 27
//输出：true
//示例 2：
//输入：n = 0
//输出：false
//示例 3：
//输入：n = 9
//输出：true
//示例 4：
//输入：n = 45
//输出：false
//提示：
//- 2^31 <= n <= 2^31 - 1
//进阶：你能不使用循环或者递归来完成本题吗？

bool isPowerOfThree(int n) {
	if (n <= 0) {
		return false;
	}
	double result = log(n) / log(3);
	return fabs(result - rint(result)) < 1e-15;
}