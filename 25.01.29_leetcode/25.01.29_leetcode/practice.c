#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2025.01.29力扣网刷题
//“气球” 的最大数量——哈希表、字符串、计数——简单
//给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
//字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
//示例 1：
//输入：text = "nlaebolko"
//输出：1
//示例 2：
//输入：text = "loonbalxballpoon"
//输出：2
//示例 3：
//输入：text = "leetcode"
//输出：0
//提示：
//1 <= text.length <= 10^4
//text 全部由小写英文字母组成
//注意：本题与 2287. 重排字符形成目标字符串 相同。

int maxNumberOfBalloons(char* text) {
	int hash[26] = { 0 };
	for (int i = 0; text[i]; i++) {
		int key = text[i] - 'a';
		hash[key] += 1;
	}
	char* s = "balon";
	int tmp[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		int key = s[i] - 'a';
		int div = 1;
		if (s[i] == 'l' || s[i] == 'o') {
			div += 1;
		}
		tmp[i] = hash[key] / div;
	}
	int ans = tmp[0];
	for (int i = 0; i < 5; i++) {
		if (tmp[i] < ans) {
			ans = tmp[i];
		}
	}
	return ans;
}