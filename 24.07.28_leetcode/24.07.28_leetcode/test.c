#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void test() {
	srand(time(NULL));
	int N = 10;
	int* a1 = (int*)calloc(N, sizeof(int));
	assert(a1);

	for (int i = 0; i < N; i++) {
		a1[i] = rand() % 100;
	}

	printf("ÅÅÐòÇ°£º");
	Print_Int(a1, N);
	printf("ÅÅÐòºó£º");
	//InsertSort(a1, N);
	//ShellSort(a1, N);
	//BubbleSort(a1, N);
	//QuickSort(a1, 0, N - 1);
	//SelectSort(a1, N);
	//CreatHeap(a1, N);
	//HeapSort(a1, N);
	int* b = (int*)calloc(N, sizeof(int));
	assert(b);
	MergeSort2(a1, 0, N - 1, b);
	Print_Int(a1, N);

	free(a1);
	free(b);
}

int main() {
	test4();
	return 0;
}