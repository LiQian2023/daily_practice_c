#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.03.17力扣网刷题
//奇偶频次间的最大差值 I——哈希表、字符串、计数——简单
//给你一个由小写英文字母组成的字符串 s 。请你找出字符串中两个字符的出现频次之间的 最大 差值，这两个字符需要满足：
//一个字符在字符串中出现 偶数次 。
//另一个字符在字符串中出现 奇数次 。
//返回 最大 差值，计算方法是出现 奇数次 字符的次数 减去 出现 偶数次 字符的次数。
//示例 1：
//输入：s = "aaaaabbc"
//输出：3
//解释：
//字符 'a' 出现 奇数次 ，次数为 5 ；字符 'b' 出现 偶数次 ，次数为 2 。
//最大差值为 5 - 2 = 3 。
//示例 2：
//输入：s = "abcabcab"
//输出：1
//解释：
//字符 'a' 出现 奇数次 ，次数为 3 ；字符 'c' 出现 偶数次 ，次数为 2 。
//最大差值为 3 - 2 = 1 。
//提示：
//3 <= s.length <= 100
//s 仅由小写英文字母组成。
//s 至少由一个出现奇数次的字符和一个出现偶数次的字符组成。


int maxDifference(char* s) {
	int odd = 0;
	int even = 0;
	int ch[26] = { 0 };
	for (int i = 0; s[i]; i++) {
		int key = s[i] - 'a';
		ch[key] += 1;
	}
	for (int i = 0; i < 26; i++) {
		if (ch[i] && ch[i] % 2 == 0) {
			if (even == 0 || ch[i] < even) {
				even = ch[i];
			}
		}
		else {
			if (ch[i] > odd) {
				odd = ch[i];
			}
		}
	}
	return odd - even;
}
