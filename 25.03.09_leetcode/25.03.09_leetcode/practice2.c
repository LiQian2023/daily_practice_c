#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
//2025.03.09灰灰考研实时事件
//1.知名考研教师何文在多次考试中面临选择：公布真实分数或伪造高分以提升影响力。
//每次选择造假会带来短期收益，但若累计造假次数过多，将面临声誉损失和行业惩罚直至全网封禁。
//请你设计一个动态规划算法，帮助他制定最优策略以最大化总收益。
//问题描述给定一个长度为 n 的数组 real[] 和 fake[]，分别代表第 i 次考试的真实分数收益和虚假分数收益。
//另给定整数k，表示连续造假的最大容忍次数，超过此次数后，每次造假的收益会因声誉损失而减半。
//请计算在n 次考试中，如何选择真实或虚假分数，使得总收益最大。
//输入格式
//第一行两个整数 n 和 k
//第二行 n 个整数，表示 real[i]
//第三行 n 个整数，表示 fake[i]
//输出格式
//一个整数，表示最大总收益
//示例
//输入n = 3, k = 1  
//real = [5, 2, 3] 
//fake = [3, 7, 4] 
//输出12  
//解释 
//最优策略为：第1次真实（收益5），第2次造假（收益7），第3次真实（收益3）。
//总收益为5 + 7 + 3 = 15。
//若第2次造假后第3次继续造假，则因连续造假2次（超过k = 1），第3次造假收益变为4 / 2 = 2，总收益为5 + 7 + 2 = 14，非最优。

int Englist_Text1(int n, int k, int* real, int* fake) {
	int* dp = (int*)calloc(n, sizeof(int));
	assert(dp);
	int count = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = real[i];//真实
		if (real[i] < fake[i]) {
			count += 1;
			if (count > k) {
				if (fake[i] / 2 > real[i]) {
					dp[i] = fake[i] / 2;//造假
				}
				else {
					count -= 1;//未造假
				}
			}
			else {
				dp[i] = fake[i];//造假
			}
		}
		sum += dp[i];
	}
	free(dp);
	dp = NULL;
	return sum;
}

//2.问题描述
//小七和张哥在森林里收集了 m 堆香蕉，准备分给n 个小朋友。
//每个小朋友有一个需求值a[i]，表示至少需要拿到a[i] 个香蕉。
//每堆香蕉只能分配给一个小朋友，且必须满足该小朋友的需求。
//请问最多能有多少个小朋友被满足？
//输入格式
//第一行：两个整数 n 和 m，分别表示小朋友数量和香蕉堆数量。
//第二行：n 个整数，表示每个小朋友的需求值 a[1..n]。
//第三行：m 个整数，表示每堆香蕉的数量 b[1..m]。
//输出格式
//一个整数，表示最多能满足的小朋友数量。
//示例
//输入
//3 3
//2 3 4
//3 2 4
//示例
//输出
//2
//样例解释
//需求为 2 和 3 的小朋友可以分别拿到香蕉堆2 和 3，或者需求 3 和 4 拿到香蕉 3 和 4。

int Math_Text(int n, int m, int* childs, int* bananas) {
	int ans = 0;
	for (int i = 0; i < n && i < m; i++) {
		if (childs[i] <= bananas[i]) {
			ans += 1;
		}
	}
	return ans;
}