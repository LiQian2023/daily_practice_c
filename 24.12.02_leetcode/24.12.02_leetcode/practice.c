#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//2024.12.02力扣网刷题
//公因子的数目——数学、枚举、数论——简单
//给你两个正整数 a 和 b ，返回 a 和 b 的 公 因子的数目。
//如果 x 可以同时整除 a 和 b ，则认为 x 是 a 和 b 的一个 公因子 。
//示例 1：
//输入：a = 12, b = 6
//输出：4
//解释：12 和 6 的公因子是 1、2、3、6 。
//示例 2：
//输入：a = 25, b = 30
//输出：2
//解释：25 和 30 的公因子是 1、5 。
//提示：
//1 <= a, b <= 1000

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int commonFactors(int a, int b) {
	int ans = 0;
	if (a < b) {
		Swap(&a, &b);
	}
	for (int i = 1; i <= b; i++) {
		if (0 == a % i && 0 == b % i) {
			ans += 1;
		}
	}
	return ans;
}