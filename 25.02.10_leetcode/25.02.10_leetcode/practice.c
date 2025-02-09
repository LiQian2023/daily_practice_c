#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//2025.02.10力扣网刷题
//键盘行——哈希表、字符串、数组——简单
//给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
//请注意，字符串 不区分大小写，相同字母的大小写形式都被视为在同一行。
//美式键盘 中：
//第一行由字符 "qwertyuiop" 组成。
//第二行由字符 "asdfghjkl" 组成。
//第三行由字符 "zxcvbnm" 组成。
//American keyboard
//示例 1：
//输入：words = ["Hello", "Alaska", "Dad", "Peace"]
//输出：["Alaska", "Dad"]
//解释：
//由于不区分大小写，"a" 和 "A" 都在美式键盘的第二行。
//示例 2：
//输入：words = ["omk"]
//输出：[]
//示例 3：
//输入：words = ["adsdf", "sfd"]
//输出：["adsdf", "sfd"]
//提示：
//1 <= words.length <= 20
//1 <= words[i].length <= 100
//words[i] 由英文字母（小写和大写字母）组成

char** findWords(char** words, int wordsSize, int* returnSize) {
	char** ans = (char**)calloc(wordsSize, sizeof(char*));
	assert(ans);
	*returnSize = 0;
	char str1[11] = "qwertyuiop";
	char first[26] = { 0 };
	char str2[10] = "asdfghjkl";
	char secend[26] = { 0 };
	char str3[8] = "zxcvbnm";
	char third[26] = { 0 };
	for (int i = 0, j = 0, z = 0; i < 10; i++) {
		int key1 = str1[i] - 'a';
		first[key1] += 1;
		if (j < 9) {
			int key2 = str2[j] - 'a';
			secend[key2] += 1;
			j += 1;
		}
		if (z < 7) {
			int key3 = str3[z] - 'a';
			third[key3] += 1;
			z += 1;
		}
	}
	for (int i = 0; i < wordsSize; i++) {
		int key = tolower(words[i][0]) - 'a';
		int len = strlen(words[i]);
		bool flag = true;
		if (first[key]) {
			for (int j = 1; j < len; j++) {
				key = tolower(words[i][j]) - 'a';
				if (first[key] == 0) {
					flag = false;
					break;
				}
			}
		}
		else if (secend[key]) {
			for (int j = 1; j < len; j++) {
				key = tolower(words[i][j]) - 'a';
				if (secend[key] == 0) {
					flag = false;
					break;
				}
			}
		}
		else {
			for (int j = 1; j < len; j++) {
				key = tolower(words[i][j]) - 'a';
				if (third[key] == 0) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			ans[*returnSize] = (char*)calloc(len + 1, sizeof(char));
			assert(ans[*returnSize]);
			strncpy(ans[*returnSize], words[i], len);
			*returnSize += 1;
		}
	}
	return ans;
}