#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//2024.03.30力扣网刷题
//检测大写字母——字符串——简单
//我们定义，在以下情况时，单词的大写用法是正确的：
//全部字母都是大写，比如 "USA" 。
//单词中所有字母都不是大写，比如 "leetcode" 。
//如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
//给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。
//示例 1：
//输入：word = "USA"
//输出：true
//示例 2：
//输入：word = "FlaG"
//输出：false
//提示：
//1 <= word.length <= 100
//word 由小写和大写英文字母组成

bool detectCapitalUse(char* word) {
	if (islower(word[0])) {
		for (int i = 1; word[i]; i++) {
			if (isupper(word[i]))
				return false;
		}
	}
	else {
		int len = strlen(word);
		int flag = 1;
		for (int i = 1; word[i]; i++) {
			if (isupper(word[i]))
				flag++;
		}
		if (flag > 1 && flag != len)
			return false;
	}
	return true;
}