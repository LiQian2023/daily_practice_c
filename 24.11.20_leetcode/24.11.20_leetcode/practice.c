#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2024.11.20力扣网刷题
//二进制求和——位运算、数学、字符串、模拟——简单
//给定两个 01 字符串 a 和 b ，请计算它们的和，并以二进制字符串的形式输出。
//输入为 非空 字符串且只包含数字 1 和 0。
//示例 1:
//输入: a = "11", b = "10"
//输出 : "101"
//示例 2 :
//输入 : a = "1010", b = "1011"
//输出 : "10101"
//提示：
//每个字符串仅由字符 '0' 或 '1' 组成。
//1 <= a.length, b.length <= 10 ^ 4
//字符串如果不是 "0" ，就都不含前导零。
//注意：本题与主站 67 题相同：https://leetcode-cn.com/problems/add-binary/
char* addBinary(char* a, char* b) {
	int len1 = strlen(a);
	int len2 = strlen(b);
	int size = len1 + len2 + 2;
	char* ans = (char*)calloc(size, sizeof(char));
	assert(ans);
	int i = len1 - 1, j = len2 - 1, z = 0;
	//求和
	for (; i >= 0 && j >= 0; i--, j--, z++) {
		int num = a[i] - '0' + b[j] - '0';
		ans[z] += num;
		if (ans[z] > 1) {
			ans[z + 1] += ans[z] / 2;
			ans[z] %= 2;
		}
	}
	while (i >= 0) {
		ans[z] += a[i] - '0';
		if (ans[z] > 1) {
			ans[z + 1] += ans[z] / 2;
			ans[z] %= 2;
		}
		z += 1, i -= 1;
	}
	while (j >= 0) {
		ans[z] += b[j] - '0';
		if (ans[z] > 1) {
			ans[z + 1] += ans[z] / 2;
			ans[z] %= 2;
		}
		z += 1, j -= 1;
	}
	if (ans[z])
		z += 1;
	//反转
	for (int l = 0, r = z - 1; l <= r; l++, r--) {
		if (l == r) {
			ans[l] += '0';
		}
		else {
			char* tmp = ans[l] + '0';
			ans[l] = ans[r] + '0';
			ans[r] = tmp;
		}
	}
	if (ans[0] == '0')
		ans[1] = 0;
	return ans;
}