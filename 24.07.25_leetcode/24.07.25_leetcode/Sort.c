#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"

//结构体
void Swap_Hash(Hash* pa, Hash* pb) {
	Hash tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void Adjust_Down_int(Hash* a, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && a[child].score > a[child + 1].score)
			child += 1;
		if (a[parent].score > a[child].score)
			Swap_Hash(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort_int(Hash* a, int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap_Hash(&a[i], &a[0]);
		Adjust_Down_int(a, i, 0);
	}
}
void CreatHeap_int(Hash* a, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down_int(a, len, i);
	}
}

//整型
void Swap(ElemType* pa, ElemType* pb) {
	ElemType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//堆排序
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
void HeapSort(ElemType* a, int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap(&a[i], &a[0]);
		Adjust_Down(a, i, 0);
	}
}
void CreatHeap(ElemType* a, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down(a, len, i);
	}
}

//快排——三点取中
int getKey(ElemType a[], int min, int mid, int max) {
	if (a[min] <= a[mid]) {
		if (a[mid] <= a[max])
			return mid;
		else {
			if (a[min] <= a[max])
				return max;
			return min;
		}
	}
	else {
		if (a[min] < a[max])
			return min;
		else {
			if (a[mid] < a[max])
				return max;
		}
	}
	return mid;

}
void QuickSort(ElemType a[], int left, int right) {
	if (left >= right)
		return;
	int mid = rand() % (right - left + 1) + left;
	int key = getKey(a, left, mid, right);
	Swap(&a[key], &a[left]);
	key = left;
	int begin = left, end = right;
	while (left < right) {
		while (left < right && a[right] >= a[key])
			right--;
		while (left < right && a[left] <= a[key])
			left++;
		if (left < right)
			Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	key = left;
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
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

//归并排序——递归实现
void MergeSort(ElemType a[], int left, int right, ElemType b[]) {
	if (left == right)
		return;
	//分区
	int key = (right - left) / 2 + left;//key——左侧分区大小
	MergeSort(a, left, key, b);
	MergeSort(a, key + 1, right, b);
	//归并
	int i = left, j = key + 1;//i指向左侧分区，j指向右侧分区
	int len = left;//归并分区起点
	while (i <= key && j <= right) {
		if (a[i] <= a[j])
			b[len++] = a[i++];
		else {
			b[len++] = a[j++];
		}
	}
	while (i <= key)b[len++] = a[i++];
	while (j <= right)b[len++] = a[j++];
	memcpy(a + left, b + left, (right - left + 1) * sizeof(int));
}

//归并排序——非递归实现
void MergeSort_iterate(ElemType a[], int left, int right, ElemType b[]) {
	for (int key = 1; key <= right; key *= 2) {
		int len = 0;
		int begin1 = 0, begin2 = begin1 + key;
		//归并
		for (; begin1 <= right && begin2 <= right; begin1 += 2 * key, begin2 += 2 * key) {
			int i = begin1, j = begin2;
			while (i <= right && j <= right && i < begin1 + key && j < begin2 + key) {
				if (a[i] <= a[j])
					b[len++] = a[i++];
				else
					b[len++] = a[j++];
			}
			while (i <= right && i < begin1 + key)b[len++] = a[i++];
			while (j <= right && j < begin2 + key)b[len++] = a[j++];
		}
		while (begin1 <= right)b[len++] = a[begin1++];
		//复制
		for (int z = 0; z <= right; z++)
			a[z] = b[z];
	}
}