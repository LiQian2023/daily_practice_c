#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
//2024.04.28力扣网刷题
//Excel表列名称——数学、字符串——简单
//给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
//例如：
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//示例 1：
//输入：columnNumber = 1
//输出："A"
//示例 2：
//输入：columnNumber = 28
//输出："AB"
//示例 3：
//输入：columnNumber = 701
//输出："ZY"
//示例 4：
//输入：columnNumber = 2147483647
//输出："FXSHRXW"
//提示：
//1 <= columnNumber <= 2^31 - 1

char* convertToTitle1(int columnNumber) {
	int len = 1;
	int num = columnNumber;
	while (num > 26) {
		len++;
		num /= 26;
	}
	char* ans = (char*)calloc(len + 1, sizeof(char));
	if (!ans)
		return NULL;
	num = columnNumber;
	for (int i = len - 1; i >= 0; i--) {
		if (num > 26) {
			if (num % 26)
				ans[i] = num % 26 - 1 + 'A';
			else {
				ans[i] = 'Z';
				num -= 26;
			}
			num /= 26;
		}
		else {
			ans[i] = num - 1 + 'A';
			num -= 26;
		}
	}
	return ans[0] >= 'A' ? ans : ans + 1;
}

char* convertToTitle(int columnNumber) {
	int len = 1;
	int num = columnNumber;
	while (num > 26) {
		len++;
		num /= 26;
	}
	char* ans = (char*)calloc(len + 1, sizeof(char));
	if (!ans)
		return NULL;
	num = columnNumber;
	for (int i = len - 1; i >= 0; i--) {
		if (num > 26) {
			if (num % 26)
				ans[i] = (num - 1) % 26 + 'A';
			else {
				ans[i] = 'Z';
				num -= 26;
			}
			num /= 26;
		}
		else {
			ans[i] = num - 1 + 'A';
			num -= 26;
		}
	}
	return ans[0] >= 'A' ? ans : ans + 1;
}
void test() {
	int num = 0;
	while (scanf("%d", &num) == 1) {
		char* ret = convertToTitle(num);
		printf("%s\n", ret);
		free(ret);
	}
}

int main() {
	test();
	return 0;
}