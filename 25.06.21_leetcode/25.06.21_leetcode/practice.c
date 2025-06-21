#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//2025.06.21力扣网刷题
//统计平方和三元组的数目——数学、枚举——简单
//一个 平方和三元组(a, b, c) 指的是满足 a2 + b2 = c2 的 整数 三元组 a，b 和 c 。
//给你一个整数 n ，请你返回满足 1 <= a, b, c <= n 的 平方和三元组 的数目。
//示例 1：
//输入：n = 5
//输出：2
//解释：平方和三元组为(3, 4, 5) 和(4, 3, 5) 。
//示例 2：
//输入：n = 10
//输出：4
//解释：平方和三元组为(3, 4, 5)，(4, 3, 5)，(6, 8, 10) 和(8, 6, 10) 。
//提示：
//1 <= n <= 250

int countTriples(int n) {
	int ans = 0;
	for (int a = 3; a < n; a++) {
		for (int b = 3; b < n; b++) {
			for (int c = 5; c <= n; c++) {
				if (a * a + b * b == c * c) {
					ans += 1;
				}
			}
		}
	}
	return ans;
}

int countTriples(int n) {
	int ans = 0;
	for (int a = 3; a < n; a++) {
		for (int b = 3; b < n; b++) {
			int c = (int)sqrt(a * a + b * b);
			if (c <= n && c * c == a * a + b * b) {
				ans += 1;
			}
		}
	}
	return ans;
}