#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
//2025.01.03力扣网刷题
//字符串的最大公因子——数学、字符串——简单
//对于字符串 s 和 t，只有在 s = t + t + t + ... + t + t（t 自身连接 1 次或多次）时，我们才认定 “t 能除尽 s”。
//给定两个字符串 str1 和 str2 。返回 最长字符串 x，要求满足 x 能除尽 str1 且 x 能除尽 str2 。
//示例 1：
//输入：str1 = "ABCABC", str2 = "ABC"
//输出："ABC"
//示例 2：
//输入：str1 = "ABABAB", str2 = "ABAB"
//输出："AB"
//示例 3：
//输入：str1 = "LEET", str2 = "CODE"
//输出：""
//提示：
//1 <= str1.length, str2.length <= 1000
//str1 和 str2 由大写英文字母组成

char* gcdOfStrings(char* str1, char* str2) {
	int len1 = strlen(str1), len2 = strlen(str2);
	int len = 0;
	for (int i = 0; i < len1 && i < len2; i++) {
		if (str1[i] != str2[i])
			return "";
		if (len1 % (i + 1) == 0 && len2 % (i + 1) == 0) {
			len = i + 1;
		}
	}
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	for (int i = 0; i < len; i++) {
		ans[i] = str1[i];
	}
	for (int i = 0, j = 0; i < len1; i++, j = (j + 1) % len) {
		if (str1[i] != ans[j])
			return "";
	}
	for (int i = 0, j = 0; i < len2; i++, j = (j + 1) % len) {
		if (str2[i] != ans[j])
			return "";
	}
	return ans;
}