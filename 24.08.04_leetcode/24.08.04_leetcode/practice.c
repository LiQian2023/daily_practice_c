#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//2024.08.04力扣网刷题
//将句子排序——字符串、排序——简单
//一个 句子 指的是一个序列的单词用单个空格连接起来，且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。
//我们可以给一个句子添加 从 1 开始的单词位置索引 ，并且将句子中所有单词 打乱顺序 。
//比方说，句子 "This is a sentence" 可以被打乱顺序得到 "sentence4 a3 is2 This1" 或者 "is2 sentence4 This1 a3" 。
//给你一个 打乱顺序 的句子 s ，它包含的单词不超过 9 个，请你重新构造并得到原本顺序的句子。
//示例 1：
//输入：s = "is2 sentence4 This1 a3"
//输出："This is a sentence"
//解释：将 s 中的单词按照初始位置排序，得到 "This1 is2 a3 sentence4" ，然后删除数字。
//示例 2：
//输入：s = "Myself2 Me1 I4 and3"
//输出："Me Myself and I"
//解释：将 s 中的单词按照初始位置排序，得到 "Me1 Myself2 and3 I4" ，然后删除数字。
//提示：
//2 <= s.length <= 200
//s 只包含小写和大写英文字母、空格以及从 1 到 9 的数字。
//s 中单词数目为 1 到 9 个。
//s 中的单词由单个空格分隔。
//s 不包含任何前导或者后缀空格。

void Remove(char* s) {
	int len = strlen(s);
	char tmp = s[len - 1];
	for (int i = len - 2; i >= 0; i--) {
		s[i + 1] = s[i];
	}
	s[0] = tmp;
}
void DeleteDigit(char* s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		s[i] = s[i + 1];
	}
}

char* sortSentence(char* s) {
	char* ans = (char*)calloc(strlen(s), sizeof(char));
	assert(ans);
	char* t = " ";
	char* tmp[200] = { 0 };
	int num = 0;
	for (tmp[num] = strtok(s, t); tmp[num]; tmp[num] = strtok(NULL, t)) {
		Remove(tmp[num]);
		num++;
	}
	for (int i = 0; i < num - 1; i++) {
		bool flag = true;
		for (int j = 0; j < num - 1 - i; j++) {
			if (strcmp(tmp[j], tmp[j + 1]) > 0) {
				char* p = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = p;
				flag = false;
			}
		}
		if (flag)
			break;
	}
	DeleteDigit(tmp[0]);
	memcpy(ans, tmp[0], strlen(tmp[0]));
	for (int i = 1; i < num; i++) {
		strcat(ans, t);
		DeleteDigit(tmp[i]);
		strcat(ans, tmp[i]);
	}
	return ans;
}

void test() {
	char s[201] = "is2 sentence4 This1 a3";
	char* ret = sortSentence(s);
	printf("%s\n", ret);
}

int main() {
	test();
	return 0;
}