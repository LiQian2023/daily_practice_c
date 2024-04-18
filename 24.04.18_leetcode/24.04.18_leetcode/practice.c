#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//2024.04.18力扣网刷题
//七进制数——数学——简单
//给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。
//示例 1:
//输入: num = 100
//输出 : "202"
//示例 2 :
//	输入 : num = -7
//	输出 : "-10"
//	提示：
//	- 10^7 <= num <= 10^7

char* convertToBase71(int num) {
	if (num == 0)
		return "0";
	int a = num;
	if (num < 0)
		a = -a;
	int n = 0;
	while (a) {
		n++;
		a /= 7;
	}
	char* nums = (char*)calloc(n + 2, sizeof(char));
	int i = 0;
	if (num < 0) {
		nums[i++] = '-';
		num = -num;
	}
	for (i; num; num /= 7)
		nums[i++] = num % 7 + '0';
	int l = 0, r = i - 1;
	if (nums[l] == '-')
		l++;
	while (l < r) {
		char tmp = nums[l];
		nums[l] = nums[r];
		nums[r] = tmp;
		l++, r--;
	}
	return nums;
}
char* convertToBase7(int num) {
	if (num == 0)
		return "0";
	char* ans = (char*)calloc(11, sizeof(char));
	if (!ans)
		return NULL;
	int i = 0;
	if (num < 0) {
		ans[i++] = '-';
		num = -num;
	}
	for (i; num; num /= 7)
		ans[i++] = num % 7 + '0';
	int l = 0, r = i - 1;
	if (ans[l] == '-')
		l++;
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
		printf("%s\n", convertToBase7(num));
	}
}

int main() {
	test();
	return 0;
}