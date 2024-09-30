#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

int N = 10;
//插入排序测试
void test_Insert() {
	//测试数组
	int* a1 = (int*)calloc(N, sizeof(int));
	assert(a1);
	int* a2 = (int*)calloc(N, sizeof(int));
	assert(a2);
	//取值
	for (int i = 0; i < N; i++) {
		a1[i] = rand() % N;
		a2[i] = a1[i];
	}
	printf("a1 = ");
	Print(a1, N);
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	printf("a1 = ");
	Print(a1, N);
	printf("InsertSort = %d\n\n", end1 - begin1);
	printf("a2 = ");
	Print(a2, N);
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	printf("a2 = ");
	Print(a2, N);
	printf("ShellSort = %d\n\n", end2 - begin2);
	free(a1);
	free(a2);
	a1 = NULL;
	a2 = NULL;
}

//选择排序测试
void test_Select() {
	//测试数组
	int* a1 = (int*)calloc(N, sizeof(int));
	assert(a1);
	int* a2 = (int*)calloc(N, sizeof(int));
	assert(a2);
	//取值
	for (int i = 0; i < N; i++) {
		a1[i] = rand() % N;
		a2[i] = a1[i];
	}
	printf("a1 = ");
	Print(a1, N);
	int begin1 = clock();
	SelectSort1(a1, N);
	int end1 = clock();
	printf("a1 = ");
	Print(a1, N);
	printf("SelectSort1 = %d\n\n", end1 - begin1);
	printf("a2 = ");
	Print(a2, N);
	int begin2 = clock();
	HeapSort(a2, N);
	int end2 = clock();
	printf("a2 = ");
	Print(a2, N);
	printf("HeapSort = %d\n\n", end2 - begin2);
	free(a1);
	free(a2);
	a1 = NULL;
	a2 = NULL;
}

//交换排序测试
void test_Change() {
	//测试数组
	int* a1 = (int*)calloc(N, sizeof(int));
	assert(a1);
	int* a2 = (int*)calloc(N, sizeof(int));
	assert(a2);
	//取值
	for (int i = 0; i < N; i++) {
		a1[i] = rand() % N;
		a2[i] = a1[i];
	}
	printf("a1 = ");
	Print(a1, N);
	int begin1 = clock();
	BubbleSort(a1, N);
	int end1 = clock();
	printf("a1 = ");
	Print(a1, N);
	printf("BubbleSort = %d\n\n", end1 - begin1);
	printf("a2 = ");
	Print(a2, N);
	int begin2 = clock();
	QuickSort1(a2, 0, N - 1);
	int end2 = clock();
	printf("a2 = ");
	Print(a2, N);
	printf("QuickSort1 = %d\n\n", end2 - begin2);
	free(a1);
	free(a2);
	a1 = NULL;
	a2 = NULL;
}

//归并排序测试
void test_Merge() {

}

//其它排序测试
void test_Others() {
	//测试数组
	int* a1 = (int*)calloc(N, sizeof(int));
	assert(a1);
	int* a2 = (int*)calloc(N, sizeof(int));
	assert(a2);
	//取值
	for (int i = 0; i < N; i++) {
		a1[i] = rand() % N;
		a2[i] = a1[i];
	}
	printf("a1 = ");
	Print(a1, N);
	int begin1 = clock();
	CountSort(a1, N);
	int end1 = clock();
	printf("a1 = ");
	Print(a1, N);
	printf("CountSort = %d\n\n", end1 - begin1);
	printf("a2 = ");
	Print(a2, N);
	int begin2 = clock();
	BucketSort(a2, N);
	int end2 = clock();
	printf("a2 = ");
	Print(a2, N);
	printf("BucketSort = %d\n\n", end2 - begin2);
	free(a1);
	free(a2);
	a1 = NULL;
	a2 = NULL;
}

int main() {
	//srand((unsigned int)time(NULL));
	//test_Insert();
	//test_Select();
	//test_Change();
	//test_Merge();
	//test_Others();
	test();
	return 0;
}