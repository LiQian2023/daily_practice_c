#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdllib>
//2024.09.12力扣网刷题
//合并排序的数组——数组、双指针、排序——简单
//给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
//初始化 A 和 B 的元素数量分别为 m 和 n。
//示例 :
//输入:
//A = [1, 2, 3, 0, 0, 0], m = 3
//B = [2, 5, 6], n = 3
//输出 : [1, 2, 2, 3, 5, 6]
//说明 :
//A.length == n + m

//方法一：归并排序
void merge(int* A, int ASize, int m, int* B, int BSize, int n) {
	int i = m - 1, j = n - 1, z = m + n - 1;
	while(i >= 0 && j >= 0) {
		if (A[i] >= B[j]) {
			A[z--] = A[i];
			i -= 1;
		}
		else {
			A[z--] = B[j];
			j -= 1;
		}
	}
	while (j >= 0) {
		A[z--] = B[j--];
	}
}
