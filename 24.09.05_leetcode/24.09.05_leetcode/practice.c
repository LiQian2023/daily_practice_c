#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
//2024.09.05力扣网刷题
//面试题 01.01. 判定字符是否唯一——位运算、哈希表、字符串、排序——简单
//实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
//示例 1：
//输入 : s = "leetcode"
//输出 : false
//示例 2：
//输入 : s = "abc"
//输出 : true
//限制：
//0 <= len(s) <= 100
//s[i]仅包含小写字母
//如果你不使用额外的数据结构，会很加分。

//哈希计数
bool isUnique(char* astr) {
	char ch[26] = { 0 };
	for (int i = 0; astr[i]; i++) {
		ch[astr[i] - 'a'] += 1;
		if (ch[astr[i] - 'a'] > 1)
			return false;
	}
	return true;
}