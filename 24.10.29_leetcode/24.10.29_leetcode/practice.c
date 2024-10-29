#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.10.29力扣网刷题
//汉诺塔问题——递归、数组——简单
//在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。
//一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
//(1) 每次只能移动一个盘子;
//(2) 盘子只能从柱子顶端滑出移到下一根柱子;
//(3) 盘子只能叠在比它大的盘子上。
//请编写程序，用栈将所有盘子从第一根柱子移到最后一根柱子。
//你需要原地修改栈。
//示例1 :
//输入：A = [2, 1, 0], B = [], C = []
//输出：C = [2, 1, 0]
//示例2 :
//输入：A = [1, 0], B = [], C = []
//输出：C = [1, 0]
//提示 :
//A中盘子的数目不大于14个。

//方法一：递归——力扣无法通过
void move(int* a, int* len1, int* c, int* len3) {
	c[*len3] = a[*len1 - 1];
	*len3 += 1;
	*len1 -= 1;
}
void dfs(int* a, int* len1, int* b, int* len2, int* c, int* len3, int n) {
	if (n == 1) {
		c[*len3] = a[*len1 - 1];
		*len3 += 1;
		*len1 -= 1;
		return;
	}
	dfs(a, len1, c, len3, b, len2, n - 1);
	move(a, len1, c, len3);
	dfs(b, len2, a, len1, c, len3, n - 1);
}
void hanota(int* A, int ASize, int* B, int BSize, int** C, int* CSize) {
	CSize = (int*)calloc(1, sizeof(int));
	assert(CSize);
	B = (int*)calloc(ASize, sizeof(int));
	assert(B);
	*C = (int**)calloc(1, sizeof(int*));
	assert(*C);
	*C = (int*)calloc(ASize, sizeof(int));
	assert(C);
	dfs(A, &ASize, B, &BSize, *C, CSize, ASize);
	free(B);
}