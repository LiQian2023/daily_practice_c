#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.02.15力扣网刷题
//67. 二进制求和——位运算、数学、字符串、模拟——简单
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

// 方法一：整型溢出，无法通过测试用例
int str_to_int(char* str) {
	int res = 0;
	for (int i = 0; str[i]; i++) {
		res *= 2;
		res += str[i] - '0';
	}
	return res;
}
void reverse(char* str, int len) {
	for (int l = 0, r = len - 1; l < r; l++, r--) {
		char tmp = str[l];
		str[l] = str[r];
		str[r] = tmp;
	}
}
char* int_to_str(int num, int size) {
	char* res = (char*)calloc(size, sizeof(char));
	assert(res);
	int i = 0;
	if(num == 0){
		res[0] = '0';
	}
	else {
		while (num > 0) {
			res[i++] = num % 2 + '0';
			num /= 2;
		}
		reverse(res, i);
	}
	return res;
}

char* addBinary1(char* a, char* b) {
	int len_a = strlen(a), len_b = strlen(b);
	int size = len_a > len_b ? len_a + 2: len_b + 2;
	int num_a = str_to_int(a);
	int num_b = str_to_int(b);
	int sum = num_a + num_b;
	return int_to_str(sum, size);
}
// 方法二：顺序表
char* addBinary(char* a, char* b) {
	int len_a = strlen(a), len_b = strlen(b);
	int size = len_a > len_b ? len_a + 2: len_b + 2;
	char* res = (char*)calloc(size, sizeof(char));
	assert(res);
	int carry = 0, i = 0;
	while (len_a > 0 || len_b > 0 || carry) {
		int sum = carry;
		if (len_a > 0) {
			sum += a[--len_a] - '0';
		}
		if (len_b > 0) {
			sum += b[--len_b] - '0';
		}
		res[i++] = sum % 2 + '0';
		carry = sum / 2;
	}
	res[i] = '\0';
	reverse(res, i);
	return res;
}