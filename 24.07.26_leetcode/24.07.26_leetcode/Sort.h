#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

typedef int ElemType;
void Swap(ElemType* pa, ElemType* pb);
void Print_int(ElemType a[], int len);

//²åÈëÅÅĞò
void InsertSort(ElemType a[], int len);
//Ï£¶ûÅÅĞò
void ShellSort(ElemType a[], int len);
//Ñ¡ÔñÅÅĞò
void SelectSort(ElemType a[], int len);
//¶ÑÅÅĞò
void Adjust_Down(ElemType a[], int len, int parent);
void CreatHeap(ElemType a[], int len);
void HeapSort(ElemType a[], int len);
//½»»»ÅÅĞò¡ª¡ªÃ°ÅİÅÅĞò
void BubbleSort(ElemType a[], int len);
//¿ìËÙÅÅĞò
int getKey(ElemType a[], int min, int max);
void QuickSort(ElemType a[], int left, int right);
//¹é²¢ÅÅĞò_µİ¹éÊµÏÖ
void MergeSort(ElemType a[], int left, int right, ElemType b[]);
//¹é²¢ÅÅĞò¡ª¡ª·Çµİ¹éÊµÏÖ
void MergeSort_Iterate(ElemType a[], int left, int right, ElemType b[]);

//ÅÅĞòËã·¨²âÊÔ
void test();
//ÌâÄ¿1²âÊÔ
void test1();
//ÌâÄ¿6²âÊÔ
void test6();