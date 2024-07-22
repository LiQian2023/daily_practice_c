#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

//2024.07.22力扣网刷题
//有效单词——字符串——简单
//有效单词 需要满足以下几个条件：
//至少 包含 3 个字符。
//由数字 0 - 9 和英文大小写字母组成。（不必包含所有这类字符。）
//至少 包含一个 元音字母 。
//至少 包含一个 辅音字母 。
//给你一个字符串 word 。如果 word 是一个有效单词，则返回 true ，否则返回 false 。
//注意：
//'a'、'e'、'i'、'o'、'u' 及其大写形式都属于 元音字母 。
//英文中的 辅音字母 是指那些除元音字母之外的字母。
//示例 1：
//输入：word = "234Adas"
//输出：true
//解释：
//这个单词满足所有条件。
//示例 2：
//输入：word = "b3"
//输出：false
//解释：
//这个单词的长度少于 3 且没有包含元音字母。
//示例 3：
//输入：word = "a3$e"
//输出：false
//解释：
//这个单词包含了 '$' 字符且没有包含辅音字母。
//提示：
//1 <= word.length <= 20
//word 由英文大写和小写字母、数字、'@'、'#' 和 '$' 组成。

bool isValid(char* word) {
	bool vowel = false;
	bool consonant = false;
	char vowels[10] = { 'a','e','i','o','u','A','E','I','O','U' };
	int i = 0;
	for (i; word[i]; i++) {
		//判断是否是字母和数字
		if (isalnum(word[i])) {
			//判断是否是字母且
			if (isalpha(word[i]) && (!vowel || !consonant)) {
				int j = 0;
				for (; j < 10; j++) {
					if (word[i] == vowels[j]) {
						vowel = true;
						break;
					}
				}
				if (j == 10)
					consonant = true;
			}
		}
		else
			return false;
	}
	return i > 2 && vowel && consonant;
}

void test() {
	printf("%d\n", isalpha('2'));
	char S[10] = "Hor";
	printf("%d\n", isValid(S));
}

int main() {
	test();
	return 0;
}