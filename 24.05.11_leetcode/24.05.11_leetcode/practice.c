#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
//2024.05.11力扣网刷题
//反转两次的数字——数学——简单
//反转 一个整数意味着倒置它的所有位。
//例如，反转 2021 得到 1202 。反转 12300 得到 321 ，不保留前导零 。
//给你一个整数 num ，反转 num 得到 reversed1 ，接着反转 reversed1 得到 reversed2 。如果 reversed2 等于 num ，返回 true ；否则，返回 false 。
//示例 1：
//输入：num = 526
//输出：true
//解释：反转 num 得到 625 ，接着反转 625 得到 526 ，等于 num 。
//示例 2：
//输入：num = 1800
//输出：false
//解释：反转 num 得到 81 ，接着反转 81 得到 18 ，不等于 num 。
//示例 3：
//输入：num = 0
//输出：true
//解释：反转 num 得到 0 ，接着反转 0 得到 0 ，等于 num 。
//提示：
//0 <= num <= 10^6

bool isSameAfterReversals(int num) {
	int count = 0;
	int a = num;
	while (a) {
		count++;
		a /= 10;
	}
	if (count == 0 || count == 1)
		return true;
	int* arr = (int*)calloc(count, sizeof(int));
	assert(arr);
	a = num;
	//第一次反转
	for (int i = 0; a; i++) {
		arr[i] = a % 10;
		a /= 10;
	}
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum = sum * 10 + arr[i];
		arr[i] = 0;
	}
	//第二次反转
	int i = 0;
	for (i; sum; i++) {
		arr[i] = sum % 10;
		sum /= 10;
	}
	for (int j = 0; j < i; j++)
		sum = sum * 10 + arr[j];
	if (sum == num)
		return true;
	return false;
}

bool isSameAfterReversals(int num) {
	int a = num;
	int sum = 0;
	while (a) {
		sum = sum * 10 + a % 10;
		a /= 10;
	}
	a = sum;
	sum = 0;
	while (a) {
		sum = sum * 10 + a % 10;
		a /= 10;
	}
	if (sum == num)
		return true;
	return false;
}

bool isSameAfterReversals(int num) {
	if (num == 0 || num % 10 != 0)
		return true;
	return false;
}