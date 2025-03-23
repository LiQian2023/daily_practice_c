#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//2025.03.24力扣网刷题
//统计是给定字符串前缀的字符串数目——数组、字符串——简单
//给你一个字符串数组 words 和一个字符串 s ，其中 words[i] 和 s 只包含 小写英文字母 。
//请你返回 words 中是字符串 s 前缀 的 字符串数目 。
//一个字符串的 前缀 是出现在字符串开头的子字符串。子字符串 是一个字符串中的连续一段字符序列。
//示例 1：
//输入：words = ["a", "b", "c", "ab", "bc", "abc"], s = "abc"
//输出：3
//解释：
//words 中是 s = "abc" 前缀的字符串为：
//"a" ，"ab" 和 "abc" 。
//所以 words 中是字符串 s 前缀的字符串数目为 3 。
//示例 2：
//输入：words = ["a", "a"], s = "aa"
//输出：2
//解释：
//两个字符串都是 s 的前缀。
//注意，相同的字符串可能在 words 中出现多次，它们应该被计数多次。
//提示：
//1 <= words.length <= 1000
//1 <= words[i].length, s.length <= 10
//words[i] 和 s 只 包含小写英文字母。

typedef struct Hash {
	char* str;
	int len;
}Hash;

int countPrefixes(char** words, int wordsSize, char* s) {
	int len = strlen(s);
	Hash* h = (Hash*)calloc(len, sizeof(Hash));
	assert(h);
	for (int i = 0; i < len; i++) {
		h[i].len = i + 2;
		h[i].str = (char*)calloc(h[i].len, sizeof(char));
		assert(h[i].str);
		for (int j = 0; j <= i; j++) {
			h[i].str[j] = s[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < wordsSize; i++) {
		int key = strlen(words[i]) - 1;
		if (key < len) {
			if (strcmp(words[i], h[key].str) == 0) {
				ans += 1;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		free(h[i].str);
		h[i].str = NULL;
	}
	free(h);
	h = NULL;
	return ans;
}