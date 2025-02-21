#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

//2025.02.21力扣网刷题
//字符串中第二大的数字——哈希表、字符串——简单
//给你一个混合字符串 s ，请你返回 s 中 第二大 的数字，如果不存在第二大的数字，请你返回 - 1 。
//混合字符串 由小写英文字母和数字组成。
//示例 1：
//输入：s = "dfa12321afd"
//输出：2
//解释：出现在 s 中的数字包括[1, 2, 3] 。第二大的数字是 2 。
//示例 2：
//输入：s = "abc1111"
//输出： - 1
//解释：出现在 s 中的数字只包含[1] 。没有第二大的数字。
//提示：
//1 <= s.length <= 500
//s 只包含小写英文字母和（或）数字。

int secondHighest(char* s) {
	int num[10] = { 0 };
	int max = -1;
	for (int i = 0; s[i]; i++) {
		if (isdigit(s[i])) {
			int key = s[i] - '0';
			num[key] += 1;
			if (key > max) {
				max = key;
			}
		}
	}
	int ans = -1;
	for (int i = max - 1; i >= 0; i--) {
		if (num[i]) {
			ans = i;
			break;
		}
	}
	return ans;
}