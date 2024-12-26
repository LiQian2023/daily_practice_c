#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2024.12.26力扣网刷题
//字符串及其反转中是否存在同一子字符串——哈希表、字符串——简单
//给你一个字符串 s ，请你判断字符串 s 是否存在一个长度为 2 的子字符串，在其反转后的字符串中也出现。
//如果存在这样的子字符串，返回 true；如果不存在，返回 false 。
//示例 1：
//输入：s = "leetcode"
//输出：true
//解释：子字符串 "ee" 的长度为 2，它也出现在 reverse(s) == "edocteel" 中。
//示例 2：
//输入：s = "abcba"
//输出：true
//解释：所有长度为 2 的子字符串 "ab"、"bc"、"cb"、"ba" 也都出现在 reverse(s) == "abcba" 中。
//示例 3：
//输入：s = "abcd"
//输出：false
//解释：字符串 s 中不存在满足「在其反转后的字符串中也出现」且长度为 2 的子字符串。
//提示：
//1 <= s.length <= 100
//字符串 s 仅由小写英文字母组成。
void Reverse(char* s, int len) {
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
bool isSubstringPresent(char* s) {
	int length = strlen(s);
	char hash[26][26] = { 0 };
	for (int i = 0; i < length - 1; i++) {
		int key1 = s[i] - 'a';
		int key2 = s[i + 1] - 'a';
		hash[key1][key2] = 1;
	}
	Reverse(s, length);
	for (int i = 0; i < length - 1; i++) {
		int key1 = s[i] - 'a';
		int key2 = s[i + 1] - 'a';
		if (hash[key1][key2]) {
			return true;
		}
	}
	return false;
}