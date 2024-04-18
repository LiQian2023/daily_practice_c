#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2024.04.15力扣网刷题
//二进制表示中质数个计算置位——位运算、数学——简单
//给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。
//计算置位位数 就是二进制表示中 1 的个数。
//例如， 21 的二进制表示 10101 有 3 个计算置位。
//示例 1：
//输入：left = 6, right = 10
//输出：4
//解释：
//6 -> 110 (2 个计算置位，2 是质数)
//7 -> 111 (3 个计算置位，3 是质数)
//9 -> 1001 (2 个计算置位，2 是质数)
//10-> 1010 (2 个计算置位，2 是质数)
//共计 4 个计算置位为质数的数字。
//示例 2：
//输入：left = 10, right = 15
//输出：5
//解释：
//10 -> 1010 (2 个计算置位, 2 是质数)
//11 -> 1011 (3 个计算置位, 3 是质数)
//12 -> 1100 (2 个计算置位, 2 是质数)
//13 -> 1101 (3 个计算置位, 3 是质数)
//14 -> 1110 (3 个计算置位, 3 是质数)
//15 -> 1111 (4 个计算置位, 4 不是质数)
//共计 5 个计算置位为质数的数字。
//提示：
//1 <= left <= right <= 10^6
//0 <= right - left <= 10^4

int countPrimeSetBits(int left, int right) {
	int count = 0;
	for (int i = left; i <= right; i++) {
		int sum = 0;
		//计算1的个数
		for (int a = i; a; a >>= 1) {
			if (a & 1)
				sum++;
		}
		if (sum == 1)
			continue;
		//判断计算置位是否为质数
		int j = 2;
		for (j; j <= sqrt(sum); j++) {
			if (sum % j == 0)
				break;
		}
		if (j > sqrt(sum))
			count++;
	}
	return count;
}