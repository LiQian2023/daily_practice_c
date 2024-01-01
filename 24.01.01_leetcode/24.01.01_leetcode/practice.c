#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//2024.01.01力扣网刷题
//有效的字母异位词——哈希表、字符串、排序——简单
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出 : true
//示例 2 :
//	输入 : s = "rat", t = "car"
//	输出 : false
//	提示 :
//	1 <= s.length, t.length <= 5 * 10^4
//	s 和 t 仅包含小写字母
//	进阶 : 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
int cmp(const void* p1, const void* p2) {
	return *(char*)p1 - *(char*)p2;
}

bool isAnagram(char* s, char* t) {
	int sum = 0;
	int len = strlen(s);
	int len2 = strlen(t);
	if (len != len2)
		return false;
	qsort(t, len2, 1, cmp);
	qsort(s, len, 1, cmp);
	//for (int i = 0; i < len; i++)
	//{
	//	sum ^= s[i];
	//	sum ^= t[i];
	//	if (sum)
	//		return false;
	//}
	//return true;
	return strcmp(s, t);
}
int main()
{
	char ch1[50000] = { 0 };
	char ch2[50000] = { 0 };
	while (scanf("%s%s", ch1, ch2) == 2) {
		if (isAnagram(ch1, ch2))
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}