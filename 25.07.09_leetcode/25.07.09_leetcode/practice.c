#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2025.07.09力扣网刷题
//解码字母到整数映射——字符串——简单
//给你一个字符串 s，它由数字（'0' - '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：
//字符（'a' - 'i'）分别用（'1' - '9'）表示。
//字符（'j' - 'z'）分别用（'10#' - '26#'）表示。
//返回映射之后形成的新字符串。
//题目数据保证映射始终唯一。
//示例 1：
//输入：s = "10#11#12"
//输出："jkab"
//解释："j" -> "10#", "k" -> "11#", "a" -> "1", "b" -> "2".
//示例 2：
//输入：s = "1326#"
//输出："acz"
//提示：
//1 <= s.length <= 1000
//s[i] 只包含数字（'0' - '9'）和 '#' 字符。
//s 是映射始终存在的有效字符串。


char* freqAlphabets(char* s) {
	int len = strlen(s);
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	int size = 0;
	for (int i = 0; i < len;) {
		if (i + 2 < len && s[i + 2] == '#') {
			ans[size] = (s[i] - '0') * 10 + (s[i + 1] - '0') - 1 + 'a';
			i += 3;
		}
		else {
			ans[size] = s[i] - '0' - 1 + 'a';
			i += 1;
		}
		size += 1;
	}
	return ans;
}