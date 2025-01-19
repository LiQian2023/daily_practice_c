#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//2025.01.19力扣网刷题
//数组中字符串的最大值——数组、字符串——简单
//一个由字母和数字组成的字符串的 值 定义如下：
//如果字符串 只 包含数字，那么值为该字符串在 10 进制下的所表示的数字。
//否则，值为字符串的 长度 。
//给你一个字符串数组 strs ，每个字符串都只由字母和数字组成，请你返回 strs 中字符串的 最大值 。
//示例 1：
//输入：strs = ["alic3", "bob", "3", "4", "00000"]
//输出：5
//解释：
//- "alic3" 包含字母和数字，所以值为长度 5 。
//- "bob" 只包含字母，所以值为长度 3 。
//- "3" 只包含数字，所以值为 3 。
//- "4" 只包含数字，所以值为 4 。
//- "00000" 只包含数字，所以值为 0 。
//所以最大的值为 5 ，是字符串 "alic3" 的值。
//示例 2：
//输入：strs = ["1", "01", "001", "0001"]
//输出：1
//解释：
//数组中所有字符串的值都是 1 ，所以我们返回 1 。
//提示：
//1 <= strs.length <= 100
//1 <= strs[i].length <= 9
//strs[i] 只包含小写英文字母和数字。 

bool Isdigit(char* strs) {
	for (int i = 0; strs[i]; i++) {
		if (isalpha(strs[i]))
			return false;
	}
	return true;
}

int maximumValue(char** strs, int strsSize) {
	int max = 0;
	for (int i = 0; i < strsSize; i++) {
		int len = strlen(strs[i]);
		if (Isdigit(strs[i])) {
			int tmp = 0;
			for (int j = 0; j < len;j++) {
				tmp *= 10;
				tmp += strs[i][j] - '0';
			}
			if (tmp > max) {
				max = tmp;
			}
		}
		else {
			if (len > max)
				max = len;
		}
	}
	return max;
}