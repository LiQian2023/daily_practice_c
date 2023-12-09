#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
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


//法一：异或法
bool isPalindrome1(int x) {
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
//法二：字符串比较法
bool isPalindrome2(int x) {
	if (x < 0)
		return false;
	else
	{
		char a[11] = { 0 };
		char b[11] = { 0 };
		int i = 0;
		int j = 0;
		for (x; x > 0; x /= 10)
		{
			a[i] = x % 10 + '0';
			i++;
		}
		for (j; j < i; j++)
			b[j] = a[i - 1 - j];
		if (strcmp(a, b) == 0)
			return true;
		return false;
	}
}
//法三：元素比较法
bool isPalindrome3(int x) {
	if (x < 0)
		return false;
	else if (x >= 0 && x <= 9)
		return true;
	else
	{
		char a[11] = { 0 };
		int i = 0;
		for (x; x > 0; x /= 10)
		{
			a[i] = x % 10 + '0';
			//a[i] = x % 10 ;
			i++;
		}
		int left = 0;
		int right = i - 1;
		while (left < right)
		{
			if (a[left] != a[right])
				break;
			left++;
			right--;
		}
		if (left >= right)
			return true;
		return false;
	}
}
//法四：傻子求法
bool isPalindrome4(int x) {
	if (x < 0)
		return false;
	else if (x >= 0 && x <= 9)
		return true;
	else if (x > 10 && x < 100)
	{
		if (x == 11 || x == 22 || x == 33 || x == 44 || x == 55 || x == 66 || x == 77 || x == 88 || x == 99)
			return true;
		return false;
	}
	else if (x > 100 && x < 1000)
	{
		if (x % 10 == x / 100)
			return true;
		return false;
	}
	else if (x > 1000 && x < 10000)
	{
		if (x % 10 == x / 100)
		{
			x /= 10;
			if (x % 100 == 11 || x % 100 == 22 || x % 100 == 33 || x % 100 == 44 || x % 100 == 55 || x % 100 == 66 || x % 100 == 77 || x % 100 == 88 || x % 100 == 99)
				return true;
		}
		return false;
	}
	else
	{
		char a[11] = { 0 };
		int i = 0;
		for (x; x > 0; x /= 10)
		{
			a[i] = x % 10 + '0';
			i++;
		}
		int left = 0;
		int right = i - 1;
		while (left < right)
		{
			if (a[left] != a[right])
				break;
			left++;
			right--;
		}
		if (left >= right)
			return true;
		return false;
	}
}
//法五：分类求解法
bool isPalindrome5(int x) {
	if (x < 0)
		return false;
	else if (x >= 0 && x <= 9)
		return true;
	else if(x>10&&x<1000000000)
	{
		int a = x;
		int b = 0;
		while (a > 0)
		{
			b = b * 10 + a % 10;
			a /= 10;
		}
		if (b == x)
			return true;
		return false;
	}
	else
	{
		int a[10] = { 0 };
		int left = 0;
		int right = 9;
		for (int i = 0; i < 10; i++)
		{
			a[i] = x % 10;
			x /= 10;
		}
		while (left < right)
		{
			if (a[left] != a[right])
				break;
			left++;
			right--;
		}
		if (left > right)
			return true;
		return false;
	}
}
//法六：分类求解法——优化
bool isPalindrome5(int x) {
	if (x < 0)
		return false;
	else if (x >= 0 && x <= 9)
		return true;
	else if (x > 10 && x < 1000000000)
	{
		int a = x;
		int b = 0;
		while (a > 0)
		{
			b = b * 10 + a % 10;
			a /= 10;
		}
		if (b == x)
			return true;
		return false;
	}
	else
	{
		int a[10] = { 0 };
		int left = 0;
		int right = 9;
		for (int i = 0; i < 10; i++)
		{
			a[i] = x % 10;
			x /= 10;
		}
		while (left < 5)
		{
			if (a[left] != a[right])
				break;
			left++;
			right--;
		}
		if (left == 5)
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