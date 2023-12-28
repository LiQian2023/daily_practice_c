#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2023.12.28力扣网刷题
//找出字符串中第一个匹配项的下标——双指针、字符串、字符串匹配——简单
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
//示例 1：
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
//示例 2：
//输入：haystack = "leetcode", needle = "leeto"
//输出： - 1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 - 1 。
//提示：
//1 <= haystack.length, needle.length <= 10……4
//haystack 和 needle 仅由小写英文字符组成

//法一:调用函数strstr
int strStr(char* haystack, char* needle) {
	char* p = strstr(haystack, needle);
	if (!p)
		return -1;
	else
		return p - haystack;
}
//法二：strstr模拟实现
int strStr(char* haystack, char* needle)
{

}
int main()
{
	char ch1[10000] = { 0 };
	char ch2[10000] = { 0 };
	while (scanf("%s%s", ch1, ch2) == 2)
	{
		int ret = strStr(ch1, ch2);
		printf("%d\n", ret);
	}
	return 0;
}