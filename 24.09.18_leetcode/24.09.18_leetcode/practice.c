#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//2024.09.18力扣网刷题
//有效的字母异位词——哈希表、字符串、排序——简单
//给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。
//注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词）。
//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出 : true
//示例 2 :
//输入 : s = "rat", t = "car"
//输出 : false
//示例 3 :
//输入 : s = "a", t = "a"
//输出 : false
//提示 :
//1 <= s.length, t.length <= 5 * 104
//s and t 仅包含小写字母
//进阶 : 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
//注意：本题与主站 242 题相似（字母异位词定义不同）：https ://leetcode-cn.com/problems/valid-anagram/

int cmp(const void* p1, const void* p2) {
	return *(char*)p2 - *(char*)p1;
}

bool isAnagram(char* s, char* t) {
	bool flag = strcmp(s, t);
	qsort(s, strlen(s), sizeof(char), cmp);
	qsort(t, strlen(t), sizeof(char), cmp);
	return flag && !strcmp(s, t);
}

void test() {
	char s[10] = "anagram";
	char t[10] = "nagaram";
	printf("%d\n", isAnagram(s, t));
}

int main() {
	test();
	return 0;
}