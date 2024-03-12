#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//2024.03.12力扣网刷题
//整数反转——数学——中等
//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//如果反转后整数超过 32 位的有符号整数的范围[−2^31, 2^31 − 1] ，就返回 0。
//假设环境不允许存储 64 位整数（有符号或无符号）。
//示例 1：
//输入：x = 123
//输出：321
//示例 2：
//输入：x = -123
//输出： - 321
//示例 3：
//输入：x = 120
//输出：21
//示例 4：
//输入：x = 0
//输出：0
//提示：
//- 2^31 <= x <= 2^31 - 1

#define MAX 2147483647
#define MIN -2147483648
int reverse(int x) {
	int i = 0;
	int ans = 0;
	while (x) {
		if (ans > MAX / 10 || ans < MIN / 10)
			return 0;
		ans *= 10;
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

void test() {
	int x = -123;
	int a = 0;
	for (int i = 3; i; i--) {
		printf("%d\n", x % 10);
		a *= 10;
		a += x % 10;
		printf("a = %d\n", a);
		x /= 10;
		printf("x = %d\n", x);
	}
	printf("MAX = %d\n", MAX);
	printf("MIN = %d\n", MIN);
}

int main() {
	test();
	return 0;
}