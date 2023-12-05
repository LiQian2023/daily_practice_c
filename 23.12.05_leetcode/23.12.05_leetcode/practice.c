#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2023.12.05力扣网刷题
//山脉数组的峰顶索引——数组、二分查找——简单
//符合下列属性的数组 arr 称为 山脉数组 ：
//arr.length >= 3
//存在 i（0 < i < arr.length - 1）使得：
//	arr[0] < arr[1] < ... arr[i - 1] < arr[i]
//	arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//	给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。
//	你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。
//	示例 1：
//	输入：arr = [0, 1, 0]
//	输出：1
//	示例 2：
//	输入：arr = [0, 2, 1, 0]
//	输出：1
//	示例 3：
//	输入：arr = [0, 10, 5, 2]
//	输出：1
//	提示：
//	3 <= arr.length <= 105
//	0 <= arr[i] <= 106
//	题目数据保证 arr 是一个山脉数组

int peakIndexInMountainArray(int* arr, int arrSize) {
	int left = 0;
	int right = arrSize - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < arr[mid - 1])
			right = mid - 1;
		if (arr[mid] < arr[mid + 1])
			left = mid + 1;
		if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
			return mid;
	}
	return -1;
}
int main()
{
	int arr[105] = { 0 };
	int n = 0;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		printf("%d\n", peakIndexInMountainArray(arr, n));
	}
	return 0;
}