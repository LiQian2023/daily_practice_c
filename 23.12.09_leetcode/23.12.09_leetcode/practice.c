#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//2023.12.09力扣网刷题
// 回文数——数学——简单
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//例如，121 是回文，而 123 不是。
//示例 1：
//输入：x = 121
//输出：true
//示例 2：
//输入：x = -121
//输出：false
//解释：从左向右读, 为 - 121 。 从右向左读, 为 121 - 。因此它不是一个回文数。
//示例 3：
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
//提示：
//- 2^31 <= x <= 2^31 - 1
//进阶：你能不将整数转为字符串来解决这个问题吗？


//法一：逆序法
bool isPalindrome(int x) {
	if (x < 0)
		return false;
	else
	{
		int a[10] = { 0 };
		int b[10] = { 0 };
		int i = 0;
		int j = 0;
		int sum = 0;
		for (x; x > 0; x /= 10)
		{
			a[i] = x % 10;
			i++;
		}
		for (i -= 1; i >= 0; i--)
		{
			b[j] = a[i];
			j++;
		}
		for (i+=1; i < j; i++)
		{
			sum += a[i] ^ b[i];
		}
		i -= 1;
		if (sum == 0 || sum == a[i / 2])
			return true;
		return false;
	}
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		bool ret = isPalindrome(n);
		if (ret)
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}