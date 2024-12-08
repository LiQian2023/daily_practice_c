#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

//2024.12.08力扣网刷题
//整数转换为两个无零整数的和——数学——简单
//无零整数」是十进制表示中 不含任何 0 的正整数。
//给你一个整数 n，请你返回一个 由两个整数组成的列表[a, b]，满足：
//a 和 b 都是无零整数
//a + b = n
//题目数据保证至少有一个有效的解决方案。
//如果存在多个有效解决方案，你可以返回其中任意一个。
//示例 1：
//输入：n = 2
//输出：[1, 1]
//解释：a = 1, b = 1。a + b = n 并且 a 和 b 的十进制表示形式都不包含任何 0。
//示例 2：
//输入：n = 11
//输出：[2, 9]
//示例 3：
//输入：n = 10000
//输出：[1, 9999]
//示例 4：
//输入：n = 69
//输出：[1, 68]
//示例 5：
//输入：n = 1010
//输出：[11, 999]
//提示：
//2 <= n <= 10^4

bool NoZero(int x) {
	while (x) {
		if (x % 10 == 0)
			return false;
		x /= 10;
	}
	return true;
}

int* getNoZeroIntegers(int n, int* returnSize) {
	*returnSize = 2;
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	for (int i = 1; i < n; i++) {
		ans[0] = i;
		ans[1] = n - i;
		if (NoZero(ans[0]) && NoZero(ans[1]))
			break;
	}
	return ans;
}