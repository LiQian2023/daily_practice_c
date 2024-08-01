#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>

//2024.08.01力扣网刷题
//力扣网排序习题

typedef int ElemType;
void Swap(ElemType* p1, ElemType* p2);
void Print_int(ElemType* a, int len);

//插入排序——直接插入排序
void InsertSort(ElemType* a, int len);
//插入排序——折半插入排序
void Binary_InsertSort(ElemType* a, int len);
//插入排序——希尔排序
void ShellSort(ElemType* a, int len);
//选择排序——直接选择排序
void SelectSort(ElemType* a, int len);
//选择排序——双指针选择排序
void Double_SelectSort(ElemType* a, int len);
//选择排序——堆排序
void HeapSort(ElemType* a, int len);
void CreatHeap(ElemType* a, int len);
void Adjust_Down(ElemType* a, int len, int parent);
//交换排序——冒泡排序
void BubbleSort(ElemType* a, int len);
//交换排序——直接快速排序
void QuickSort1(ElemType* a, int left, int right);
//交换排序——随机数快速排序
void QuickSort2(ElemType* a, int left, int right);
//交换排序——三数取中快速排序
void QuickSort3(ElemType* a, int left, int right);
//交换排序——小区间优化快速排序
void QuickSort4(ElemType* a, int left, int right);
//归并排序——递归归并排序
void MergeSort1(ElemType* a, int left, int right, ElemType* b);
//归并排序——迭代归并排序
void MergeSort2(ElemType* a, int left, int right, ElemType* b);

//题目1测试
void test1();
//题目4测试
void test4();
//题目6测试
void test6();
//题目7测试
void test7();