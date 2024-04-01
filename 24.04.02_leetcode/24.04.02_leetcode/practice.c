#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
//2024.04.02力扣网刷题
//反转字符串中的单词 III——字符串、双指针——简单
//给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//示例 1：
//输入：s = "Let's take LeetCode contest"
//输出："s'teL ekat edoCteeL tsetnoc"
//示例 2:
//输入： s = "Mr Ding"
//输出："rM gniD"
//提示：
//1 <= s.length <= 5 * 10^4
//s 包含可打印的 ASCII 字符。
//s 不包含任何开头或结尾空格。
//s 里 至少 有一个词。
//s 中的所有单词都用一个空格隔开。

char* reverseWords(char* s) {
	int l = 0, r = strlen(s) - 1;
	for (int i = r; i >= 0;) {
		if (s[i] != ' ' && i != 0)
			i--;
		else {
			if (i)
				l = i + 1;
			else
				l = i;
			//反转单词
			while (l < r) {
				char* tmp = s[l];
				s[l] = s[r];
				s[r] = tmp;
				l++, r--;
			}
			l = r = i - 1;
			i--;
		}
	}
	return s;
}