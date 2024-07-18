#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//2024.07.19力扣网刷题
//清除数字——哈希表、字符串、模拟——简单
//给你一个字符串 s 。
//你的任务是重复以下操作删除 所有 数字字符：
//删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
//请你返回删除所有数字字符以后剩下的字符串。
//示例 1：
//输入：s = "abc"
//输出："abc"
//解释：
//字符串中没有数字。
//示例 2：
//输入：s = "cb34"
//输出：""
//解释：
//一开始，我们对 s[2] 执行操作，s 变为 "c4" 。
//然后对 s[1] 执行操作，s 变为 "" 。
//提示：
//1 <= s.length <= 100
//s 只包含小写英文字母和数字字符。
//输入保证所有数字都可以按以上操作被删除。

//方法一：模拟
char* clearDigits1(char* s) {
	int len = strlen(s);
	for (int i = 0; s[i];) {
		if (isdigit(s[i])) {
			int j = i + 1;
			if (i == 0) {
				while (j < len + 1) {
					s[j - 1] = s[j];
					j++;
				}
			}
			else {
				while (j < len + 1) {
					s[j - 2] = s[j];
					j++;
				}
			}
			if (i) {
				i -= 1;
			}
		}
		else {
			i++;
		}
	}
	return s;
}

//方法二：模拟2
char* clearDigits(char* s) {
	int len = strlen(s);
	for (int i = 0; s[i];) {
		if (isdigit(s[i])) {
			int j = i + 1;
			while (isdigit(s[j])) {
				j++;
			}
			int n = j - i;
			if (n >= i ){
				i = 0;
			}
			else {
				i -= n;
			}
			if (j == len) {
				s[i] = '\0';
				break;
			}
			for (int z = i; j < len + 1; j++) {
				s[z++] = s[j];
			}
		}
		else {
			i++;
		}
	}
	return s;
}

