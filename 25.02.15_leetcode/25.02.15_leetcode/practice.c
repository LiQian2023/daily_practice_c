#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2025.02.15力扣网刷题
//两个相同字符之间的最长子字符串——哈希表、字符串——简单
//给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 - 1 。
//子字符串 是字符串中的一个连续字符序列。
//示例 1：
//输入：s = "aa"
//输出：0
//解释：最优的子字符串是两个 'a' 之间的空子字符串。
//示例 2：
//输入：s = "abca"
//输出：2
//解释：最优的子字符串是 "bc" 。
//示例 3：
//输入：s = "cbzxy"
//输出： - 1
//解释：s 中不存在出现出现两次的字符，所以返回 - 1 。
//示例 4：
//输入：s = "cabbac"
//输出：4
//解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
//提示：
//1 <= s.length <= 300
//s 只含小写英文字母

typedef struct Hash {
	int i;//下标
	int len;//子串长度
}Hash;

int maxLengthBetweenEqualCharacters(char* s) {
	Hash hash[26] = { 0 };
	int ans = -1;
	int i = 0;
	for (i = 0; i < 26; i++) {
		hash[i].len = -1;
		hash[i].i = -1;
	}
	for (i = 0; s[i]; i++) {
		int key = s[i] - 'a';
		if (hash[key].i == -1) {
			hash[key].i = i;
		}
		else {
			int len = i - hash[key].i - 1;
			if (len > hash[key].len) {
				hash[key].len = len;
			}
		}
		if (hash[key].len > ans) {
			ans = hash[key].len;
		}
	}
	return ans;
}