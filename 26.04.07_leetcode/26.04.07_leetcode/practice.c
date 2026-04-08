#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
//2026.04.07力扣网刷题
//LCR 001. 两数相除——数学——简单
//给定两个整数 a 和 b ，求它们的除法的商 a / b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。
//注意：
//整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
//假设我们的环境只能存储 32 位有符号整数，其数值范围是[−231, 231−1]。本题中，如果除法结果溢出，则返回 231 − 1
//示例 1：
//输入：a = 15, b = 2
//输出：7
//解释：15 / 2 = truncate(7.5) = 7
//示例 2：
//输入：a = 7, b = -3
//输出： - 2
//解释：7 / -3 = truncate(-2.33333..) = -2
//示例 3：
//输入：a = 0, b = 1
//输出：0
//示例 4：
//输入：a = 1, b = 1
//输出：1
//提示 :
//-2^31 <= a, b <= 2^31 - 1
//b != 0
//注意：本题与主站 29 题相同：https://leetcode.cn/problems/divide-two-integers/


int divide(int a, int b) {
	if (a == INT_MIN && b == -1) {
		return INT_MAX;
	}
	long long aa = (long long)a;
	long long bb = (long long)b;
	int flag = 1;
	if (aa < 0) {
		aa = -aa;
		flag = -flag;
	}
	if (bb < 0) {
		bb = -bb;
		flag = -flag;
	}
	long long ans = 0;
	for (int i = 31; i >= 0; i--) {
		if ((aa >> i) >= bb) {
			aa -= bb << i;
			ans += 1ll << i;
		}
	}
	ans = flag == 1 ? ans : -ans;
	return (int)ans;
}