#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

//排序头文件
//打印数组
void Print(int* a, int len);
//两数交换
void Swap(int* a, int* b);
//插入排序
void InsertSort(int* a, int len);
//希尔排序
void ShellSort(int* a, int len);
//选择排序
void SelectSort(int* a, int len);
//向下调整
void Adjust_Down(int* a, int len, int parent);
//建堆
void CreateHeap(int* a, int len);
//堆排序
void HeapSort(int* a, int len);
//交换排序——冒泡排序
void BubbleSort(int* a, int len);
//快速排序
void QuickSort1(int* a, int left, int right);
//快速排序
void QuickSort2(int* a, int left, int right);
//快速排序
void QuickSort3(int* a, int left, int right);
//归并排序
void MergeSort(int* a, int len);
//计数排序
void CountSort(int* a, int len);
//桶排序
void BucketSort(int* a, int len);

void test();