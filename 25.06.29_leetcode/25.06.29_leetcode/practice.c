#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

//2025.06.29力扣网刷题
//删除字符使字符串变好——字符串——简单
//一个字符串如果没有 三个连续 相同字符，那么它就是一个 好字符串 。
//给你一个字符串 s ，请你从 s 删除 最少 的字符，使它变成一个 好字符串 。
//请你返回删除后的字符串。题目数据保证答案总是 唯一的 。
//示例 1：
//输入：s = "leeetcode"
//输出："leetcode"
//解释：
//从第一组 'e' 里面删除一个 'e' ，得到 "leetcode" 。
//没有连续三个相同字符，所以返回 "leetcode" 。
//示例 2：
//输入：s = "aaabaaaa"
//输出："aabaa"
//解释：
//从第一组 'a' 里面删除一个 'a' ，得到 "aabaaaa" 。
//从第二组 'a' 里面删除两个 'a' ，得到 "aabaa" 。
//没有连续三个相同字符，所以返回 "aabaa" 。
//示例 3：
//输入：s = "aab"
//输出："aab"
//解释：没有连续三个相同字符，所以返回 "aab" 。
//提示：
//1 <= s.length <= 10^5
//s 只包含小写英文字母。

char* makeFancyString(char* s) {
	int len = strlen(s);
	char* res = (char*)calloc(len + 1, sizeof(char));
	assert(res);
	int i = 0;
	int n = 0;
	for (int j = 0; j < len; j++) {
		if (i && s[j] == s[j - 1]) {
			n += 1;
			if (n == 3) {
				n -= 1;
				continue;
			}
		}
		else {
			n = 1;
		}
		res[i] = s[j];
		i += 1;
	}
	return res;
}