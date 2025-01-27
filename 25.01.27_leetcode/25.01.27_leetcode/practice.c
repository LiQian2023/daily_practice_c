#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2025.01.27力扣网刷题
//连续字符——字符串——简单
//给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
//请你返回字符串 s 的 能量。
//示例 1：
//输入：s = "leetcode"
//输出：2
//解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
//示例 2：
//输入：s = "abbcccddddeeeeedcba"
//输出：5
//解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
//提示：
//1 <= s.length <= 500
//s 只包含小写英文字母。

int maxPower(char* s) {
	int len = strlen(s);
	int ans = 0, tmp = 1;
	for (int i = 1; i < len; i++) {
		if (s[i] != s[i - 1]) {
			if (tmp > ans) {
				ans = tmp;
			}
			tmp = 1;
		}
		else {
			tmp += 1;
		}
	}
	if (tmp > ans) {
		ans = tmp;
	}
	return ans;
}