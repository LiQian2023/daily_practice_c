#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//2024.04.14力扣网刷题
//字符串相乘——数学、字符串、模拟——中等
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
//示例 1:
//输入: num1 = "2", num2 = "3"
//输出 : "6"
//示例 2 :
//	输入 : num1 = "123", num2 = "456"
//	输出 : "56088"
//	提示：
//	1 <= num1.length, num2.length <= 200
//	num1 和 num2 只能由数字组成。
//	num1 和 num2 都不包含任何前导零，除了数字0本身。

//方法一：模拟
char* multiply(char* num1, char* num2) {
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	char* ans = (char*)calloc(len1 + len2 + 1, sizeof(char));
	int len3 = 0;
	int flag = 0;//回退标记
	for (int i = len1 - 1; i >= 0; i--) {
		int one = 0, ten = 0;
		for (int j = len2 - 1; j >= 0; j--) {
			one = ((num1[i] - '0') * (num2[j] - '0') + ten) % 10;
			ten = ((num1[i] - '0') * (num2[j] - '0') + ten) / 10;
			if (ans[len3])
			{
				ten += (ans[len3] - '0' + one) / 10;
				ans[len3] = (ans[len3] - '0' + one) % 10 + '0';
			}
			else {
				ten += (ans[len3 + 1] + one) / 10;
				ans[len3] = (ans[len3] + one) % 10 + '0';
			}
			if (ans[len3])
				len3++;
		}
		if (ten)
			ans[len3] = ten + '0';
		flag++;//移动标记
		len3 = flag;
	}
	len3 = strlen(ans);
	for (int i = 0, j = len3 - 1; i < j; i++, j--) {
		char tmp = ans[i];
		ans[i] = ans[j];
		ans[j] = tmp;
	}
	if (ans[0] == '0')
		ans[1] = 0;
	return ans;
}

void test() {
	char a[5] = { 0 };
	char b[5] = { 0 };
	while (scanf("%s%s", a, b) == 2) {
		char* ret = multiply(a, b);
		printf("%s\n", ret);
		free(ret);
	}
}

int main() {
	test();
	return 0;
}