#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2025.09.14力扣网刷题
//面试题 01.03.URL化——字符串——简单
//URL化。编写一种方法，将字符串中的空格全部替换为 % 20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）
//示例 1：
//输入："Mr John Smith    ", 13
//输出："Mr%20John%20Smith"
//示例 2：
//输入："               ", 5
//输出："%20%20%20%20%20"
//提示：
//字符串长度在[0, 500000] 范围内。

char* replaceSpaces(char* S, int length) {
	int place = 0;
	for (int i = 0; i < length; i++) {
		if (S[i] == ' ') {
			place += 1;
		}
	}
	char* ans = (char*)calloc(length + 2 * place + 1, sizeof(char));
	assert(ans);
	int size = 0;
	for (int i = 0; i < length; i++) {
		if (S[i] == ' ') {
			ans[size] = '%';
			ans[size + 1] = '2';
			ans[size + 2] = '0';
			size += 3;
		}
		else {
			ans[size] = S[i];
			size += 1;
		}
	}
	return ans;
}