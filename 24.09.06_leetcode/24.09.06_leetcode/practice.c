#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//2024.09.06力扣网刷题
//判定是否互为字符重排——哈希表、字符串、排序——简单
//给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
//示例 1：
//输入 : s1 = "abc", s2 = "bca"
//输出 : true
//示例 2：
//输入 : s1 = "abc", s2 = "bad"
//输出 : false
//说明：
//0 <= len(s1) <= 100
//0 <= len(s2) <= 100

void CountSort(char* a, int n) {
	char ch[26] = { 0 };
	for (int i = 0; i < n; i++) {
		int key = a[i] - 'a';
		ch[key] += 1;
	}
	n = 0;
	for (int i = 0; i < 26; i++) {
		while (ch[i]) {
			a[n++] = i + 'a';
			ch[i] -= 1;
		}
	}
}

bool CheckPermutation(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)
		return false;
	CountSort(s1, len1);
	CountSort(s2, len2);
	return strcmp(s1, s2) == 0;
}