#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2025.07.23力扣网刷题
//最大重复子字符串——字符串、动态规划、字符串匹配、第40场双周赛——简单
//给你一个字符串 sequence ，如果字符串 word 连续重复 k 次形成的字符串是 sequence 的一个子字符串，那么单词 word 的 重复值为 k 。
//单词 word 的 最大重复值 是单词 word 在 sequence 中最大的重复值。如果 word 不是 sequence 的子串，那么重复值 k 为 0 。
//给你一个字符串 sequence 和 word ，请你返回 最大重复值 k 。
//示例 1：
//输入：sequence = "ababc", word = "ab"
//输出：2
//解释："abab" 是 "ababc" 的子字符串。
//示例 2：
//输入：sequence = "ababc", word = "ba"
//输出：1
//解释："ba" 是 "ababc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
//示例 3：
//输入：sequence = "ababc", word = "ac"
//输出：0
//解释："ac" 不是 "ababc" 的子字符串。
//提示：
//1 <= sequence.length <= 100
//1 <= word.length <= 100
//sequence 和 word 都只包含小写英文字母。

int maxRepeating(char* sequence, char* word) {
	int ans = 0;
	int n = 0;
	for (int begin = 0; sequence[begin]; begin++) {
		n = 0;
		int i = begin, j = 0;
		int lose = 0;
		while (sequence[i]) {
			while (sequence[i] && word[j] && sequence[i] == word[j]) {
				i += 1;
				j += 1;
			}
			if (!word[j]) {
				n += 1;
				lose += 1;
			}
			else {
				lose += 1;
				if (ans < n) {
					ans = n;
					n = 0;
				}
				if (lose > 1) {
					break;
				}
			}
			j = 0;
		}
		if (!sequence[i]) {
			break;
		}
	}
	if (ans < n) {
		ans = n;
	}
	return ans;
}