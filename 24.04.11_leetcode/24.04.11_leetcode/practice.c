#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//2024.04.11力扣网刷题
//矩阵置零——数组、哈希表、矩阵——中等
//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
//示例 1：
//输入：matrix = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
//输出： [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
//示例 2：
//输入：matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
//输出： [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]
//提示：
//m == matrix.length
//n == matrix[0].length
//1 <= m, n <= 200
//- 2^31 <= matrix[i][j] <= 2^31 - 1
//进阶：
//一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
//你能想出一个仅使用常量空间的解决方案吗？


//法一：单链表
typedef struct ListNode {
	int i;
	int j;
	struct ListNode* next;
}ListNode, * LinkList;

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
	LinkList L = (ListNode*)calloc(1, sizeof(ListNode));
	if (!L)
		return;
	//头结点指针域初始化
	L->next = NULL;
	//表尾指针
	ListNode* p = L;
	//记录矩阵中为数据为0的下标
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < (*matrixColSize); j++) {
			if (matrix[i][j] == 0) {
				ListNode* s = (ListNode*)calloc(1, sizeof(ListNode));
				if (!s)
					return;
				s->i = i;
				s->j = j;
				//尾插法建立链表
				s->next = p->next;
				p->next = s;
				p = s;
			}
		}
	}
	p = L->next;
	//矩阵置0
	while (p) {
		//行置0
		for (int row = p->i , col = 0; col < *matrixColSize; col++) {
			if (matrix[row][col] == 0)
				continue;
			matrix[row][col] = 0;
		}
		//列置0
		for (int row = 0, col = p->j; row < matrixSize; row++) {
			if (matrix[row][col] == 0)
				continue;
			matrix[row][col] = 0;
		}
		//销毁结点
		L->next = p->next;
		free(p);
		//遍历下一个结点
		p = L->next;
	}
	free(L);
}

