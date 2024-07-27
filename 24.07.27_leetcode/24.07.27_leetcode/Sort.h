#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

//2024.07.27力扣网刷题

typedef int ElemType;
void Swap(ElemType* pa, ElemType* pb);
void Print_Int(ElemType* a, int len);

//插入排序
void InsertSort(ElemType* a, int len);
void InsertSort2(ElemType* a, int len);
//希尔排序
void ShellSort(ElemType* a, int len);
//选择排序
void SelectSort(ElemType* a, int len);
//选择排序——双指针
void SelectSort2(ElemType* a, int len);
//堆排序
void HeapSort(ElemType* a, int len);
//冒泡排序
void BubbleSort(ElemType* a, int len);
//快排——Horea版本
void QuickSort(ElemType* a, int left, int right);
//快排——挖坑法
void QuickSort2(ElemType* a, int left, int right);
//快排——前后指针法
void QuickSort3(ElemType* a, int left, int right);
//归并排序
void MergeSort(ElemType* a, int left, int right, ElemType* b);
//归并排序
void MergeSort2(ElemType* a, int left, int right, ElemType* b);

//测试
void test();