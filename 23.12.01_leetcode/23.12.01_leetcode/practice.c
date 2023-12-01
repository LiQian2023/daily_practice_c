#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.01力扣网刷题
//找出叠涂元素——数组、哈希表、矩阵——中等
//给你一个下标从 0 开始的整数数组 arr 和一个 m x n 的整数 矩阵 mat 。arr 和 mat 都包含范围[1，m * n] 内的 所有 整数。
//从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat 单元格涂色。
//请你找出 arr 中在 mat 的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 i 。
//示例 1：
//输入：arr = [1, 3, 4, 2], mat = [[1, 4], [2, 3]]
//输出：2
//解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
//示例 2：
//输入：arr = [2, 8, 7, 4, 1, 3, 5, 6, 9], mat = [[3, 2, 5], [1, 4, 6], [8, 7, 9]]
//输出：3
//解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。
//提示：
//m == mat.length
//n = mat[i].length
//arr.length == m * n
//1 <= m, n <= 105
//1 <= m * n <= 105
//1 <= arr[i], mat[r][c] <= m * n
//arr 中的所有整数 互不相同
//mat 中的所有整数 互不相同
#define M 100
#define N 100
int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) {

}
int main()
{
	int arr[M * N] = { 0 };
	int mat[M][N] = { 0 };
	int m = 0, n = 0;
	scanf("")
	return 0;
}





#if 0
////倍数求和——数学——简单
////给你一个正整数 n ，请你计算在 [1，n] 范围内能被 3、5、7 整除的所有整数之和。
////返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。
////示例 1：
////输入：n = 7
////输出：21
////解释：在[1, 7] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7 。数字之和为 21。
////示例 2：
////输入：n = 10
////输出：40
////解释：在[1, 10] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9、10 。数字之和为 40。
////示例 3：
////输入：n = 9
////输出：30
////解释：在[1, 9] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9 。数字之和为 30。
////提示：
////1 <= n <= 103
//int sumOfMultiples1(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (0 == i % 3)
//			sum += i;
//		if (0 == i % 5)
//			sum += i;
//		if (0 == i % 7)
//			sum += i;
//	}
//	return sum;
//}
//int sumOfMultiples(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if ((0 == i % 3) || (0 == i % 5) || (0 == i % 7))
//			sum += i;
//	}
//	return sum;
//	if (0 == sum)
//		return -1;
//}
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) == 1)
//	{
//		int ret = sumOfMultiples(n);
//		printf("%d\n", ret);
//	}
//	return 0;
//}
#endif