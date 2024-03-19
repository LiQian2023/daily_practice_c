#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>
//2024.03.19力扣网刷题
//最后一个单词的长度——字符串——简单
//给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
//示例 1：
//输入：s = "Hello World"
//输出：5
//解释：最后一个单词是“World”，长度为5。
//示例 2：
//输入：s = "   fly me   to   the moon  "
//输出：4
//解释：最后一个单词是“moon”，长度为4。
//示例 3：
//输入：s = "luffy is still joyboy"
//输出：6
//解释：最后一个单词是长度为6的“joyboy”。
//提示：
//1 <= s.length <= 10^4
//s 仅有英文字母和空格 ' ' 组成
//s 中至少存在一个单词

int lengthOfLastWord(char* s) {
	int len = strlen(s);
	int l = 0, r = len - 1;
	while (r >= 0 && s[r] == ' ') {
		r--;
	}
	l = r;
	while (l >= 0 && s[l] != ' ') {
		l--;
	}
	return r - l;
}