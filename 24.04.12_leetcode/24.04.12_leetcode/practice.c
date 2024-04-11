#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//2024.04.12力扣网刷题
//重复的子字符串——字符串、字符串匹配——简单
//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
//示例 1:
//输入: s = "abab"
//输出 : true
//解释 : 可由子串 "ab" 重复两次构成。
//示例 2 :
//	输入 : s = "aba"
//	输出 : false
//	示例 3 :
//	输入 : s = "abcabcabcabc"
//	输出 : true
//	解释 : 可由子串 "abc" 重复四次构成。(或子串 "abcabc" 重复两次构成。)
//	提示：
//	1 <= s.length <= 10^4
//	s 由小写英文字母组成

//方法一：朴素匹配算法（超时）
bool repeatedSubstringPattern1(char* s) {
	int len = strlen(s);
	char* ch = (char*)calloc(len, sizeof(char));
	if (!ch)
		return false;
	for (int i = 0; i < len - 1; i++) {
		//获取子串
		ch[i] = s[i];
		int j = 0, z = 0;
		for (j, z; z < len; j++, z++) {
			if (ch[j] == 0)
				j = 0;
			if (ch[j] != s[z])
				break;
		}
		if (!ch[j])
			return true;
	}
	return false;
}
//方法二：计数——无法区别个数相同但不重复的字符串
bool repeatedSubstringPattern2(char* s) {
	char ch[26] = { 0 };
	//记录每个字符出现的个数
	for (int i = 0; s[i]; i++) {
		ch[s[i] - 'a']++;
	}
	//记录字符出现的次数
	int count = 0;
	int i = 0;
	for (i; i < 26; i++) {
		if (ch[i] != 0 && ch[i] > 1) {
			count = ch[i];
			break;
		}
	}
	if (!count)
		return false;
	//判断是否为重复子字符串
	for (i += 1; i < 26; i++) {
		if (ch[i] && ch[i] != count)
			return false;
	}
	return true;
}
//方法三：双指针
bool repeatedSubstringPattern(char* s) {
	int len = strlen(s);
	if (len == 1)
		return false;
	int l = 0, r = 0, str = 0;
	for (int i = len - 1; i >= 2; i--) {
		if (len % i == 0) {
			r = i;
			str = i;
			break;
		}
	}
	//长度为质数
	if (!r) {
		while (s[r] && s[r] == s[l]) {
			r++;
		}
		if (!s[r])
			return true;
		return false;
	}
	else {
		for (l, r, str; str > 0 && s[r]; l++, r++) {
			if (l == str)//模式串遍历完，从头遍历
				l = 0;
			if (s[l] != s[r]) {//当遇到模式串与子串元素不相同，跟换模式串
				str--;
				l = 0;
				r = str;
			}
		}
	}
	if (!str)
		return false;
	return true;
}


void test() {
	char ch[10] = { 0 };
	while (scanf("%s", ch) == 1) {
		printf("%d\n", repeatedSubstringPattern(ch));
	}
}

int main() {
	test();
	return 0;
}