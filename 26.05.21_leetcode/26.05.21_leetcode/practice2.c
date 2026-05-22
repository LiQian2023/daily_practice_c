#include <stdio.h>

//2026.05.21力扣网刷题
//5579. 增加模数——快速幂——简单
//给定 H 对非负整数数对(Ai, Bi) 和一个正整数 M。
//请你计算并输出(AB11 + AB22 + … + ABHH)modM。
//输入格式
//第一行包含整数 T，表示共有 T组测试数据。
//每组数据第一行包含整数 M。
//第二行包含整数 H。
//接下来 H 行，每行包含两个整数 Ai, Bi。
//输出格式
//每组数据输出一行结果。
//数据范围
//1≤T≤100,
//1≤M≤45000,
//1≤H≤45000,
//0≤Ai, Bi≤10^7,
//Ai和 Bi不同时为 0。
//输入样例：
//3
//16
//4
//2 3
//3 4
//4 5
//5 6
//36123
//1
//2374859 3029382
//17
//1
//3 18132
//输出样例：
//2
//13195
//13
typedef int ElemType;
ElemType myMul(ElemType a, ElemType b, ElemType p) {
	ElemType ans = 0;
	a %= p;
	while (b) {
		if (b & 1) {
			ans = (ans + a) % p;
		}
		a = a * 2 % p;
		b >>= 1;
	}
	return ans;
}
ElemType myPow(ElemType a, ElemType b, ElemType p) {
	ElemType ans = 1 % p;
	a %= p;
	for (; b; b >>= 1) {
		if (b & 1) {
			ans = ans * a % p;
		}
		a = a * a % p;
	}
	return ans % p;
}

int main() {
	ElemType T = 0;
	while (scanf("%d", &T) == 1) {
		ElemType M = 0, N = 0;
		for (ElemType i = 0; i < T; i++) {
			if (scanf("%d%d", &M, &N) == 2) {
				ElemType sum = 0;
				// 计算和
				for (int j = 0; j < N; j += 1) {
					ElemType a = 0, b = 0;
					ElemType ret = scanf("%d%d", &a, &b);
					switch (ret) {
						case 2:
							sum = (sum + myPow(a, b, M)) % M;
							break;
						default:
							break;
					}
				}
				ElemType ans = sum % M;
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
