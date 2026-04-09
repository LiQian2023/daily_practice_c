#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.04.09力扣网刷题
//LCR 072. x 的平方根——数学、二分查找——简单
//给定一个非负整数 x ，计算并返回 x 的平方根，即实现 int sqrt(int x) 函数。
//正数的平方根有两个，只输出其中的正数平方根。
//如果平方根不是整数，输出只保留整数的部分，小数部分将被舍去。
//示例 1：
//输入 : x = 4
//输出 : 2
//示例 2：
//输入 : x = 8
//输出 : 2
//解释 : 8 的平方根是 2.82842...，由于小数部分将被舍去，所以返回 2
//提示：
//0 <= x <= 2^31 - 1
//注意：本题与主站 69 题相同： https ://leetcode.cn/problems/sqrtx/




int mySqrt(int x) {
	if (x == 0) {
		return 0;
	}
	int l = 0, r = x;
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (m == 0) {
			break;
		}
		if (m == x / m) {
			return m;
		}
		else if (m > x / m) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return r;
}