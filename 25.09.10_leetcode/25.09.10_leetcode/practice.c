#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//2025.09.10力扣网刷题
//验证回文串 II——贪心、双指针、字符串——简单
//给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。
//示例 1：
//输入 : s = "aba"
//输出 : true
//示例 2：
//输入 : s = "abca"
//输出 : true
//解释 : 可以删除 "c" 字符 或者 "b" 字符
//示例 3：
//输入 : s = "abc"
//输出 : false
//提示：
//1 <= s.length <= 105
//s 由小写英文字母组成
//注意：本题与主站 680 题相同： https ://leetcode-cn.com/problems/valid-palindrome-ii/

bool Delete(char* s, int len, int flag_l, int flag_r) {
	int dif = 0, l = 0, r = len - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			dif += 1;
			if (dif == 2) {
				return false;
			}
			l += flag_l, r += flag_r;
			continue;
		}
		l += 1, r -= 1;
	}
	return true;
}

bool validPalindrome(char* s) {
	int len = strlen(s);
	bool l = Delete(s, len, 1, 0);
	bool r = Delete(s, len, 0, -1);
	return l || r;
}