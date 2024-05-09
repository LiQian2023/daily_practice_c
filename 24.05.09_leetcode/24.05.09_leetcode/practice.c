#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//2024.05.09力扣网刷题
//和为零的 N 个不同整数——数组、数学——简单
//给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。
//示例 1：
//输入：n = 5
//输出：[-7, -1, 1, 3, 4]
//解释：这些数组也是正确的[-5, -1, 1, 2, 3]，[-3, -1, 2, -2, 4]。
//示例 2：
//输入：n = 3
//输出：[-1, 0, 1]
//示例 3：
//输入：n = 1
//输出：[0]
//提示：
//1 <= n <= 1000

int* sumZero(int n, int* returnSize) {
	int* ans = (int*)calloc(n, sizeof(int));
	assert(ans);
	*returnSize = n;
	int l = 0, r = n - 1;
	while (l < r) {
		ans[l] = n * (-1);
		ans[r] = n;
		l++, r--, n--;
	}
	return ans;
}