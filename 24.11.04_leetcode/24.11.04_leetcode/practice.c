#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
//2024.11.04力扣网刷题
//平方数之和——数学、双指针、二分查找——中等
//给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。
//示例 1：
//输入：c = 5
//输出：true
//解释：1 * 1 + 2 * 2 = 5
//示例 2：
//输入：c = 3
//输出：false
//提示：
//0 <= c <= 2^31 - 1

bool isSquare(int x) {
	int a = sqrt(x);
	for (int i = 1; i <= sqrt(x); i++) {
		if (x == i * i) {
			printf("%d * %d = %d\n", i, i, i * i);
			printf("%d\n", x);
			return true;
		}
	}
	return false;
}

bool judgeSquareSum(int c) {
	for (int a = 1; a <= sqrt(c / 2); a++) {
		int b = c - a * a;
		int x = sqrt(b);
		if (x * x == b) {
			printf("a = %d\nb = %d\n", a, b);
			return true;
		}
	}
	return false;
}

void test() {
	printf("%d\n", judgeSquareSum(INT_MAX));
	printf("%d\n", 205 * 205 + 46340 * 46340);
	printf("%d\n", INT_MAX);
}

int main() {
	test();
	return 0;
}