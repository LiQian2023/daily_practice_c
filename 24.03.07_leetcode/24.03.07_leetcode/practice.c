#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.03.07力扣网刷题
//4的幂——位运算、递归、数学——简单
//给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。
//整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4^x
//示例 1：
//输入：n = 16
//输出：true
//示例 2：
//输入：n = 5
//输出：false
//示例 3：
//输入：n = 1
//输出：true
//提示：
//- 2^31 <= n <= 2^31 - 1
//进阶：你能不使用循环或者递归来完成本题吗？

bool isPowerOfFour1(int n) {
	if (n == 1 || n == 4 || n == 16 || n == 64 || n == 256 || n == 1024 || n == 4096 || n == 16384 || n == 65536 || n == 262144 || n == 1048576 || n == 4194306 || n == 16777216 || n == 67108864 || n == 268435456 || n == 1073741824)
		return true;
	return false;
}

bool isPowerOfFour2(int n) {
	if (n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0)
		return true;
	return false;
}