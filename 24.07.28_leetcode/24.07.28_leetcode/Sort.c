#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"


void Swap(ElemType* pa, ElemType* pb) {
	ElemType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void Print_Int(ElemType* a, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");
}

//插入排序——折半插入
int Binary_Search(ElemType* a, int left, int right, ElemType key) {
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (a[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}
void Move(ElemType* a, int begin, int end) {
	for (int i = end; i >= begin; i--) {
		a[i + 1] = a[i];
	}
}
void InsertSort(ElemType a[], int len) {
	for (int i = 0; i < len - 1; i++) {
		ElemType key = a[i + 1];
		int move = Binary_Search(a, 0, i, key);
		Move(a, move, i);
		a[move] = key;
	}
}

//插入排序——希尔排序
void ShellSort(ElemType* a, int len) {
	for (int gap = len / 2; gap; gap /= 2) {
		for (int i = 0; i < len - gap; i++) {
			int key = a[i + gap];
			int j = i;
			while (j >= 0 && a[j] > key) {
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = key;
		}
	}
}

//交换排序——冒泡排序
void BubbleSort(ElemType* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
	}
}

//交换排序——快速排序（三数取中+前后指针）
int GetMid(ElemType* a, int begin, int end) {
	int mid = rand() % (end - begin) / 2 + begin;
	if (a[end] >= a[mid]) {
		if (a[mid] >= a[begin])
			return mid;
		else {
			if (a[end] >= a[begin])
				return begin;
			return end;
		}
	}
	else {
		if (a[end] >= a[begin])
			return end;
		else {
			if (a[mid] >= a[begin])
				return begin;
			return mid;
		}
	}
}
int Partition(ElemType* a, int begin, int end) {
	//三数取中
	int key = GetMid(a, begin, end);
	Swap(&a[key], &a[begin]);
	key = begin;
	//前后指针
	int fast = key, slow = key;
	while (fast <= end) {
		if (a[fast] < a[key] && ++slow != fast)
			Swap(&a[slow], &a[fast]);
		fast++;
	}
	Swap(&a[key], &a[slow]);
	return slow;
}
void QuickSort(ElemType* a, int begin, int end) {
	if (begin >= end)
		return;
	int key = Partition(a, begin, end);
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}

//选择排序——双指针
void SelectSort(ElemType* a, int len) {
	for (int min = 0, max = len - 1; min < max; min++, max--) {
		for (int i = min; i < max; i++) {
			if (a[min] > a[i])
				Swap(&a[min], &a[i]);
			if (a[max] < a[i])
				Swap(&a[max], &a[i]);
		}
	}
}

//选择排序——堆排序
void Adjust_Down(ElemType* a, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && a[child] < a[child + 1])
			child += 1;
		if (a[parent] < a[child])
			Swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void CreatHeap(ElemType* a, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down(a, len, i);
	}
}
void HeapSort(ElemType* a, int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap(&a[0], &a[i]);
		Adjust_Down(a, i, 0);
	}
}

//归并排序——递归实现
void MergeSort(ElemType* a, int left, int right, ElemType* b) {
	if (left == right)
		return;
	//分区
	int key = (right - left) / 2 + left;// 分区大小
	MergeSort(a, left, key, b);
	MergeSort(a, key + 1, right, b);
	//归并
	int len = left;
	int begin1 = left, begin2 = key + 1;
	while (begin1 <= key && begin2 <= right) {
		if (a[begin1] <= a[begin2])
			b[len++] = a[begin1++];
		else
			b[len++] = a[begin2++];
	}
	while (begin1 <= key)b[len++] = a[begin1++];
	while (begin2 <= right)b[len++] = a[begin2++];
	memcpy(a + left, b + left, (right - left + 1) * sizeof(int));
}

//归并排序——非递归实现
void MergeSort2(ElemType* a, int left, int right, ElemType* b) {
	for (int key = 1; key < right; key *= 2) {
		int len = 0;
		int begin1 = 0, begin2 = key;
		while (begin1 <= right && begin2 <= right) {
			int i = begin1, j = begin2;
			while (i <= right && j <= right && i < begin1 + key && j < begin2 + key) {
				if (a[i] <= a[j])
					b[len++] = a[i++];
				else
					b[len++] = a[j++];
			}
			while (i <= right && i < begin1 + key)b[len++] = a[i++];
			while (j <= right && j < begin2 + key)b[len++] = a[j++];
			begin1 += 2 * key, begin2 += 2 * key;
		}
		while (begin1 <= right)b[len++] = a[begin1++];

		//复制
		for (int i = 0; i < len; i++)
			a[i] = b[i];
	}
}