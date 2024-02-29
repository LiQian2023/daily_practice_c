#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//2024.02.24力扣网刷题
//比特位计数——位运算、动态规划——简单
//给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
//示例 1：
//输入：n = 2
//输出：[0, 1, 1]
//解释：
//0 -- > 0
//1 -- > 1
//2 -- > 10
//示例 2：
//输入：n = 5
//输出：[0, 1, 1, 2, 1, 2]
//解释：
//0 -- > 0
//1 -- > 1
//2 -- > 10
//3 -- > 11
//4 -- > 100
//5 -- > 101
//提示：
//0 <= n <= 105
//进阶：
//很容易就能实现时间复杂度为 O(n log n) 的解决方案，你可以在线性时间复杂度 O(n) 内用一趟扫描解决此问题吗？
//你能不使用任何内置函数解决此问题吗？（如，C++ 中的 __builtin_popcount ）

int* countBits(int n, int* returnSize) {
	int* ans = (int*)calloc(n + 1, sizeof(int));
	if (!ans)
		return NULL;
	*returnSize = n + 1;
	for (int i = 0; i <= n; i++) {
		int count = 0;
		for (int j = i; j; j >>= 1) {
			if (j & 1)
				count++;
		}
		ans[i] = count;
	}
	return ans;
}