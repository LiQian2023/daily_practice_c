#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.07.27力扣网刷题
//高度检查器——数组、计数排序、排序——简单
//学校打算为全体学生拍一张年度纪念照。根据要求，学生需要按照 非递减 的高度顺序排成一行。
//排序后的高度情况用整数数组 expected 表示，其中 expected[i] 是预计排在这一行中第 i 位的学生的高度（下标从 0 开始）。
//给你一个整数数组 heights ，表示 当前学生站位 的高度情况。heights[i] 是这一行中第 i 位学生的高度（下标从 0 开始）。
//返回满足 heights[i] != expected[i] 的 下标数量 。
//示例：
//输入：heights = [1, 1, 4, 2, 1, 3]
//输出：3
//解释：
//高度：[1, 1, 4, 2, 1, 3]
//预期：[1, 1, 1, 2, 3, 4]
//下标 2 、4 、5 处的学生高度不匹配。
//示例 2：
//输入：heights = [5, 1, 2, 3, 4]
//输出：5
//解释：
//高度：[5, 1, 2, 3, 4]
//预期：[1, 2, 3, 4, 5]
//所有下标的对应学生高度都不匹配。
//示例 3：
//输入：heights = [1, 2, 3, 4, 5]
//输出：0
//解释：
//高度：[1, 2, 3, 4, 5]
//预期：[1, 2, 3, 4, 5]
//所有下标的对应学生高度都匹配。
//提示：
//1 <= heights.length <= 100
//1 <= heights[i] <= 100

//计数排序
int heightChecker(int* heights, int heightsSize) {
	int* tmp = (int*)calloc(heightsSize, sizeof(int));
	assert(tmp);
	char nums[101] = { 0 };
	//计数
	for (int i = 0; i < heightsSize; i++)
		nums[heights[i]] += 1;
	int len = 0;
	//排序
	for (int i = 1; i < 101;i++) {
		while (nums[i]) {
			tmp[len++] = i;
			nums[i] -= 1;
		}
		if (len == heightsSize)
			break;
	}
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (tmp[i] != heights[i])
			ans += 1;
	}
	free(tmp);
	return ans;
}

//排序算法测试
void test() {
	srand(time(NULL));
	//申请内存
	int N = 10;
	int* a1 = (int*)calloc(N, sizeof(int));
	assert(a1);
	int* a2 = (int*)calloc(N, sizeof(int));
	assert(a2);
	int* a3 = (int*)calloc(N, sizeof(int));
	assert(a3);
	int* a4 = (int*)calloc(N, sizeof(int));
	assert(a4);
	int* a5 = (int*)calloc(N, sizeof(int));
	assert(a5);
	int* a6 = (int*)calloc(N, sizeof(int));
	assert(a6);
	int* a7 = (int*)calloc(N, sizeof(int));
	assert(a7);
	int* a8 = (int*)calloc(N, sizeof(int));
	assert(a8);
	int* a9 = (int*)calloc(N, sizeof(int));
	assert(a9);

	//获取数据
	for (int i = 0; i < N; i++) {
		a1[i] = rand() % 100;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
	}

	printf("    排序前：");
	Print_Int(a1, N);
	//插入排序测试
	//printf("插入排序前：");
	//Print_Int(a1, N);
	printf("插入排序后：");
	InsertSort(a1, N);
	Print_Int(a1, N);

	//插入排序——折半插入测试
	//printf("插入排序前：");
	//Print_Int(a2, N);
	printf("插入排序后：");
	InsertSort2(a2, N);
	Print_Int(a2, N);

	//希尔排序测试
	//printf("希尔排序前：");
	//Print_Int(a3, N);
	printf("希尔排序后：");
	ShellSort(a3, N);
	Print_Int(a3, N);

	//选择排序测试
	//printf("选择排序前：");
	//Print_Int(a4, N);
	printf("选择排序后：");
	SelectSort(a4, N);
	Print_Int(a4, N);

	//选择排序——双指针测试
	//printf("选择排序前：");
	//Print_Int(a5, N);
	printf("选择排序后：");
	SelectSort2(a5, N);
	Print_Int(a5, N);

	//堆排序
	//printf("  堆排序前：");
	//Print_Int(a6, N);
	CreatHeap(a6, N);
	printf("  堆排序后：");
	HeapSort(a6, N);
	Print_Int(a6, N);

	//冒泡排序
	//printf("冒泡排序前：");
	//Print_Int(a7, N);
	printf("冒泡排序后：");
	BubbleSort(a7, N);
	Print_Int(a7, N);

	//快速排序
	//printf("快速排序前：");
	//Print_Int(a8, N);
	printf("快速排序后：");
	QuickSort3(a8, 0, N - 1);
	Print_Int(a8, N);

	//归并排序
	//printf("归并排序前：");
	//Print_Int(a9, N);
	int* b = (int*)calloc(N, sizeof(int));
	assert(b);
	printf("归并排序后：");
	MergeSort2(a9, 0, N - 1, b);
	Print_Int(a9, N);

	//释放内存
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
	free(b);
}