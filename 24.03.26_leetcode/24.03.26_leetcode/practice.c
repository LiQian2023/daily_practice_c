#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//2024.03.26力扣网刷题
//  反转字符串中的元音字母——双指针、字符串——简单
//给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
//元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
//示例 1：
//输入：s = "hello"
//输出："holle"
//示例 2：
//输入：s = "leetcode"
//输出："leotcede"
//提示：
//1 <= s.length <= 3 * 10^5
//s 由 可打印的 ASCII 字符组成

int Judge(char ret) {
	char ch[5] = { 'a','e','i','o','u' };
	for (int i = 0; i < 5; i++) {
		if (ret == ch[i] || ret == ch[i] - 32) {
			return 1;
		}
	}
	return 0;
}

char* reverseVowels(char* s) {
	int len = strlen(s);
	int l = 0, r = len - 1;
	while (l < r) {
		if (Judge(s[l])) {
			if (Judge(s[r])) {
				char tmp = s[l];
				s[l] = s[r];
				s[r] = tmp;
				l++, r--;
			}
			else {
				r--;
			}
		}
		else {
			l++;
		}
	}
	return s;
}

int main() {
	char ch[10] = { 0 };
	while (scanf("%s", ch) == 1) {
		printf("%s\n", reverseVowels(ch));
	}
	return 0;
}