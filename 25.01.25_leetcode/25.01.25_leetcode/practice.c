#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

//2025.01.25力扣网刷题
//查找共用字符——数组、哈希表、字符串——简单
//给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
//示例 1：
//输入：words = ["bella", "label", "roller"]
//输出：["e", "l", "l"]
//示例 2：
//输入：words = ["cool", "lock", "cook"]
//输出：["c", "o"]
//提示：
//1 <= words.length <= 100
//1 <= words[i].length <= 100
//words[i] 由小写英文字母组成

typedef struct Hash {
	char ch;
	int num;
}Hash;

char** commonChars(char** words, int wordsSize, int* returnSize) {
	int max = strlen(words[0]);
	for (int i = 0; i < wordsSize; i++) {
		int len = strlen(words[i]);
		if (len > max) {
			max = len;
		}
	}
	char** ans = (char**)calloc(max, sizeof(char*));
	assert(ans);
	for (int i = 0; i < max; i++) {
		ans[i] = (char*)calloc(2, sizeof(char));
		assert(ans[i]);
	}
	*returnSize = 0;
	Hash hash[26] = { 0 };
	for (int i = 0; i < wordsSize; i++) {
		char tmp[26] = { 0 };
		for (int j = 0; words[i][j]; j++) {
			int key = words[i][j] - 'a';
			tmp[key] += 1;
		}
		for (int j = 0; j < 26; j++) {
			if (i == 0) {
				hash[j].ch = j + 'a';
				hash[j].num = tmp[j];
			}
			else if (j && tmp[j] < hash[j].num) {
				hash[j].num = tmp[j];
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		while (hash[i].num) {
			ans[*returnSize][0] = hash[i].ch;
			*returnSize += 1;
			hash[i].num -= 1;
		}
	}
	return ans;
}