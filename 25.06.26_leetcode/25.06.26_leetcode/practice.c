#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.06.26力扣网刷题
//子字符串匹配模式——字符串、字符串匹配——简单
//给你一个字符串 s 和一个模式字符串 p ，其中 p 恰好 包含 一个 '*' 符号。
//p 中的 '*' 符号可以被替换为零个或多个字符组成的任意字符序列。
//如果 p 可以变成 s 的 子字符串，那么返回 true ，否则返回 false 。
//示例 1：
//输入：s = "leetcode", p = "ee*e"
//输出：true
//解释：
//将 '*' 替换为 "tcod" ，子字符串 "eetcode" 匹配模式串。
//示例 2：
//输入：s = "car", p = "c*v"
//输出：false
//解释：
//不存在匹配模式串的子字符串。
//示例 3：
//输入：s = "luck", p = "u*"
//输出：true 
//解释：
//子字符串 "u" ，"uc" 和 "uck" 都匹配模式串。
//提示：
//1 <= s.length <= 50
//1 <= p.length <= 50
//s 只包含小写英文字母。
//p 只包含小写英文字母和一个 '*' 符号。
void get_next(char* T, int* next) {
	//函数实现——算法优化
	//处理首字符
	next[0] = -1;//字符下标从0开始
	int p = 0, l = 1;//前缀指针和后缀指针
	for (int i = 1; T[i];) {
		//当匹配成功时
		if (T[p] == T[l]) {
			next[i] = next[i - 1] + 1;
			p++, l++, i++;
		}
		//当匹配失败时
		else {
			p = next[i - 1];//前缀指针回溯到next[i-1]的位置
			//处理无匹配字符的情况
			if (p == -1) {
				next[i] = 0;
				p++, l++, i++;
			}
		}
	}
}

bool KMP(char* s, char* p, int len_s, int len_p, int* i) {
	int* next = (int*)calloc(len_p, sizeof(int));
	assert(next);
	get_next(p, next);
	int j = 0;
	for (*i, j; *i < len_s && j < len_p;) {
		if (j == -1 || s[*i] == p[j]) {
			*i += 1, j += 1;
		}
		else {
			j = next[j];
		}
	}
	free(next);
	return j == len_p;
}
bool str_index(char* s, char* p, int len_s, int len_p, int* begin) {
	int i = *begin, j = 0, z = *begin;
	for (; i < len_s && j < len_p;) {
		if (s[i] == p[j]) {
			i += 1, j += 1;
		}
		else {
			j = 0;
			i = z + 1;
			z += 1;
		}
	}
	*begin = i;
	return j == len_p;
}
bool hasMatch(char* s, char* p) {
	int len_s = strlen(s), len_p = strlen(p);
	if (len_p > len_s) {
		return false;
	}
	int k = 0;
	while (p[k] != '*') {
		k += 1;
	}
	char* left = (char*)calloc(k + 1, sizeof(char));
	assert(left);
	for (int i = 0; i < k; i++) {
		left[i] = p[i];
	}
	char* right = (char*)calloc(len_p - k, sizeof(char));
	assert(right);
	for (int i = k + 1, j = 0; i < len_p; i++, j++) {
		right[j] = p[i];
	}
	int begin = 0;
	bool l = str_index(s, left, len_s, k, &begin);
	bool r = str_index(s, right, len_s, len_p - k - 1, &begin);
	free(left);
	left = NULL;
	free(right);
	right = NULL;
	return l && r;
}