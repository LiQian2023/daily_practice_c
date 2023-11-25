#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//2023.11.24力扣刷题
//2 的幂——位运算、递归、数学——简单
//给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
//如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。
//示例 1：
//输入：n = 1
//输出：true
//解释：20 = 1
//示例 2：
//输入：n = 16
//输出：true
//解释：24 = 16
//示例 3：
//输入：n = 3
//输出：false
//示例 4：
//输入：n = 4
//输出：true
//示例 5：
//输入：n = 5
//输出：false
//提示：
//- 2^31 <= n <= 2^31 - 1
//1——0001
//2——0010
//4——0100——0110——6
//6——0110——0100——4
//8——1000
//10——1010——1000——8
//12——1100——1110——14
//16——0001 0000
//迭代求解
bool isPowerOfTwo1(int n) {
	while (n > 2 || n <= 0)
	{
		if ((n % 2 != 0) || (0 == n))
			return false;
		n >>= 1;
	}
	/*if (n == 0)
		return false;*/
	return true;
}
//递归求解
bool isPowerOfTwo(int n) {
	bool a = true;
	if ((n > 2) || (n <= 0))
	{
		if ((0 != n % 2) || (0 == n))
			return false;
		a = isPowerOfTwo(n >>= 1);
	}
	if (n == 2 || n == 1 || a)
		return true;
}
int main()
{
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		bool a = isPowerOfTwo1(n);
		printf("%d\n", a);
	}
	return 0;
}

//int main()
//{
//	printf("%d\n", 1 << 31);
//	return 0;
//}