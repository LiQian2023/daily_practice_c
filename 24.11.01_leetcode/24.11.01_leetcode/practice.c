#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

//2024.11.01力扣网刷题
//求出数字答案——数学——简单
//给你三个 正 整数 num1 ，num2 和 num3 。
//数字 num1 ，num2 和 num3 的数字答案 key 是一个四位数，定义如下：
//一开始，如果有数字 少于 四位数，给它补 前导 0 。
//答案 key 的第 i 个数位（1 <= i <= 4）为 num1 ，num2 和 num3 第 i 个数位中的 最小 值。
//请你返回三个数字 没有 前导 0 的数字答案。
//示例 1：
//输入：num1 = 1, num2 = 10, num3 = 1000
//输出：0
//解释：
//补前导 0 后，num1 变为 "0001" ，num2 变为 "0010" ，num3 保持不变，为 "1000" 。
//数字答案 key 的第 1 个数位为 min(0, 0, 1) 。
//数字答案 key 的第 2 个数位为 min(0, 0, 0) 。
//数字答案 key 的第 3 个数位为 min(0, 1, 0) 。
//数字答案 key 的第 4 个数位为 min(1, 0, 0) 。
//所以数字答案为 "0000" ，也就是 0 。
//示例 2：
//输入： num1 = 987, num2 = 879, num3 = 798
//输出：777
//示例 3：
//输入：num1 = 1, num2 = 2, num3 = 3
//输出：1
//提示：
//1 <= num1, num2, num3 <= 9999

//方法一：暴力求解
int Min(int a, int b, int c) {
	int ans = a > b ? b : a;
	ans = ans > c ? c : ans;
	return ans;
}
int generateKey(int num1, int num2, int num3) {
	int tmp1[4] = { 0 };
	int tmp2[4] = { 0 };
	int tmp3[4] = { 0 };
	for (int i = 3; i >= 0; i--) {
		tmp1[i] = num1 % 10;
		tmp2[i] = num2 % 10;
		tmp3[i] = num3 % 10;
		num1 /= 10;
		num2 /= 10;
		num3 /= 10;
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans *= 10;
		ans += Min(tmp1[i], tmp2[i], tmp3[i]);
	}
	return ans;
}