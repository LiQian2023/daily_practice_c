#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.11.17力扣网刷题
//不用加号的加法——位运算、数学——简单
//设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。
//示例 :
//输入: a = 1, b = 1
//输出 : 2
//提示：
//a, b 均可能是负数或 0
//结果不会溢出 32 位整数

int add(int a, int b) {
	unsigned int sum = a ^ b;
	unsigned int carry = a & b;
	while (carry) {
		a = carry << 1;
		b = sum;
		sum = a ^ b;
		carry = a & b;
	}
	return sum;
}