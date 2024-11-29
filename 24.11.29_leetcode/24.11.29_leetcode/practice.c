#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.11.29力扣网刷题
//阶乘尾数——数学——简单
//设计一个算法，算出 n 阶乘有多少个尾随零。
//示例 1:
//输入: 3
//输出 : 0
//解释 : 3!= 6, 尾数中没有零。
//示例 2 :
//输入 : 5
//输出 : 1
//解释 : 5!= 120, 尾数中有 1 个零.
//说明 : 你算法的时间复杂度应为 O(log n) 。



int trailingZeroes(int n) {
	int ans = 0;
	while (n) {
		n /= 5;
		ans += n;
	}
	return ans;
}