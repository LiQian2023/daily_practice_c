#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//2025.03.10力扣网刷题
//删除字符使频率相同——哈希表、字符串、计数——简单
//给你一个下标从 0 开始的字符串 word ，字符串只包含小写英文字母。你需要选择 一个 下标并 删除 下标处的字符，使得 word 中剩余每个字母出现 频率 相同。
//如果删除一个字母后，word 中剩余所有字母的出现频率都相同，那么返回 true ，否则返回 false 。
//注意：
//字母 x 的 频率 是这个字母在字符串中出现的次数。
//你 必须 恰好删除一个字母，不能一个字母都不删除。
//示例 1：
//输入：word = "abcc"
//输出：true
//解释：选择下标 3 并删除该字母：word 变成 "abc" 且每个字母出现频率都为 1 。
//示例 2：
//输入：word = "aazz"
//输出：false
//解释：我们必须删除一个字母，所以要么 "a" 的频率变为 1 且 "z" 的频率为 2 ，要么两个字母频率反过来。所以不可能让剩余所有字母出现频率相同。
//提示：
//2 <= word.length <= 100
//word 只包含小写英文字母。

typedef struct Hash {
	char ch;
	int count;
}Hash;

bool equalFrequency(char* word) {
	int len = strlen(word);
	//记录字符出现次数
	char ch[26] = { 0 };
	for (int i = 0; i < len; i++) {
		int key = word[i] - 'a';
		ch[key] += 1;
	}
	Hash* h = (Hash*)calloc(len, sizeof(Hash));
	assert(h);
	int size = 0;
	for (int i = 0; i < 26; i++) {
		if (ch[i]) {
			h[size].ch = i + 'a';
			h[size].count = ch[i];
			size += 1;
		}
	}
	int min = h[0].count;
	int max = h[0].count;
	for (int i = 0; i < size; i++) {
		if (h[i].count < min) {
			min = h[i].count;
		}
		if (h[i].count > max) {
			max = h[i].count;
		}
	}
	int counts[2] = { 0 };
	for (int i = 0; i < size; i++) {
		if (h[i].count == min) {
			counts[0] += 1;
		}
		else if (h[i].count == max) {
			counts[1] += 1;
		}
	}
	free(h);
	h = NULL;
	if (max - min > 1 && counts[1] * max != len - 1) {
		return false;
	}
	if ((counts[0] + 1) * min == len - 1) {
		return true;
	}
	else if (counts[0] == 1 && counts[1] == 0) {
		return true;
	}
	else if (min == 1) {
		if (counts[0] == len || counts[0] == 1) {
			return true;
		}
	}
	return false;
}