#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.06.12力扣网刷题
//判断一个数是否迷人——哈希表、数学——简单
//给你一个三位数整数 n 。
//如果经过以下修改得到的数字 恰好 包含数字 1 到 9 各一次且不包含任何 0 ，那么我们称数字 n 是 迷人的 ：
//将 n 与数字 2 * n 和 3 * n 连接 。
//如果 n 是迷人的，返回 true，否则返回 false 。
//连接 两个数字表示把它们首尾相接连在一起。比方说 121 和 371 连接得到 121371 。
//示例 1：
//输入：n = 192
//输出：true
//解释：我们将数字 n = 192 ，2 * n = 384 和 3 * n = 576 连接，得到 192384576 。这个数字包含 1 到 9 恰好各一次。
//示例 2：
//输入：n = 100
//输出：false
//解释：我们将数字 n = 100 ，2 * n = 200 和 3 * n = 300 连接，得到 100200300 。这个数字不符合上述条件。
//提示：
//100 <= n <= 999

bool isFascinating(int n) {
	int tmp[11] = { 0 };
	int a = n;
	int b = 2 * n;
	int c = 3 * n;
	int i = 0;
	for (i; a || b || c; i++) {
		if (c) {
			tmp[i] = c % 10;
			c /= 10;
		}
		else if (b) {
			tmp[i] = b % 10;
			b /= 10;
		}
		else {
			tmp[i] = a % 10;
			a /= 10;
		}
	}
	int num[10] = { 0 };
	for (int j = 0; j < i; i++) {
		num[tmp[j]]++;
		if (num[tmp[j]] == 2)
			return false;
	}
	for (int j = 1; j <= 9; j++) {
		if (num[j] != 1)
			return false;
	}
	return true;
}

void test() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", isFascinating(n));
	}
}

int main() {
	test();
	return 0;
}