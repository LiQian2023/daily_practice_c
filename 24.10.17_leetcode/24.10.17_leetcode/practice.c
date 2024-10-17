#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2024.10.17力扣网刷题
//通过删除字母匹配到字典里最长单词——数字、双指针、字符串、排序——中等
//给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。
//如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。
//示例 1：
//输入：s = "abpcplea", dictionary = ["ale", "apple", "monkey", "plea"]
//输出："apple"
//示例 2：
//输入：s = "abpcplea", dictionary = ["a", "b", "c"]
//输出："a"
//提示：
//1 <= s.length <= 1000
//1 <= dictionary.length <= 1000
//1 <= dictionary[i].length <= 1000
//s 和 dictionary[i] 仅由小写英文字母组成

int ch_cmp(const void* p1, const void* p2) {
	return *(char*)p1 - *(char*)p2;
}
int str_cmp(const void** p1, const void** p2) {
	char* a = *(char**)p1;
	char* b = *(char**)p2;
	int len1 = strlen(a);
	int len2 = strlen(b);
	if (len1 != len2)
		return len2 - len1;
	return strcmp(a, b);
}
char* Index(char* s, int len1, char* t, int len2) {
	int i = 0, j = 0;
	while (i < len1 && j < len2) {
		if (s[i] == t[j]) {
			i += 1;
			j += 1;
		}
		else {
			i += 1;
		}
	}
	if (j == len2)
		return t;
	return NULL;
}
char* findLongestWord(char* s, char** dictionary, int dictionarySize) {
	qsort(dictionary, dictionarySize, sizeof(char*), str_cmp);
	int len1 = strlen(s);
	//qsort(s, len1, sizeof(char), ch_cmp);
	char* ans = NULL;
	for (int i = 0; i < dictionarySize && !ans; i++) {
		int len2 = strlen(dictionary[i]);
		//qsort(dictionary[i], len2, sizeof(char), ch_cmp);
		ans = Index(s, len1, dictionary[i], len2);
	}
	return ans ? ans : "";
}