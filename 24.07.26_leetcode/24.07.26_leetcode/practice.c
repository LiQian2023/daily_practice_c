#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.07.26力扣网刷题
//公平的糖果交换——数组、哈希表、二分查找、排序——简单
//爱丽丝和鲍勃拥有不同总数量的糖果。给你两个数组 aliceSizes 和 bobSizes ，
//aliceSizes[i] 是爱丽丝拥有的第 i 盒糖果中的糖果数量，bobSizes[j] 是鲍勃拥有的第 j 盒糖果中的糖果数量。
//两人想要互相交换一盒糖果，这样在交换之后，他们就可以拥有相同总数量的糖果。一个人拥有的糖果总数量是他们每盒糖果数量的总和。
//返回一个整数数组 answer，其中 answer[0] 是爱丽丝必须交换的糖果盒中的糖果的数目，answer[1] 是鲍勃必须交换的糖果盒中的糖果的数目。
//如果存在多个答案，你可以返回其中 任何一个 。题目测试用例保证存在与输入对应的答案。
//示例 1：
//输入：aliceSizes = [1, 1], bobSizes = [2, 2]
//输出：[1, 2]
//示例 2：
//输入：aliceSizes = [1, 2], bobSizes = [2, 3]
//输出：[1, 2]
//示例 3：
//输入：aliceSizes = [2], bobSizes = [1, 3]
//输出：[2, 3]
//示例 4：
//输入：aliceSizes = [1, 2, 5], bobSizes = [2, 4]
//输出：[5, 4]
//提示：
//1 <= aliceSizes.length, bobSizes.length <= 10^4
//1 <= aliceSizes[i], bobSizes[j] <= 10^5
//爱丽丝和鲍勃的糖果总数量不同。
//题目数据保证对于给定的输入至少存在一个有效答案。

bool Search(ElemType a[], int len, int x) {
	int l = 0, r = len - 1;
	while (l <= r) {
		int mid = (r - l) / 2 + l;
		if (a[mid] > x) {
			r = mid - 1;
		}
		else if (a[mid] < x) {
			l = mid + 1;
		}
		else
			return true;
	}
	return false;
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
	*returnSize = 2;
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	//排序
	ShellSort(aliceSizes, aliceSizesSize);
	ShellSort(bobSizes, bobSizesSize);
	//计算差值
	long long sum1 = 0, sum2 = 0;
	for (int i = 0; i < aliceSizesSize; i++) {
		sum1 += aliceSizes[i];
	}
	for (int i = 0; i < bobSizesSize; i++) {
		sum2 += bobSizes[i];
	}
	int x = abs(sum1 - sum2) / 2;
	int taget1 = 1;
	int taget2 = taget1 + x;
	//通过flag1与flag2来判断是否找到目标值
	bool flag1 = false, flag2 = false;
	//查找
	if (sum1 > sum2) {
		//alice 交换的糖果数要多
		taget2 = 0, taget1 = taget2 + x;
		while (!flag1 || !flag2) {
			taget2 += 1;
			taget1 = taget2 + x;
			flag1 = Search(aliceSizes, aliceSizesSize, taget1);
			flag2 = Search(bobSizes, bobSizesSize, taget2);
		}
	}
	else {
		//alice 交换的糖果数要少
		taget1 = 0, taget2 = x + taget1;
		while (!flag1 || !flag2) {
			taget1 += 1;
			taget2 = taget1 + x;
			flag1 = Search(aliceSizes, aliceSizesSize, taget1);
			flag2 = Search(bobSizes, bobSizesSize, taget2);
		}
	}
	ans[0] = taget1, ans[1] = taget2;
	return ans;
}

void test1() {
	int a[10] = { 20,35,22,6,13 };
	int b[10] = { 31,57 };
	int size = 0;
	int* ret = fairCandySwap(a, 5, b, 2, &size);
	Print_int(ret, size);
	free(ret);
}

//排序算法测试
void test() {
	srand(time(NULL));
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

	for (int i = 0; i < N; i++) {
		a1[i] = rand() % N;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}

	printf("插入排序前：");
	Print_int(a1, N);
	printf("插入排序后：");
	InsertSort(a1, N);
	Print_int(a1, N);

	printf("希尔排序前：");
	Print_int(a2, N);
	printf("希尔排序后：");
	ShellSort(a2, N);
	Print_int(a2, N);

	printf("选择排序前：");
	Print_int(a3, N);
	printf("选择排序后：");
	SelectSort(a3, N);
	Print_int(a3, N);

	printf("  堆排序前：");
	Print_int(a4, N);
	printf("  堆排序后：");
	CreatHeap(a4, N);
	HeapSort(a4, N);
	Print_int(a4, N);

	printf("冒泡排序前：");
	Print_int(a5, N);
	printf("冒泡排序后：");
	BubbleSort(a5, N);
	Print_int(a5, N);

	printf("快速排序前：");
	Print_int(a6, N);
	printf("快速排序后：");
	QuickSort(a6, 0, N);
	Print_int(a6, N);

	printf("归并排序前：");
	Print_int(a7, N);
	printf("归并排序后：");
	ElemType* b = (ElemType*)calloc(N, sizeof(int));
	assert(b);
	MergeSort(a7, 0, N - 1, b);
	Print_int(a7, N);

	printf("归并排序前：");
	Print_int(a8, N);
	printf("归并排序后：");
	MergeSort_Iterate(a8, 0, N - 1, b);
	Print_int(a8, N);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(b);

}
