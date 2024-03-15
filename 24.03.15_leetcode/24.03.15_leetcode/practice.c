#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.03.15力扣网刷题
//两整数之和——位运算、数学——中等
//给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
//示例 1：
//输入：a = 1, b = 2
//输出：3
//示例 2：
//输入：a = 2, b = 3
//输出：5
//提示：
//- 1000 <= a, b <= 1000

int getSum(int a, int b) {
	if (a >= 0 && b >= 0) {
		while (a & b) {
			int sum = (a & b) << 1;//进位信息
			a ^= b;
			b = sum;
		}
	}
	else if (a >= 0 && b <= 0) {
		b = -b;
		while (a & b) {
			int sum = (a & b) >> 1;//进位信息
			a ^= b;
			b = sum;
		}
	}
	else if (a <= 0 && b >= 0) {
		a = -a;
		while (a & b) {
			int sum = (a & b) >> 1;//进位信息
			a ^= b;
			b = sum;
		}
	}
	else {
		a = -a, b = -b;
		while (a & b) {
			int sum = (a & b) << 1;//进位信息
			a ^= b;
			b = sum;
		}
		a = -a;
	}
	return a;
}