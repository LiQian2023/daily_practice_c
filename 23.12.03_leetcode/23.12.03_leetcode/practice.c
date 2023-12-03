#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//2023.12.03力扣网刷题
// 统计好三元组——数学、枚举——简单
//给你一个整数数组 arr ，以及 a、b 、c 三个整数。请你统计其中好三元组的数量。
//如果三元组(arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。
//0 <= i < j < k < arr.length
//	| arr[i] - arr[j]| <= a
//	| arr[j] - arr[k]| <= b
//	| arr[i] - arr[k]| <= c
//	其中 | x | 表示 x 的绝对值。
//	返回 好三元组的数量 。
//	示例 1：
//	输入：arr = [3, 0, 1, 1, 9, 7], a = 7, b = 2, c = 3
//	输出：4
//	解释：一共有 4 个好三元组：[(3, 0, 1), (3, 0, 1), (3, 1, 1), (0, 1, 1)] 。
//	示例 2：
//	输入：arr = [1, 1, 2, 2, 3], a = 0, b = 0, c = 1
//	输出：0
//	解释：不存在满足所有条件的三元组。
//	提示：
//	3 <= arr.length <= 100
//	0 <= arr[i] <= 1000
//	0 <= a, b, c <= 1000
#include <math.h>
int countGoodTriplets(int* arr, int arrSize, int a, int b, int c) {
	int count = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < arrSize - 2; i++)
	{
		for (j = i + 1; j < arrSize - 1; j++)
		{
			for (k = j + 1; k < arrSize; k++)
			{
				if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
					count++;
			}
		}
	}
	return count;
}
int main()
{
	int arr[100] = { 0 };
	int a = 0, b = 0, c = 0;
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		scanf("%d%d%d", &a, &b, &c);
		int ret = countGoodTriplets(arr, n, a, b, c);
		printf("%d\n", ret);
	}
	return 0;
}