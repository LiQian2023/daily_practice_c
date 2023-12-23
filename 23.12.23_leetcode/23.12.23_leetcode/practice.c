#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.23力扣网刷题
// 第 k 个缺失的正整数——数组、二分查找——简单
//给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。
//请你找到这个数组里第 k 个缺失的正整数。
//示例 1：
//输入：arr = [2, 3, 4, 7, 11], k = 5
//输出：9
//解释：缺失的正整数包括[1, 5, 6, 8, 9, 10, 12, 13, ...] 。第 5 个缺失的正整数为 9 。
//示例 2：
//输入：arr = [1, 2, 3, 4], k = 2
//输出：6
//解释：缺失的正整数包括[5, 6, 7, ...] 。第 2 个缺失的正整数为 6 。
//提示：
//1 <= arr.length <= 1000
//1 <= arr[i] <= 1000
//1 <= k <= 1000
//对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j]
//	进阶：
//	你可以设计一个时间复杂度小于 O(n) 的算法解决此问题吗？

//法一：暴力求解
int findKthPositive1(int* arr, int arrSize, int k) {
	int tmp[3000] = { 0 };
	int i = 0, j = 0, z = 0;
	for (i = 1; i < 3000; i++)
	{
		int flag = -1;
		for (j = 0; j < arrSize; j++)
		{
			if (i == arr[j])
			{
				flag = j;
				break;
			}
		}
		if (-1 == flag)
		{
			tmp[z] = i;
			z++;
		}
	}
	return tmp[k - 1];
}
//法二：二分查找
int findKthPositive1(int* arr, int arrSize, int k) {
	int num = arr[arrSize - 1] - (arrSize - 1);
	if (k < num)
	{
		int l = 1, r = arr[arrSize - 1];
		while()
	}
}

int main()
{
	int arr[1000] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int k = 0;
		scanf("%d", &k);
		int ret = findKthPositive(arr, n, k);
		printf("%d\n", ret);
	}
	return 0;
}

////法二：顺序表求解
//#include <stdlib.h>
//#include <stdbool.h>
//#define InitSize 10
//typedef struct
//{
//	int* date;
//	int MaxSize, length;
//}Sqlist;
////顺序表初始化
//void IntiList(Sqlist* L)
//{
//	L->date = (int*)calloc(sizeof(int), InitSize);
//	L->MaxSize = InitSize;
//	L->length = 0;
//}
////修改表长
//bool IncreasSize(Sqlist* L, int len)
//{
//	L->date = (int*)realloc(L->date, L->MaxSize + len);
//	if (!L->date)
//	{
//		perror("L->date");
//		return false;
//	}
//	return true;
//}
////增加与删除元素