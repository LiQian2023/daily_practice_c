#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//2025.01.18力扣网刷题
//判断句子是否为全字母句——哈希表、字符串——简单
//全字母句 指包含英语字母表中每个字母至少一次的句子。
//给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。
//如果是，返回 true ；否则，返回 false 。
//示例 1：
//输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
//输出：true
//解释：sentence 包含英语字母表中每个字母至少一次。
//示例 2：
//输入：sentence = "leetcode"
//输出：false
//提示：
//1 <= sentence.length <= 1000
//sentence 由小写英语字母组成

bool checkIfPangram(char* sentence) {
	char hash[26] = { 0 };
	for (int i = 0; sentence[i]; i++) {
		int key = sentence[i] - 'a';
		hash[key] += 1;
	}
	for (int i = 0; i < 26; i++) {
		if (hash[i] == 0)
			return false;
	}
	return true;
}