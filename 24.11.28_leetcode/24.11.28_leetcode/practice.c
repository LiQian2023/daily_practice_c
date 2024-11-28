#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.11.28力扣网刷题
//三步问题——记忆化搜索、数学、动态规划——简单
//三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。
//示例1 :
//输入：n = 3
//输出：4
//说明 : 有四种走法
//示例2 :
//输入：n = 5
//输出：13
//提示 :
//n范围在[1, 1000000]之间

#define MOD 1000000007

int waysToStep(int n) {
	if (n < 3)
		return n;
	int a = 1, b = 1, c = 2, d = 4;
	for (int i = 4; i <= n; i++) {
		a = b % MOD;
		b = c % MOD;
		c = d % MOD;
		d = ((a + b) % MOD + c) % MOD;
	}
	return d;
}