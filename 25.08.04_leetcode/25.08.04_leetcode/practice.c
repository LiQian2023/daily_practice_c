#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//2025.08.04力扣网刷题
//检查字符串是否为数组前缀——数组、双指针、字符串、第253场周赛——简单
//给你一个字符串 s 和一个字符串数组 words ，请你判断 s 是否为 words 的 前缀字符串 。
//字符串 s 要成为 words 的 前缀字符串 ，需要满足：s 可以由 words 中的前 k（k 为 正数 ）个字符串按顺序相连得到，且 k 不超过 words.length 。
//如果 s 是 words 的 前缀字符串 ，返回 true ；否则，返回 false 。
//示例 1：
//输入：s = "iloveleetcode", words = ["i", "love", "leetcode", "apples"]
//输出：true
//解释：
//s 可以由 "i"、"love" 和 "leetcode" 相连得到。
//示例 2：
//输入：s = "iloveleetcode", words = ["apples", "i", "love", "leetcode"]
//输出：false
//解释：
//数组的前缀相连无法得到 s 。
//提示：
//1 <= words.length <= 100
//1 <= words[i].length <= 20
//1 <= s.length <= 1000
//words[i] 和 s 仅由小写英文字母组成

bool isPrefixString(char* s, char** words, int wordsSize) {
	for (int i = 0, j = 0, z = 0; s[i] && j < wordsSize;) {
		while (s[i] && words[j][z]) {
			if (s[i] == words[j][z]) {
				i += 1;
				z += 1;
			}
			else {
				return false;
			}
		}
		if ((!s[i] && words[j][z]) || (s[i] && j == wordsSize - 1 && !words[j][z])) {
			return false;
		}
		j += 1;
		z = 0;
	}
	return true;
}