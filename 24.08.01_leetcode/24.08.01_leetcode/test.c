#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//≈≈–ÚÀ„∑®≤‚ ‘
void test() {
	srand(time(NULL));
	int N = 10;
	int* a = (int*)calloc(N, sizeof(int));
	assert(a);
	for (int i = 0; i < N; i++)
		a[i] = rand() % 100;

	printf("≈≈–Ú«∞£∫");
	Print_int(a, N);
	//1≤Â»Î≈≈–Ú°™°™÷±Ω”≤Â»Î≈≈–Ú
	InsertSort(a, N);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//2≤Â»Î≈≈–Ú°™°™’€∞Î≤Â»Î≈≈–Ú
	Binary_InsertSort(a, N);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//3≤Â»Î≈≈–Ú°™°™œ£∂˚≈≈–Ú
	ShellSort(a, N);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//4—°‘Ò≈≈–Ú°™°™÷±Ω”—°‘Ò≈≈–Ú
	SelectSort(a, N);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//5—°‘Ò≈≈–Ú°™°™À´÷∏’Î—°‘Ò≈≈–Ú
	Double_SelectSort(a, N);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//6—°‘Ò≈≈–Ú°™°™∂—≈≈–Ú
	CreatHeap(a, N);
	HeapSort(a, N);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//7Ωªªª≈≈–Ú°™°™√∞≈›≈≈–Ú
	BubbleSort(a, N);;
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//8Ωªªª≈≈–Ú°™°™÷±Ω”øÏÀŸ≈≈–Ú
	QuickSort1(a, 0, N - 1);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//9Ωªªª≈≈–Ú°™°™ÀÊª˙ ˝øÏÀŸ≈≈–Ú
	QuickSort2(a, 0, N - 1);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//10Ωªªª≈≈–Ú°™°™»˝ ˝»°÷–øÏÀŸ≈≈–Ú
	QuickSort3(a, 0, N - 1);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//11Ωªªª≈≈–Ú°™°™–°«¯º‰”≈ªØøÏÀŸ≈≈–Ú
	QuickSort4(a, 0, N - 1);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//12πÈ≤¢≈≈–Ú°™°™µ›πÈπÈ≤¢≈≈–Ú
	int* b = (int*)calloc(N, sizeof(int));
	assert(b);
	MergeSort1(a, 0, N - 1, b);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	//13πÈ≤¢≈≈–Ú°™°™µ¸¥˙πÈ≤¢≈≈–Ú
	MergeSort2(a, 0, N - 1, b);
	printf("≈≈–Ú∫Û£∫");
	Print_int(a, N);
	free(a);
	free(b);
}

int main() {
	test7();
	return 0;
}