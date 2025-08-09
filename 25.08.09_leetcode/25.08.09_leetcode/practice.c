#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
//2025.08.09力扣网刷题
//2 的幂——位运算、递归、数学——简单
//给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
//如果存在一个整数 x 使得 n == 2^x ，则认为 n 是 2 的幂次方。
//示例 1：
//输入：n = 1
//输出：true
//解释：20 = 1
//示例 2：
//输入：n = 16
//输出：true
//解释：24 = 16
//示例 3：
//输入：n = 3
//输出：false
//提示：
//- 2^31 <= n <= 2^31 - 1
//进阶：你能够不使用循环 / 递归解决此问题吗？

bool isPowerOfTwo(int n) {
	return fabs(log2((double)n) - trunc(log2((double)n))) < 1e-10;
}