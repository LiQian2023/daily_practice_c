#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
//2025.07.19力扣网刷题
//检查两个字符串数组是否相等——数组、字符串、第216场周赛——简单
//给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。
//数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
//示例 1：
//输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
//输出：true
//解释：
//word1 表示的字符串为 "ab" + "c" -> "abc"
//word2 表示的字符串为 "a" + "bc" -> "abc"
//两个字符串相同，返回 true
//示例 2：
//输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
//输出：false
//示例 3：
//输入：word1 = ["abc", "d", "defg"], word2 = ["abcddefg"]
//输出：true
//提示：
//1 <= word1.length, word2.length <= 103
//1 <= word1[i].length, word2[i].length <= 103
//1 <= sum(word1[i].length), sum(word2[i].length) <= 103
//word1[i] 和 word2[i] 由小写字母组成

int Get_len(char** word, int wordSize) {
	int len = 0;
	for (int i = 0; i < wordSize; i++) {
		len += strlen(word[i]);
	}
	return len;
}
void Str_cat(char* str, char** word, int wordSize) {
	for (int i = 0; i < wordSize; i++) {
		strcat(str, word[i]);
	}
}

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
	int size1 = Get_len(word1, word1Size);
	int size2 = Get_len(word2, word2Size);
	char* str1 = (char*)calloc(size1 + 1, sizeof(char));
	assert(str1);
	char* str2 = (char*)calloc(size2 + 1, sizeof(char));
	assert(str2);
	Str_cat(str1, word1, word1Size);
	Str_cat(str2, word2, word2Size);
	bool flag = strcmp(str1, str2) == 0;
	free(str1);
	str1 = NULL;
	free(str2);
	str2 = NULL;
	return flag;
}