#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2023.12.21力扣网刷题
//有效的完全平方数——数学、二分查找——简单
//给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
//完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
//不能使用任何内置的库函数，如  sqrt 。
//示例 1：
//输入：num = 16
//输出：true
//解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
//示例 2：
//输入：num = 14
//输出：false
//解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
//提示：
//1 <= num <= 2^31 - 1

//法一：二分查找
bool isPerfectSquare1(int num) {
	if (num == 1)
		return true;
	int l = 1, r = num / 2;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (m > num / m)
			r = m - 1;
		else if (m < num / m)
			l = m + 1;
		else if (m == num / m && 0 == num % m)
			return m;
		else
			break;
	}
	return 0;
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		if (isPerfectSquare(n))
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}

