#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.08.01力扣网刷题

void Swap(ElemType* p1, ElemType* p2) {
	ElemType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void Print_int(ElemType* a, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");
}

//插入排序——直接插入排序
void InsertSort(ElemType* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		ElemType key = a[i + 1];
		int j = i;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j -= 1;
		}
		a[j + 1] = key;
	}
}
//插入排序——折半插入排序
int BinarySearch(ElemType* a, int left, int right, ElemType key) {
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (a[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
void Move(ElemType* a, int begin, int end) {
	for (int i = end; begin <= end && i >= begin; i--) {
		a[i + 1] = a[i];
	}
}
void Binary_InsertSort(ElemType* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		ElemType key = a[i + 1];
		int move = BinarySearch(a, 0, i, key);
		Move(a, move, i);
		a[move] = key;
	}
}
//插入排序——希尔排序
void ShellSort(ElemType* a, int len) {
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
//选择排序——直接选择排序
void SelectSort(ElemType* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (a[j] < a[i]) {
				Swap(&a[j], &a[i]);
			}
		}
	}
}
//选择排序——双指针选择排序
void Double_SelectSort(ElemType* a, int len) {
	for (int min = 0, max = len - 1; min < max; min++, max--) {
		for (int i = min; i < max; i++) {
			if (a[i] < a[min]) {
				Swap(&a[i], &a[min]);
			}
			if (a[i] > a[max]) {
				Swap(&a[i], &a[max]);
			}
		}
	}
}
//选择排序——堆排序
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
//交换排序——冒泡排序
void BubbleSort(ElemType* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		int flag = 1;
		for (int j = 0; j < len - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}
//交换排序——直接快速排序
void QuickSort1(ElemType* a, int begin, int end) {
	if (begin >= end)
		return;
	int key = begin;
	//Horea法实现
	int left = begin, right = end;
	while (left < right) {
		while (left < right && a[right] >= a[key]) {
			right -= 1;
		}
		while (left < right && a[left] <= a[key]) {
			left += 1;
		}
		if (left < right)
			Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key]);
	key = left;
	QuickSort1(a, begin, key - 1);
	QuickSort1(a, key + 1, end);
}
//交换排序——随机数快速排序
void QuickSort2(ElemType* a, int begin, int end) {
	if (begin >= end)
		return;
	int pi = rand() % (end - begin) + begin;
	Swap(&a[begin], &a[pi]);
	//挖坑法实现
	ElemType key = a[begin];
	int left = begin, right = end;
	while (left < right) {
		while (left < right && a[right] >= key)
			right -= 1;
		a[left] = a[right];
		while (left < right && a[left] <= key)
			left += 1;
		a[right] = a[left];
	}
	a[left] = key;
	pi = left;
	QuickSort2(a, begin, pi - 1);
	QuickSort2(a, pi + 1, end);
}
//交换排序——三数取中快速排序
int getMid(ElemType* a, int min, int max) {
	int mid = rand() % (max - min + 1) + min;
	if (a[max] > a[mid]) {
		if (a[mid] > a[min])
			return mid;
		else {
			if (a[max] > a[min])
				return min;
			return max;
		}
	}
	else {
		if (a[max] > a[min])
			return max;
		else {
			if (a[mid] > a[min])
				return min;
			return mid;
		}
	}
}
void QuickSort3(ElemType* a, int left, int right) {
	if (left >= right)
		return;
	int key = getMid(a, left, right);
	Swap(&a[left], &a[key]);
	key = left;
	//前后指针法实现
	int ptr = left, cur = left;
	while (cur <= right) {
		if (a[cur] < a[key] && ++ptr != cur)
			Swap(&a[cur], &a[ptr]);
		cur += 1;
	}
	Swap(&a[key], &a[ptr]);
	key = ptr;
	QuickSort3(a, left, key - 1);
	QuickSort3(a, key + 1, right);
}
//交换排序——小区间优化快速排序
void QuickSort4(ElemType* a, int left, int right) {
	if (right - left + 1 <= 5) {
		InsertSort(a + left, right - left + 1);
		return;
	}
	int key = getMid(a, left, right);
	Swap(&a[left], &a[key]);
	key = left;
	//前后指针法实现
	int ptr = left, cur = left;
	while (cur <= right) {
		if (a[cur] < a[key] && ++ptr != cur)
			Swap(&a[cur], &a[ptr]);
		cur += 1;
	}
	Swap(&a[key], &a[ptr]);
	key = ptr;
	QuickSort4(a, left, key - 1);
	QuickSort4(a, key + 1, right);
}
//归并排序——递归归并排序
void MergeSort1(ElemType* a, int left, int right, ElemType* b) {
	if (left == right)
		return;
	//分区
	int key = (right - left) / 2 + left;
	MergeSort1(a, left, key, b);
	MergeSort1(a, key + 1, right, b);
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
	//复制
	memcpy(a + left, b + left, (right - left + 1) * sizeof(ElemType));
}
//归并排序——迭代归并排序
void MergeSort2(ElemType* a, int left, int right, ElemType* b) {
	for (int key = 1; key < right; key *= 2) {
		int len = 0;
		int begin1 = 0, begin2 = key;
		for (; begin1 <= right && begin2 <= right; begin1 += 2 * key, begin2 += 2 * key) {
			int i = begin1, j = begin2;
			while (i<= right && j <= right && i < begin1 + key && j <begin2 + key) {
				if (a[i] <= a[j])
					b[len++] = a[i++];
				else
					b[len++] = a[j++];
			}
			while (i <= right && i < begin1 + key)b[len++] = a[i++];
			while (j <= right && j < begin2 + key)b[len++] = a[j++];
		}
		while (begin1 <= right)b[len++] = a[begin1++];
		for (int i = 0; i <= right; i++)
			a[i] = b[i];
	}
}