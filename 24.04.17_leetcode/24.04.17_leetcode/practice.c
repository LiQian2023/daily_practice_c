#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//2024.04.17力扣网刷题
//数字转换为十六进制数——位运算、数学——简单
//给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
//注意:
//十六进制中所有字母(a - f)都必须是小写。
//十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。
//给定的数确保在32位有符号整数范围内。
//不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
//示例 1：
//输入 :
//26
//输出 :
//	"1a"
//	示例 2：
//	输入 :
//-1
//输出 :
//	"ffffffff"

char* toHex(int num) {
	if (num == 0)
		return "0";
	char* ans = (char*)calloc(9, sizeof(char));
	int len = 0;
	int sum = 0;
	int n = 0;
	for (int i = 1; i <= 32 && num; i++) {
		if (n == 4) {
			if (sum >= 10) {
				ans[len++] = sum - 10 + 'a';
			}
			else {
				ans[len++] = sum + '0';
			}
			sum = 0;
			n = 0;
		}
		sum += (int)pow(2, n) * (num & 1);
		num >>= 1;
		n++;
	}
	if (sum >= 10) {
		ans[len++] = sum - 10 + 'a';
	}
	else {
		ans[len++] = sum + '0';
	}
	int l = 0, r = len - 1;
	while (l < r) {
		char tmp = ans[l];
		ans[l] = ans[r];
		ans[r] = tmp;
		l++, r--;
	}
	return ans;
}

void test() {
	int num = 0;
	while (scanf("%d", &num) == 1) {
		printf("%s\n", toHex(num));
	}
}
int main() {
	test();
	return 0;
}