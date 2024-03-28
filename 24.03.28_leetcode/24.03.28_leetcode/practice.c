#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//2024.03.28力扣网刷题
//字符串相加——数学、字符串、模拟——简单
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//示例 1：
//输入：num1 = "11", num2 = "123"
//输出："134"
//示例 2：
//输入：num1 = "456", num2 = "77"
//输出："533"
//示例 3：
//输入：num1 = "0", num2 = "0"
//输出："0"
//提示：
//1 <= num1.length, num2.length <= 10^4
//num1 和num2 都只包含数字 0 - 9
//num1 和num2 都不包含任何前导零
#define MAXSIZE 10001
void Insert(char(*L)[MAXSIZE], int* len, char* ch) {
	for (int i = strlen(ch) - 1; i >= 0; i--) {
		(*L)[*len] = ch[i];
		(*len)++;
	}
}
void Add(char(*L)[MAXSIZE], int* len, char* ch) {
	int i = 0;//顺序表下标
	for (int j = strlen(ch) - 1; j >= 0; j--) {
		if ((*L)[i] > '9') {
			(*L)[i] -= 10;
			(*L)[i + 1] += 1;
		}
		(*L)[i] = (*L)[i] + ch[j] - '0';
		if ((*L)[i] > '9') {
			(*L)[i] -= 10;
			(*L)[i + 1] += 1;
		}
		i++;
	}
	while ((*L)[i] > '9') {
		(*L)[i] -= 10;
		(*L)[++i] += 1;
	}
	if (i == (*len) && (*L)[i] == 1) {
		(*len)++;
		(*L)[i] += '0';
	}
}
char* addStrings(char* num1, char* num2) {
	char L[MAXSIZE] = { 0 };
	int len = 0;
	char* max = strlen(num1) > strlen(num2) ? num1 : num2;
	char* min = strlen(num1) > strlen(num2) ? num2 : num1;
	Insert(&L, &len, max);
	Add(&L, &len, min);
	char* ans = (char*)calloc(len + 1, sizeof(char));
	assert(ans);
	int l = 0;
	for (int i = len - 1; i >= 0; i--) {
		ans[l++] = L[i];
	}
	return ans;
}

void test() {
	char ch1[5] = { 0 };
	char ch2[50] = { 0 };
	while (scanf("%s%s", ch1, ch2) == 2) {
		printf("%s\n", addStrings(ch1, ch2));
		free(addStrings(ch1, ch2));
	}
}

int main() {
	test();
	return 0;
}