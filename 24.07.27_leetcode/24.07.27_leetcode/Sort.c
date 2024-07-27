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

//插入排序
void InsertSort(ElemType* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		ElemType key = a[i + 1];
		int j = i;
		for (j; j >= 0 && a[j] > key; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

//折半插入
int Binary_Search(ElemType* a, int left, int right,ElemType key) {
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (a[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return right + 1;
}
void Move(ElemType* a, int begin, int end) {
	for (int i = end; i >= begin && begin >= 0; i--) {
		a[i + 1] = a[i];
	}
}
void InsertSort2(ElemType* a, int len) {
	for (int begin = 0; begin < len - 1; begin++) {
		int key = a[begin + 1];
		//二分查找
		int move = Binary_Search(a, 0, begin, key);
		//移动
		Move(a, move, begin);
		a[move] = key;
	}
}

//希尔排序
void ShellSort(ElemType* a, int len) {
	for (int gap = len / 2; gap && gap < len; gap /= 2) {
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
void SelectSort(ElemType* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (a[j] < a[i])
				Swap(&a[j], &a[i]);
		}
	}
}

//选择排序——双指针
void SelectSort2(ElemType* a, int len) {
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		for (int z = i; z < j; z++) {
			if (a[z] < a[i])
				Swap(&a[z], &a[i]);
			if (a[z] > a[j])
				Swap(&a[z], &a[j]);
		}
	}
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
	for (int i = len - 1; i; i--) {
		Swap(&a[0], &a[i]);
		Adjust_Down(a, i, 0);
	}
}

void CreatHeap(ElemType* a, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down(a, len, i);
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

//快排——Horea版本
int Partition(ElemType* a, int left, int right) {
	if (left >= right)
		return left;
	int key = left;
	while (left < right) {
		while (left < right && a[right] > a[key]) 
			right -= 1;
		while (left < right && a[left] < a[key])
			left += 1;
		if (left < right)
			Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return left;
}

//快排——挖坑法
int Partition2(ElemType* a, int left, int right) {
	if (left >= right)
		return left;
	int key = a[left];
	while (left < right) {
		while (left < right && a[right] > key) {
			right -= 1;
		}
		a[left] = a[right];
		while (left < right && a[left] < key)
			left += 1;
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

//快排——前后指针法
int Partition3(ElemType* a, int left, int right) {
	if (left >= right)
		return left;
	int key = left;
	int cur = left, ptr = left;
	while (cur <= right) {
		if (a[cur] < a[key] && ++ptr != cur)
			Swap(&a[ptr], &a[cur]);
		cur += 1;
	}
	Swap(&a[key], &a[ptr]);
	return ptr;
}

void QuickSort(ElemType* a, int left,int right) {
	if (left >= right)
		return;
	int key = Partition(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

void QuickSort2(ElemType* a, int left, int right) {
	if (left >= right)
		return;
	int key = Partition2(a, left, right);
	QuickSort2(a, left, key - 1);
	QuickSort2(a, key + 1, right);
}

void QuickSort3(ElemType* a, int left, int right) {
	if (left >= right)
		return;
	int key = Partition3(a, left, right);
	QuickSort3(a, left, key - 1);
	QuickSort3(a, key + 1, right);
}

//归并排序
void MergeSort(ElemType* a, int left, int right, ElemType* b) {
	if (left == right)
		return;
	//分区
	int key = (right - left) / 2 + left;
	MergeSort(a, left, key, b);
	MergeSort(a, key + 1, right, b);
	//一趟归并
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

//归并排序——非递归实现
void MergeSort2(ElemType* a, int left, int right, ElemType* b) {
	for (int key = 1; key <= right; key *= 2) {
		int len = 0;
		int begin1 = 0, begin2 = key;
		//合并
		for (begin1, begin2; begin1 <= right && begin2 <= right; begin1 += 2 * key, begin2 += 2 * key) {
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
		for (int i = 0; i < len; i++)
			a[i] = b[i];
	}
}