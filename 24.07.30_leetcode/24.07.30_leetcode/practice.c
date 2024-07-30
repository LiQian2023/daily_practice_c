#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
//2024.07.30力扣网刷题
//双模幂运算——数组、数学、模拟——中等
//给你一个下标从 0 开始的二维数组 variables ，其中 variables[i] = [ai, bi, ci, mi]，以及一个整数 target 。
//如果满足以下公式，则下标 i 是 好下标：
//0 <= i < variables.length
//((ai^bi % 10)^ci) % mi == target
//返回一个由 好下标 组成的数组，顺序不限 。
//示例 1：
//输入：variables = [[2, 3, 3, 10], [3, 3, 3, 1], [6, 1, 1, 4]], target = 2
//输出：[0, 2]
//解释：对于 variables 数组中的每个下标 i ：
//1) 对于下标 0 ，variables[0] = [2, 3, 3, 10] ，(2^3 % 10)^3 % 10 = 2 。
//2) 对于下标 1 ，variables[1] = [3, 3, 3, 1] ，(3^3 % 10)^3 % 1 = 0 。
//3) 对于下标 2 ，variables[2] = [6, 1, 1, 4] ，(6^1 % 10)^1 % 4 = 2 。
//因此，返回[0, 2] 作为答案。
//示例 2：
//输入：variables = [[39, 3, 1000, 1000]], target = 17
//输出：[]
//解释：对于 variables 数组中的每个下标 i ：
//1) 对于下标 0 ，variables[0] = [39, 3, 1000, 1000] ，(393 % 10)1000 % 1000 = 1 。
//因此，返回[] 作为答案。
//提示：
//1 <= variables.length <= 100
//variables[i] == [ai, bi, ci, mi]
//1 <= ai, bi, ci, mi <= 10^3
//0 <= target <= 10^3

//模运算与基本四则运算有些相似，但是除法例外。其规则如下：
//1.(a + b) % p = (a % p + b % p) % p （1）
//2.(a - b) % p = (a % p - b % p) % p （2）
//3.(a * b) % p = (a % p * b % p) % p （3）
//4.a ^ b % p = ((a % p) ^ b) % p （4）
//结合律：
//((a + b) % p + c) % p = (a + (b + c) % p) % p （5）
//((a * b) % p * c) % p = (a * (b * c) % p) % p （6）
//交换律：
//(a + b) % p = (b + a) % p （7）
//(a * b) % p = (b * a) % p （8）
//分配律：
//(a + b) % p = (a % p + b % p) % p（9）
//((a + b) % p * c) % p = ((a * c) % p + (b * c) % p) % p （10）
//((ai^ bi % 10) ^ ci) % mi——(((((a%10)^b))%10)%m)^c)%m

//方法一：快速幂
int QuickPower(int num, int p,int mod) {
	if (p == 1)
		return num % mod;
	int num1 = 1, num2 = 1;
	num1 = QuickPower(num, p / 2, mod);
	if (p % 2) {
		num2 *= (num1 % mod * num % mod) % mod;
	}
	else
		num2 = num1;
	return (num1 % mod * num2 % mod) % mod;
}
int* getGoodIndices(int** variables, int variablesSize, int* variablesColSize, int target, int* returnSize) {
	int* ans = (int*)calloc(variablesSize, sizeof(int));
	assert(ans);
	*returnSize = 0;
	for (int i = 0; i < variablesSize; i++) {
		//int num1 = QuickPower(variables[i][0], variables[i][1], 10);
		//int num2 = QuickPower(num1, variables[i][2], variables[i][3]);
		//if (num2 == target) {
		int a = variables[i][0];
		int b = variables[i][1];
		int c = variables[i][2];
		int m = variables[i][3];
		if (b % 4 == 0)
			b = 4;
		int num1 = QuickPower(a, b, 10);
		int num = QuickPower(num1, c, m);
		if (num == target) {
			ans[*returnSize] = i;
			*returnSize += 1;
		}
	}
	return ans;
}

void test() {
	int nums[4][4] = { { 2,3,3,10 }, {6,1,1,4},{31,12,21,24},{51,35,21,52} };
	int* pnums[4] = { nums[0],nums[1],nums[2],nums[3] };
	int m = 4, n = 4;
	int k = 2;
	int size = 0;
	int* ret = getGoodIndices(pnums, m, &n, k, &size);
	for (int i = 0; i < size; i++) {
		printf("%d ", ret[i]);
	}
	free(ret);
}

int main() {
	test();
	return 0;
}