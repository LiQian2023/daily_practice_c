#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//2024.10.07力扣网刷题
//有序矩阵中第 K 小的元素——数组、二分查找、矩阵、排序、堆（优先队列）——中等
//给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
//请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。
//你必须找到一个内存复杂度优于 O(n2) 的解决方案。
//示例 1：
//输入：matrix = [[1, 5, 9], [10, 11, 13], [12, 13, 15]], k = 8
//输出：13
//解释：矩阵中的元素为[1, 5, 9, 10, 11, 12, 13, 13, 15]，第 8 小元素是 13
//示例 2：
//输入：matrix = [[-5]], k = 1
//输出： - 5
//提示：
//n == matrix.length
//n == matrix[i].length
//1 <= n <= 300
//- 10^9 <= matrix[i][j] <= 10^9
//题目数据 保证 matrix 中的所有行和列都按 非递减顺序 排列
//1 <= k <= n^2
//进阶：
//你能否用一个恒定的内存(即 O(1) 内存复杂度)来解决这个问题 ?
//你能在 O(n) 的时间复杂度下解决这个问题吗 ? 这个方法对于面试来说可能太超前了，但是你会发现阅读这篇文章（ this paper ）很有趣。

void Swap(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int kthSmallest1(int** matrix, int matrixSize, int* matrixColSize, int k) {
	//排序——保证每行的数值都小于下一行的数值
	for (int i = 0; i < matrixSize - 1; i++) {
		int r = matrixColSize[i];//每一行的元素个数
		if (matrix[i][r - 1] > matrix[i + 1][0])//该行的最后一个元素大于下一行的首元素
			Swap(&matrix[i][r - 1], &matrix[i + 1][0]);
	}
	//确定要查找的行
	int target_row = k / matrixSize;
	int target_col = k % matrixSize;
	if (!target_col)
		target_row -= 1;
	//排序目标行
	for (int i = 0; i < matrixColSize[target_row] - 1; i++) {
		if (matrix[target_row][i] > matrix[target_row][i + 1])
			Swap(&matrix[target_row][i], &matrix[target_row][i + 1]);
	}
	return target_col ? matrix[target_row][target_col - 1] : matrix[target_row][matrixColSize[target_row] - 1];
}

//TopK——堆的应用
void Adjust_Down(int* a, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && a[child] < a[child + 1])
			child += 1;
		if (a[parent] < a[child])
			Swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* a, int len) {
	//建堆
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down(a, len, i);
	}
	//排序
	for (int i = len - 1; i > 0; i--) {
		Swap(&a[i], &a[0]);
		Adjust_Down(a, i, 0);
	}
 }

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
	int base = matrixSize * matrixColSize[0];
	int* h = (int*)calloc(base, sizeof(int));
	assert(h);
	int len = 0;
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixColSize[i]; j++) {
			h[len] = matrix[i][j];
			len += 1;
		}
	}
	HeapSort(h, base);
	int ans = h[k - 1];
	free(h);
	return ans;
}

void test() {
	int a1[2] = { 1,2 };
	int a2[2] = { 1,3 };
	int col[2] = { 2,2 };
	int arr[2] = { a1,a2 };
	int row = 2;
	int k = 2;
	printf("%d\n", kthSmallest(arr, row, col, k));
}

int main() {
	test();
	return 0;
}