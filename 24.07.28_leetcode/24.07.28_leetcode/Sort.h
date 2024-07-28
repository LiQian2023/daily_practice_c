#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

//2024.07.28力扣网刷题

typedef int ElemType;
void Swap(ElemType* pa, ElemType* pb);
void Print_Int(ElemType* a, int len);
//插入排序——折半插入
void InsertSort(ElemType a[], int len);
//插入排序——希尔排序
void ShellSort(ElemType* a, int len);
//交换排序——冒泡排序
void BubbleSort(ElemType* a, int len);
//交换排序——快速排序（三数取中+前后指针）
void QuickSort(ElemType* a, int begin, int end);
//选择排序——双指针
void SelectSort(ElemType* a, int len);
//选择排序——堆排序
void CreatHeap(ElemType* a, int len);
void HeapSort(ElemType* a, int len);
//归并排序——递归实现
void MergeSort(ElemType* a, int left, int right, ElemType* b);
//归并排序——非递归实现
void MergeSort2(ElemType* a, int left, int right, ElemType* b);

//题目测试
void test3();
void test4();