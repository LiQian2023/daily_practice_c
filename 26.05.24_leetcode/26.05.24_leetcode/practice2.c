//2026.05.24力扣网刷题
//92. 递归实现指数型枚举——递归——简单
//从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。
//输入格式
//输入一个整数 n。
//输出格式
//每行输出一种方案。
//同一行内的数必须升序排列，相邻两个数用恰好 1
//个空格隔开。
//对于没有选任何数的方案，输出空行。
//本题有自定义校验器（SPJ），各行（不同方案）之间的顺序任意。
//数据范围
//1≤n≤15
//输入样例：
//3
//输出样例：
//3
//2
//2 3
//1
//1 3
//1 2
//1 2 3

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void DFS(int n, int* data, int* pi) {
	if (n == 0) {
		if (*pi == 0) {
			printf(" \n");
		}
		else {
			for (int i = *pi - 1; i >= 0; i--) {
				printf("%d ", data[i]);
			}
			printf("\n");
		}
		return;
	}
	data[*pi] = n;
	*pi += 1;
	DFS(n - 1, data, pi);
	*pi -= 1;
	DFS(n - 1, data, pi);
}

int main() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int* stack = (int*)calloc(n + 1, sizeof(int));
		assert(stack);
		int top = 0;
		DFS(n, stack, &top);
		free(stack);
		stack = NULL;
	}
	return 0;
}