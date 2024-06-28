#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//2024.06.28力扣网刷题
//单词规律——哈希表、字符串——简单
//给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
//这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
//示例1:
//输入: pattern = "abba", s = "dog cat cat dog"
//输出 : true
//示例 2 :
//	输入 : pattern = "abba", s = "dog cat cat fish"
//	输出 : false
//	示例 3 :
//	输入 : pattern = "aaaa", s = "dog cat cat dog"
//	输出 : false
//	提示 :
//	1 <= pattern.length <= 300
//	pattern 只包含小写英文字母
//	1 <= s.length <= 3000
//	s 只包含小写英文字母和 ' '
//	s 不包含 任何前导或尾随对空格
//	s 中每个单词都被 单个空格 分隔

// 方法一：哈希表
typedef struct HashNode {
	char key;	//关键字
	char* data;	//数据域
}HN;

bool wordPattern(char* pattern, char* s) {
	char tmp[300][3001] = { 0 };
	int i = 0;	// 指针数组下标
	int len = strlen(s);	// s数组长度
	// 分割单词
	for (int n = 0; n < len; n++) {
		int j = 0;
		while (s[n] && s[n] != ' ') {
			tmp[i][j++] = s[n++];
		}
		tmp[i++][j] = '\0';
	}
	if (i != strlen(pattern))
		return false;
	// 创建字母哈希表
	HN hash[26] = { 0 };
	for (int i = 0; pattern[i]; i++) {
		int hash_key = pattern[i] - 'a';
		char* str = hash[hash_key].data;
		//查找关键字是否存在
		if (hash[hash_key].key) {
			//关键字存在，查找数据元素是否相等
			if (strcmp(str, tmp[i]))
				return false;
		}
		else {
			// 关键字不存在，查找元素是否存在
			for (int j = 0; j < 26; j++) {
				str = hash[j].data;
				if (str && strcmp(str, tmp[i]) == 0)
					return false;
			}
			// 元素不存在，记录关键字与元素
			hash[hash_key].key = pattern[i];
			hash[hash_key].data = tmp[i];
		}
	}
	return true;
}

void test() {
	char str1[300] = { 0 };
	char str2[300] = { 0 };
	while (scanf("%s",str1) == 1){
		gets();
		gets(str2);
		printf("%d\n", wordPattern(str1, str2));
	}
}

int main() {
	test();
	return 0;
}