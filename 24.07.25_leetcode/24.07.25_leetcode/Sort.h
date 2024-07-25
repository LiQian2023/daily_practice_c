#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <string.h>
//结构体
typedef struct Hash {
	int score;//得分
	int pi;//下标
}Hash;
void Swap_Hash(Hash* pa, Hash* pb);
void Adjust_Down_int(Hash* a, int len, int parent);
void HeapSort_int(Hash* a, int len);
void CreatHeap_int(Hash* a, int len);

//整型
typedef int ElemType;
void Swap(ElemType* pa, ElemType* pb);
//堆排序
void Adjust_Down(ElemType* a, int len, int parent);
void HeapSort(ElemType* a, int len);
void CreatHeap(ElemType* a, int len);
//快排——三点取中
void QuickSort(ElemType a[], int left, int right);
//希尔排序
void ShellSort(ElemType a[], int len);
//归并排序——递归实现
void MergeSort(ElemType a[], int left, int right, ElemType b[]);
//归并排序——非递归实现
void MergeSort_iterate(ElemType a[], int left, int right, ElemType b[]);
void test1();
void test2();
void test3();