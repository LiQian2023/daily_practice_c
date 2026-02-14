#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.02.14力扣网刷题
//3726. 移除十进制表示中的所有零——中级工程师、数学、模拟、第473场周赛——简单
//给你一个正整数n。
//返回一个整数，该整数是将 n 的十进制表示中所有的零都移除后得到的结果。
//示例 1：
//输入： n = 1020030
//输出： 123
//解释：
//从 1020030 中移除所有的零后，得到 123。
//示例 2：
//输入： n = 1
//输出： 1
//解释：
//1 的十进制表示中没有零，因此结果为 1。
//提示：
//1 <= n <= 10^15

void str(long long n, char* s) {
	int i = 1;
	for (i, n; n; n /= 10) {
		if (n % 10 != 0) {
			s[i] = n % 10 + '0';
			i++;
		}
	}
	s[0] = i - 1 + '0';
}
void reverse(char* s) {
	for (int l = 1, r = s[0] - '0'; l < r; l++, r--) {
		char tmp = s[l];
		s[l] = s[r];
		s[r] = tmp;
	}
}
long long removeZeros(long long n) {
	char* ans = (char*)calloc(18, sizeof(char));
	assert(ans);
	str(n, ans);
	reverse(ans);
	long long res = 0;
	for (int i = 1; i <= ans[0] - '0'; i++) {
		res *= 10;
		res += ans[i] - '0';
	}
	free(ans);
	return res;
}