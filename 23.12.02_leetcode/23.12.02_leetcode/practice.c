#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.02力扣网刷题
//转换成小写字母——字符串——简单
//给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。
//示例 1：
//输入：s = "Hello"
//输出："hello"
//示例 2：
//输入：s = "here"
//输出："here"
//示例 3：
//输入：s = "LOVELY"
//输出："lovely"
//提示：
//1 <= s.length <= 100
//s 由 ASCII 字符集中的可打印字符组成
#include <ctype.h>
char* toLowerCase1(char* s) {
	char* start = s;
	while (*s)
	{
		if (isupper(*s))
		{
			*s = tolower(*s);
		}
		s++;
	}
	return start;
}
char* toLowerCase(char* s) {
	char* start = s;
	while (*s)
	{
		if (*s>='A'&&*s<='Z')
		{
			*s += 32;
		}
		s++;
	}
	return start;
}
int main()
{
	char s[100] = { 0 };
	while (scanf("%s", s) != EOF)
	{
		char* p = toLowerCase(s);
		printf("%s\n", p);
	}
	return 0;
}