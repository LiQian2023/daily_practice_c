#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.15力扣网刷题
//统计有序矩阵中的负数——数组、二分查找、矩阵——简单
//给你一个 m* n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 请你统计并返回 grid 中 负数 的数目。
//示例 1：
//输入：grid = [[4, 3, 2, -1], [3, 2, 1, -1], [1, 1, -1, -2], [-1, -1, -2, -3]]
//输出：8
//解释：矩阵中共有 8 个负数。
//示例 2：
//输入：grid = [[3, 2], [1, 0]]
//输出：0
//提示：
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 100
//- 100 <= grid[i][j] <= 100
//进阶：你可以设计一个时间复杂度为 O(n + m) 的解决方案吗？

//方法一：二分查找——逻辑错误——无法判断mid是否为第一个负数
int countNegatives1(int** grid, int gridSize, int* gridColSize) {
	int num = 0;
	for (int i=0; i < gridSize; i++)
	{
		int l = 0, r = *gridColSize - 1;
		if (grid[i][r] >= 0)
			num += 0;
		else if (grid[i][l] < 0)
			num += r + 1;
		else {
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (grid[i][mid] >= 0)
					l = mid + 1;
				else
				{
					num += 1;
					l = mid + 1;
				}
			}
		}
	}
	return num;
}
//方法二：循序查找
int countNegatives2(int** grid, int gridSize, int* gridColSize) {
	int num = 0;
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < *gridColSize; j++)
			if (grid[i][j] < 0)
				num++;
	}
	return num;
}
//方法三：二分查找——使用二分查找找到第一个负数
int countNegatives3(int** grid, int gridSize, int* gridColSize) {
	int num = 0;
	for (int i = 0; i < gridSize; i++)
	{
		int l = 0, r = *gridColSize - 1;
		int flag = -1;//第一个负数下标
		if (grid[i][r] >= 0)
			num += 0;
		else if (grid[i][l] < 0)
			num += r + 1;
		else {
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if (grid[i][mid] >= 0)
					l = mid + 1;
				else
				{
					flag = mid;//找到负数就替换标志存储的值
					r = mid - 1;
				}
				
			}
			if (flag != -1)
				num += *gridColSize - flag;
		}
	}
	return num;
}
//int main(){
//	int arr[100][100] = { 0 };
//	int m = 0, n = 0;
//	while (scanf("%d%d", &m, &n) == 2){
//		//二维数组赋值
//		for (int i = 0; i < m; i++)
//			for (int j = 0; j < n; j++)
//				scanf("%d", &arr[i][j]);
//		//指针数组
//		int* parr[100] = { 0 };
//		int size = 0;
//		//指针数组接收二维数组
//		for (int i = 0; i < m; i++)
//			parr[size++] = arr[i];
//		//指针数组传参，二级指针接收
//		int ret = countNegatives(parr, m, &n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}

////方法四：二分查找优化
//int countNegatives(int** grid, int gridSize, int* gridColSize) {
//	int num = 0, l = 0, r = gridSize - 1, flag = -1;
//	while (l <= r)
//	{
//		int mid = (l + r) / 2;
//		if (gridColSize[mid] < 0)
//		{
//			flag = mid;
//			r = mid - 1;
//		}
//		else
//			l = mid + 1;
//	}
//	if (-1 != flag)
//		num += gridSize - flag;
//	return num;
//}
//int main() {
//	int arr[100][100] = { 0 };
//	int m = 0, n = 0;
//	while (scanf("%d%d", &m, &n) == 2) {
//		//二维数组赋值
//		for (int i = 0; i < m; i++)
//			for (int j = 0; j < n; j++)
//				scanf("%d", &arr[i][j]);
//		//指针数组
//		int* parr[100] = { 0 };
//		int size = 0;
//		//指针数组接收二维数组
//		for (int i = 0; i < m; i++)
//			parr[size++] = arr[i];
//		//指针数组传参，二级指针接收
//		int ret = 0;
//		for (int i = 0; i < n; i++)
//		{
//			ret += countNegatives(parr, n, parr[i]);
//		}
//		printf("%d\n", ret);
//	}
//	return 0;
//}

//void test(int** ppa, int rol, int* col)
//{
//	for (int i = 0; i < rol; i++)
//	{
//		for (int j = 0; j < *col; j++)
//			printf("%d ", ppa[i][j]);
//	}
//}
//
//int main()
//{
//	int arr[2][3] = { 1,2,3,4,5,6 };
//	int* parr[3] = { arr[0],arr[1] };
//	test(parr, 2, &arr[0]);
//	return 0;
//}

void test(int** ppa, int rol, int* pa)
{
	for (int i = 0; i < rol; i++)
	{
		printf("%d ", pa[i]);
	}
}
int main()
{
	int arr[2][3] = { 1,2,3,4,5,6 };
	int* pa[2] = { arr[0],arr[1] };
	for (int i = 0; i < 2; i++)
	{
		test(pa, 6, pa[i]);
	}
	return 0;
}