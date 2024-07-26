#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void Swap(ElemType* pa, ElemType* pb) {
	ElemType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void Print_int(ElemType a[], int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

//插入排序
void InsertSort(ElemType a[], int len) {
	for (int i = 0; i < len - 1; i++) {
		int j = i;
		ElemType key = a[j + 1];
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j -= 1;
		}
		a[j + 1] = key;
	}
}

//希尔排序
void ShellSort(ElemType a[], int len) {
	for (int gap = len / 2; gap; gap /= 2) {
		for (int i = 0; i < len - gap; i++) {
			ElemType key = a[i + gap];
			int j = i;
			while (j >= 0 && a[j] > key) {
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = key;
		}
	}
}

//选择排序
void SelectSort(ElemType a[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (a[j] < a[i])
				Swap(&a[j], &a[i]);
		}
	}
}

//堆排序
void Adjust_Down(ElemType a[], int len, int parent) {
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

void CreatHeap(ElemType a[], int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down(a, len, i);
	}
}

void HeapSort(ElemType a[], int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap(&a[i], &a[0]);
		Adjust_Down(a, i, 0);
	}
}

//交换排序——冒泡排序
void BubbleSort(ElemType a[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
	}
}

//快速排序
int getKey(ElemType a[], int min, int max) {
	int mid = rand() % (max - min) + min;
	if (max >= mid) {
		if (mid >= min)
			return mid;
		else {
			if (max >= min)
				return min;
			return max;
		}
	}
	else {
		if (max >= min)
			return max;
		else {
			if (mid >= min)
				return min;
			return mid;
		}
	}
}
void QuickSort(ElemType a[], int left, int right) {
	if (left >= right)
		return;
	//三数取中
	int key = getKey(a, left, right);
	Swap(&a[key], &a[left]);
	key = left;
	int begin = left, end = right;
	//快慢指针
	int fast = left, slow = left;
	while (fast < right) {
		if (a[fast] < a[key] && ++slow != fast)
			Swap(&a[fast], &a[slow]);
		fast++;
	}
	Swap(&a[key], &a[slow]);
	key = slow;
	QuickSort(a, left, key);
	QuickSort(a, key + 1, right);
}

//归并排序_递归实现
void MergeSort(ElemType a[], int left, int right, ElemType b[]) {
	if (left == right)
		return;
	//分区
	int key = (right - left) / 2 + left;
	MergeSort(a, left, key, b);
	MergeSort(a, key + 1, right, b);
	//归并
	int len = left;
	int i = left, j = key + 1;
	while (i <= key && j <= right) {
		if (a[i] <= a[j])
			b[len++] = a[i++];
		else
			b[len++] = a[j++];
	}
	while (i <= key)b[len++] = a[i++];
	while (j <= right)b[len++] = a[j++];
	memcpy(a + left, b + left, (right - left + 1) * sizeof(ElemType));
}

//归并排序——
void MergeSort_Iterate(ElemType a[], int left, int right, ElemType b[]) {
	for (int key = 1; key < right; key *= 2) {
		//归并
		int len = 0;
		int begin1 = 0, begin2 = key;
		while (begin1 <= right && begin2 <= right) {
			int i = begin1, j = begin2;
			while (i < begin1 + key && j < begin2 + key) {
				if (a[i] <= a[j])
					b[len++] = a[i++];
				else
					b[len++] = a[j++];
			}
			while (i < begin1 + key)b[len++] = a[i++];
			while (j < begin2 + key)b[len++] = a[j++];
			begin1 += 2 * key, begin2 += 2 * key;
		}
		while (begin1 <= right)b[len++] = a[begin1++];
		//复制
		for (int i = 0; i <= right; i++) {
			a[i] = b[i];
		}
	}
}