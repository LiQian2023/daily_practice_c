#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//2024.03.03力扣网刷题
//完美数——数学——简单
//对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。
//给定一个 整数 n， 如果是完美数，返回 true；否则返回 false。
//示例 1：
//输入：num = 28
//输出：true
//解释：28 = 1 + 2 + 4 + 7 + 14
//1, 2, 4, 7, 和 14 是 28 的所有正因子。
//示例 2：
//输入：num = 7
//输出：false
//提示：
//1 <= num <= 10^8

bool checkPerfectNumber(int num) {
	int sum = 0;
	for (int i = 1; i < sqrt(num); i++) {
		if (num % i == 0) {
			sum += i;
			sum += num / i;
		}
	}
	if (sum == 2 * num)
		return true;
	return false;
}