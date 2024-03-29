#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//2024.03.29力扣网刷题
//字符串中的单词数——字符串——简单
//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
//请注意，你可以假定字符串里不包括任何不可打印的字符。
//示例 :
//输入: "Hello, my name is John"
//输出 : 5
//解释 : 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。

int countSegments(char* s) {
	int count = 0;
	int flag = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == ' ' && flag)
		{
			count++;
			flag = 0;
		}
		else if(s[i]!=' ')
			flag = 1;
	}
	if (flag)
		count++;
	return count;
}

int main() {
	char s[10] = { 0 };
	while (gets(s)) {
		printf("%d\n", countSegments(s));
	}
	return 0;
}