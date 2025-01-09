#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
//2025.01.09力扣网刷题
// 第一个出现两次的字母——位运算、哈希表、字符串、计数——简单
//给你一个由小写英文字母组成的字符串 s ，请你找出并返回第一个出现 两次 的字母。
//注意：
//如果 a 的 第二次 出现比 b 的 第二次 出现在字符串中的位置更靠前，则认为字母 a 在字母 b 之前出现两次。
//s 包含至少一个出现两次的字母。
//示例 1：
//输入：s = "abccbaacz"
//输出："c"
//解释：
//字母 'a' 在下标 0 、5 和 6 处出现。
//字母 'b' 在下标 1 和 4 处出现。
//字母 'c' 在下标 2 、3 和 7 处出现。
//字母 'z' 在下标 8 处出现。
//字母 'c' 是第一个出现两次的字母，因为在所有字母中，'c' 第二次出现的下标是最小的。
//示例 2：
//输入：s = "abcdd"
//输出："d"
//解释：
//只有字母 'd' 出现两次，所以返回 'd' 。
//提示：
//2 <= s.length <= 100
//s 由小写英文字母组成
//s 包含至少一个重复字母

char repeatedCharacter(char* s) {
	char ch = s[0];
	char hash[26] = { 0 };
	for (int i = 0; s[i]; i++) {
		int key = s[i] - 'a';
		hash[key] += 1;
		if (hash[key] == 2) {
			ch = s[i];
			break;
		}
	}
	return ch;
}

#if 0
//统计重新排列后包含另一个字符串的子字符串数目 I——字符串、哈希表、滑动窗口——中等
//给你两个字符串 word1 和 word2 。
//如果一个字符串 x 重新排列后，word2 是重排字符串的
//前缀，那么我们称字符串 x 是 合法的 。
//请你返回 word1 中 合法子字符串的数目。
//示例 1：
//输入：word1 = "bcca", word2 = "abc"
//输出：1
//解释：
//唯一合法的子字符串是 "bcca" ，可以重新排列得到 "abcc" ，"abc" 是它的前缀。
//示例 2：
//输入：word1 = "abcabc", word2 = "abc"
//输出：10
//解释：
//除了长度为 1 和 2 的所有子字符串都是合法的。
//示例 3：
//输入：word1 = "abcabc", word2 = "aaabc"
//输出：0
//解释：
//1 <= word1.length <= 10^5
//1 <= word2.length <= 10^4
//word1 和 word2 都只包含小写英文字母。

long long validSubstringCount(char* word1, char* word2) {
	int len1 = strlen(word1), len2 = strlen(word2);
	long long ans = 0;
	if (len2 <= len1) {
		int hash1[26] = { 0 };
		int tmp[26] = { 0 };
		int key = 0;
		//记录word2
		for (int i = 0; i < len2; i++) {
			key = word2[i] - 'a';
			hash1[key] += 1;
			tmp[key] += 1;
		}
		int count = len2;
		//查找子串并记录子串
		int hash2[26] = { 0 };
		int i = 0;
		for (; i < len1 && count; i++) {
			key = word1[i] - 'a';
			hash2[key] += 1;
			if (tmp[key] > 0) {
				tmp[key] -= 1;
				count -= 1;
			}
		}
		if (count == 0)
			ans += len1 - i + 1;
		for (int j = 0; i + j < len1; j++) {
			key = word1[j] - 'a';
			int key2 = word1[i + j] - 'a';
			//新增的元素
			hash2[key] -= 1;
			hash2[key2] += 1;
			//子串中的对应元素个数大于word2中该元素的个数
			if (hash2[key] >= hash1[key]) {
				ans += len1 - (i + j) + 1;
			}
		}
	}
	return ans;
}
#endif