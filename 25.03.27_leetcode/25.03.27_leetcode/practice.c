#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//2025.03.27力扣网刷题
//回文排列——位运算、哈希表、字符串——简单
//给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
//回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
//回文串不一定是字典当中的单词。
//示例1：
//输入："tactcoa"
//输出：true（排列有"tacocat"、"atcocta"，等等）

bool canPermutePalindrome(char* s) {
	int hash[256] = { 0 };
	for (int i = 0; s[i]; i++) {
		int key = s[i];
		hash[key] += 1;
	}
	int ans = 0;
	for (int i = 0; i < 256; i++) {
		if (hash[i] % 2) {
			ans += 1;
		}
	}
	return ans == 1 || ans == 0;
}