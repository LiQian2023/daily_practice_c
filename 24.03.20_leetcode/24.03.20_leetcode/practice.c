#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//2024.03.20力扣网刷题
//二进制求和——位运算、字符串、数学、模拟——简单
//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
//示例 1：
//输入 : a = "11", b = "1"
//输出："100"
//示例 2：
//输入：a = "1010", b = "1011"
//输出："10101"
//提示：
//1 <= a.length, b.length <= 10^4
//a 和 b 仅由字符 '0' 或 '1' 组成
//字符串如果不是 "0" ，就不含前导零

#define MAXSIZE 10002
void Initarr(char* ans, char* ch, int len, int len_x) {
	//顺序表中加入元素
	for (int i = len_x - 1; i >= 0; i--) {
		ans[len++] = ch[i];
	}
}
void Add(char* ans, char* ch, int i, int len_x) {
	//求和
	for (int j = len_x - 1; j >= 0; j--) {
		ans[i] = ans[i] + ch[j] - '0';
		if (ans[i] >= '2') {
			ans[i] = ans[i] - 2;
			if (ans[i + 1] == 0)
				ans[i + 1] += '1';
			else
				ans[i + 1] = ans[i + 1] + 1;
		}
		i++;
	}
}
char* addBinary(char* a, char* b) {
	char ans[MAXSIZE] = { 0 };//数据域
	int len = 0;//表长
	int len_a = strlen(a);//串a的长度
	int len_b = strlen(b);//串b的长度
	Initarr(ans, len_a > len_b ? a : b, len, len_a > len_b ? len_a : len_b);
	int i = 0;
	Add(ans, len_a > len_b ? b : a, i, len_a > len_b ? len_b : len_a);
	//检查
	while (ans[i]) {
		if (ans[i] >= '2') {
			ans[i] = ans[i] - 2;
			if (ans[i + 1] == 0)
				ans[i + 1] += '1';
			else
				ans[i + 1] = ans[i + 1] + 1;
		}
		i++;
	}
	int max = i > len ? i : len;
	int l = 0, r = max - 1;
	//翻转
	while (l < r) {
		char tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
		l++;
		r--;
	}
	char* tmp = ans;
	return tmp;
}

void test() {
	char a[10000] = { 0 };
	char b[10000] = { 0 };
	while (scanf("%s%s", a, b) == 2) {
		printf("%s\n", addBinary(a, b));
	}
}

int main() {
	test();
	return 0;
}