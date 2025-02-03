#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2025.02.03力扣网刷题
//上升下降字符串——哈希表、字符串、计数——简单
//给你一个字符串 s ，请你根据下面的算法重新构造字符串：
//从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
//从 s 剩余字符中选出比上一个添加字符更大的 最小 字符，将它 接在 结果字符串后面。
//重复步骤 2 ，直到你没法从 s 中选择字符。
//从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
//从 s 剩余字符中选出比上一个添加字符更小的 最大 字符，将它 接在 结果字符串后面。
//重复步骤 5 ，直到你没法从 s 中选择字符。
//重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
//在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。
//请你返回将 s 中字符重新排序后的 结果字符串 。
//示例 1：
//输入：s = "aaaabbbbcccc"
//输出："abccbaabccba"
//解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
//第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
//第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
//第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
//第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"
//示例 2：
//输入：s = "rat"
//输出："art"
//解释：单词 "rat" 在上述算法重排序以后变成 "art"
//提示：
//1 <= s.length <= 500
//s 只包含小写英文字母。
void Print(int* hash) {
	for (int i = 0; i < 26; i++) {
		printf("hash[%d] = %d\n", i, hash[i]);
	}
}
char* sortString(char* s) {
	char hash[26] = { 0 };
	int size = 0;
	int min = 26, max = 0;
	for (int i = 0; s[i]; i++) {
		int key = s[i] - 'a';
		if (key < min) {
			min = key;
		}
		if (key > max) {
			max = key;
		}
		hash[key] += 1;
		size += 1;
	}
	char* ans = (char*)calloc(size + 1, sizeof(char));
	assert(ans);
	int key = min;
	bool flag = true;
	for (int i = 0; i < size; ) {
		if (hash[key]) {
			ans[i] = key + 'a';
			hash[key] -= 1;
			i += 1;
		}
		if (flag) {
			key += 1;
			if (key > max) {
				key -= 1;
				flag = false;
			}
		}
		else {
			key -= 1;
			if (key < min) {
				key += 1;
				flag = true;
			}
		}
	}
	return ans;
}