#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//2024.03.10力扣网刷题
//三除数——数学、数论、枚举——简单
//给你一个整数 n 。如果 n 恰好有三个正除数 ，返回 true ；否则，返回 false 。
//如果存在整数 k ，满足 n = k * m ，那么整数 m 就是 n 的一个 除数 。
//示例 1：
//输入：n = 2
//输出：false
//解释：2 只有两个除数：1 和 2 。
//示例 2：
//输入：n = 4
//输出：true
//解释：4 有三个除数：1、2 和 4 。
//提示：
//1 <= n <= 10^4

bool isThree1(int n) {
	int count = 3;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			count--;
		if (count < 0)
			break;
	}
	if (count == 0)
		return true;
	return false;
}

bool isThree2(int n) {
	switch (n) {
	case 4:
	case 9:
	case 25:
	case 49:
	case 121:
	case 169:
	case 289:
	case 361:
	case 529:
	case 841:
	case 961:
	case 1369:
	case 1681:
	case 1849:
	case 2209:
	case 2809:
	case 3481:
	case 3721:
	case 4489:
	case 5041:
	case 5329:
	case 6241:
	case 6889:
	case 7921:
	case 9409:
		return true;
	default:
		break;
	}
	return false;
}

void isprime() {
	for (int i = 1; i < 100; i++) {
		int flag = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag--;
				break;
			}
		}
		if (flag) {
			printf("%d  ", i * i);
		}
	}
}
int main() {
	isprime();
	return 0;
}