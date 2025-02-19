#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//2025.02.20力扣网刷题
//奇偶位数——位运算——简单
//给你一个 正 整数 n 。
//用 even 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的偶数下标的个数。
//用 odd 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的奇数下标的个数。
//返回整数数组 answer ，其中 answer = [even, odd] 。
//示例 1：
//输入：n = 17
//输出：[2, 0]
//解释：17 的二进制形式是 10001 。
//下标 0 和 下标 4 对应的值为 1 。
//共有 2 个偶数下标，0 个奇数下标。
//示例 2：
//输入：n = 2
//输出：[0, 1]
//解释：2 的二进制形式是 10 。
//下标 1 对应的值为 1 。
//共有 0 个偶数下标，1 个奇数下标。
//提示：
//1 <= n <= 1000

int* evenOddBit(int n, int* returnSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	ans[0] = 0;
	ans[1] = 0;
	for (int i = 0; i < 32; i++) {
		if (i % 2) {
			ans[1] += n & 1;
		}
		else {
			ans[0] += n & 1;
		}
		n >>= 1;
	}
	return ans;
}