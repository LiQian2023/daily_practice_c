#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.07.27力扣网刷题
//最小绝对差——数组、排序——简单
//给你个整数数组 arr，其中每个元素都 不相同。
//请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
//每对元素对[a, b] 如下：
//a, b 均为数组 arr 中的元素
//a < b
//b - a 等于 arr 中任意两个元素的最小绝对差
//示例 1：
//输入：arr = [4, 2, 1, 3]
//输出： [[1, 2], [2, 3], [3, 4]]
//示例 2：
//输入：arr = [1, 3, 6, 10, 15]
//输出： [[1, 3]]
//示例 3：
//输入：arr = [3, 8, -10, 23, 19, -4, -14, 27]
//输出： [[-14, -10], [19, 23], [23, 27]]
//提示：
//2 <= arr.length <= 10 ^ 5
//- 10 ^ 6 <= arr[i] <= 10 ^ 6


//希尔排序
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
	//排序
	ShellSort(arr, arrSize);
	//记录最小值
	int min = arr[1] - arr[0];
	//记录数组个数
	int count = 1;
	//申请返回数组空间
	int** ans = (int**)calloc(count, sizeof(int*));
	assert(ans);
	ans[0] = (int*)calloc(2, sizeof(int));
	assert(ans[0]);
	//记录初始数组元素
	ans[0][0] = arr[0];
	ans[0][1] = arr[1];
	//查找新元素
	for (int i = 2; i < arrSize; i++) {
		if (arr[i] - arr[i - 1] < min) {
			//记录最小值
			min = arr[i] - arr[i - 1];
			//删除记录元素
			while (count > 1) {
				free(ans[count - 1]);
				count -= 1;
			}
			//记录新元素
			ans[0][0] = arr[i - 1];
			ans[0][1] = arr[i];
		}
		else if (arr[i] - arr[i - 1] == min) {
			//数组元素加1
			count += 1;
			//给原空间扩容
			int** tmp = NULL;
			tmp = (int**)realloc(ans, count * sizeof(int*));
			assert(tmp);
			ans = tmp;
			ans[count - 1] = (int*)calloc(2, sizeof(int));
			assert(ans[count - 1]);
			//记录新元素
			ans[count - 1][0] = arr[i - 1];
			ans[count - 1][1] = arr[i];
		}
	}
	*returnSize = count;
	*returnColumnSizes = (int*)calloc(count, sizeof(int));
	assert(returnColumnSizes);
	for (int i = 0; i < count; i++) {
		(*returnColumnSizes)[i] = 2;
	}
	return ans;
}