#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.05.18力扣网刷题
//89. a ^ b——位运算、快速幂——简单
//求 a
//的 b
//次方对 p
//取模的值。
//输入格式
//三个整数 a, b, p
//, 在同一行用空格隔开。
//输出格式
//输出一个整数，表示a^ b mod p的值。
//数据范围
//0≤a, b≤10^9
//1≤p≤10^9
//输入样例：
//3 2 7
//输出样例：
//2

// 公式：
// a^b = a ^\sum{c_i * 2^i}
// a^b = a^{c_0 * 2^0} * a^{c_1 * 2^1} * ... * a^{c_k - 1 * 2^{k - 1}}
// a ^ { 2 ^ i} = (a ^ {2 ^{i - 1}})^2
// a^{2^1} = (a^2^0)^2
int myPow(int a, int b, int p) {
	int ans = 1 % p;
	for (; b; b >>= 1) {
		// 获取C_i
		int c = b & 1;
		// 获取 a^{2^i}
		if (c) {
			// ans = 1 * (a ^ 2^0 % p) * (a ^ 2 ^ 1 % p) * ... * (a * 2 ^ {k - 1} % p)
			ans = (long long)ans * a % p;
		}
		// a ^ i = a ^ {2 ^ {i - 1}}^2
		a = (long long)a * a % p;
	}
	return ans;
}

int main() {
	int a = 0, b = 0, p = 0;
	while (scanf("%d%d%d", &a, &b, &p) == 3) {
		int ans = myPow(a, b, p);
		printf("%d\n", ans);
	}
	return 0;
}