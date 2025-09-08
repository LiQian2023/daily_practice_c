#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//2025.09.09力扣网刷题
//验证回文串——双指针、字符串——简单
//给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。
//本题中，将空字符串定义为有效的 回文串 。
//示例 1：
//输入 : s = "A man, a plan, a canal: Panama"
//输出 : true
//解释："amanaplanacanalpanama" 是回文串
//示例 2：
//输入 : s = "race a car"
//输出 : false
//解释："raceacar" 不是回文串
//提示：
//1 <= s.length <= 2 * 105
//字符串 s 由 ASCII 字符组成
//注意：本题与主站 125 题相同： https ://leetcode-cn.com/problems/valid-palindrome/

bool isPalindrome(char* s) {
	int len = strlen(s);
	for (int l = 0, r = len - 1; l <= r; l++, r--) {
		while (l < len && !isalnum(s[l])) {
			l += 1;
		}
		while (r >= 0 && !isalnum(s[r])) {
			r -= 1;
		}
		if (l < r && tolower(s[l]) != tolower(s[r])) {
			return false;
		}
	}
	return true;
}