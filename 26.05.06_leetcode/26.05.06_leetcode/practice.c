#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.06力扣网刷题
//面试题 05.01.插入——位运算——简单
//给定两个整型数字 N 与 M，以及表示比特位置的 i 与 j（i <= j，且从 0 位开始计算）。
//编写一种方法，使 M 对应的二进制数字插入 N 对应的二进制数字的第 i ~j 位区域，不足之处用 0 补齐。具体插入过程如图所示。
//题目保证从 i 位到 j 位足以容纳 M， 例如： M = 10011，则 i～j 区域至少可容纳 5 位。
//示例 1：
//输入：N = 1024(10000000000), M = 19(10011), i = 2, j = 6
//输出：N = 1100(10001001100)
//示例 2：
//输入：N = 0, M = 31(11111), i = 0, j = 4
//输出：N = 31(11111)

int insertBits(int N, int M, int i, int j) {
	int* tmp = (int*)calloc(32, sizeof(int));
	assert(tmp);
	for (int pi = 31; pi >= 0; pi--) {
		int num = N % 2;
		if (i <= 31 - pi && 31 - pi <= j) {
			num = M % 2;
			M /= 2;
		}
		tmp[pi] = num;
		N /= 2;
	}
	int ans = 0;
	for (int pi = 0; pi < 32; pi++) {
		ans *= 2;
		ans += tmp[pi];
	}
	free(tmp);
	return ans;
}