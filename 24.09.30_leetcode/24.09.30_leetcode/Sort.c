#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//打印数组
void Print(int* a, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

//插入排序
void InsertSort(int* a, int len) {
	for (int i = 0; i < len - 1; i++) {
		int key = a[i + 1];//取出待插入对象
		int j = i;//左侧有序插入起点
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];//元素右移
			j -= 1;//指针左移
		}
		a[j + 1] = key;//插入元素
	}
}
//希尔排序
void ShellSort(int* a, int len) {
	for (int gap = len / 2; gap; gap /= 2) {
		for (int i = 0; i < len - gap; i++) {
			int key = a[i + gap];//取出待插入元素
			int j = i;//左侧有序插入起点
			while (j >= 0 && a[j] > key) {
				a[j + gap] = a[j];//元素右移
				j -= gap;//指针左移
			}
			a[j + gap] = key;//插入元素
		}
	}
}
//两数交换
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//选择排序
void SelectSort1(int* a, int len) {
	//升序排序，左侧为最小值
	for (int min = 0; min < len; min++) {
		//从排序对象右侧寻找更小值
		for (int i = min + 1; i < len; i++) {
			//找到更小值
			if (a[i] < a[min]) {
				Swap(&a[i], &a[min]);//两数交换
			}
		}
	}
}
//选择排序——优化1：双指针
void SelectSort2(int* a, int len) {
	//双指针优化——升序排序，最左侧为最小值，最右侧为最大值
	for (int min = 0, max = len - 1; min < max; min++, max--) {
		//以最小值为起点开始遍历排序数组
		for (int i = min; i <= max; i++) {
			//找到更小值
			if (a[i] < a[min]) {
				Swap(&a[i], &a[min]);//两数交换
			}
			//找到更大值
			if (a[i] > a[max]) {
				Swap(&a[i], &a[max]);//两数交换
			}
		}
	}
}
//向下调整
void Adjust_Down(int* a, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		//升序建大堆——右兄弟大于左兄弟
		if (child + 1 < len && a[child] < a[child + 1])
			child += 1;//指针指向右兄弟
		//孩子大于父结点
		if (a[parent] < a[child])
			Swap(&a[parent], &a[child]);//父子交换
		//向下遍历
		parent = child;
		child = parent * 2 + 1;
	}
}
//建堆
void CreateHeap(int* a, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		//向下调整
		Adjust_Down(a, len, i);
	}
}
//堆排序
void HeapSort(int* a, int len) {
	//建堆
	CreateHeap(a, len);
	//排序
	for (int i = len - 1; i > 0; i--) {
		Swap(&a[i], &a[0]);
		Adjust_Down(a, i, 0);
	}
}
//交换排序——冒泡排序
void BubbleSort(int* a, int len) {
	//排序总次数
	for (int i = 0; i < len - 1; i++) {
		//一次排序中的交换次数
		for (int j = 0; j < len - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

//Hoare版本
int Partition1(int* a, int left, int right) {
	while (left < right) {
		//关键字位于左侧，从右侧开始遍历
		while (right > left && a[right] >= a[left])
			right -= 1;//右侧元素大于等于关键字，则移动右侧指针
		//左右指针不相等且右侧元素小于关键字
		if (left != right)
			Swap(&a[right], &a[left]);//交换左右元素
		//完成交换后，此时关键字位于右侧，从左侧开始遍历
		while (left < right && a[left] <= a[right])
			left += 1;//左侧元素小于等于关键字，则移动左侧指针
		//左右指针不相等且左侧元素大于关键字
		if (left != right)
			Swap(&a[right], &a[left]);//交换左右元素
	}
	return left;
}
//挖坑法
int Partition2(int* a, int left, int right) {
	//挖坑
	int key = a[left];
	while (left < right) {
		//坑在左侧，从右侧开始遍历
		while (right > left && a[right] >= key)
			right -= 1;
		if (left != right)
			a[left] = a[right];//填坑
		//坑在右侧，从左侧开始遍历
		while (left < right && a[left] <= a[right]) 
			left += 1;
		if (left != right)
			a[right] = a[left];//填坑
	}
	a[left] = key;//填坑
	return left;
}
//双指针法
int Partition3(int* a, int left, int right) {
	int key = a[left];//记录关键字
	int f = left, s = left + 1;//快指针指向的元素大于等于关键字，慢指针指向的元素小于等于关键字
	while (f <= right) {
		//快指针指向的元素大于等于关键字
		if (a[f] >= key) {
			f += 1;//右移快指针
		}
		//快指针指向的元素小于关键字
		else {
			//当慢指针与快指针间隔大于1
			if (s + 1 != f)
				s += 1;//移动慢指针
			Swap(&a[f], &a[s]);//交换快慢指针指向的元素
		}
	}
	return s + 1;
}
//快排优化——随机数取中
int Partition4(int* a, int left, int right) {
	//获取随机下标
	int mid = rand() % (right - left + 1);
	//与左侧进行交换
	Swap(&a[left], &a[mid]);
	//通过双指针实现
	int key = a[left];
	int s = left, f = left + 1;
	while (f <= right) {
		if (a[f] <= key && ++s != f)
			Swap(&a[s], &a[f]);
		f += 1;
	}
	return s + 1;
}

//快速排序1——Hoare版本
void QuickSort1(int* a, int left, int right) {
	if (left >= right)
		return;
	int key = Partition1(a, left, right);
	QuickSort1(a, left, key);
	QuickSort1(a, key + 1, right);
}
//快速排序2——挖坑法
void QuickSort2(int* a, int left, int right) {
	if (left >= right)
		return;
	int key = Partition2(a, left, right);
	QuickSort1(a, left, key);
	QuickSort1(a, key + 1, right);
}
//快速排序3——双指针
void QuickSort3(int* a, int left, int right) {
	if (left >= right)
		return;
	int key = Partition3(a, left, right);
	QuickSort1(a, left, key);
	QuickSort1(a, key + 1, right);
}

//归并排序
void MergeSort(int* a, int len) {

}
//计数排序
void CountSort(int* a, int len) {
	//找最小值与最大值
	int min = a[0], max = a[len - 1];
	for (int i = 0; i < len; i++) {
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	int N = max - min + 1;//数据的具体范围
	//可以申请堆区空间，也可以直接申请栈区空间
	int* nums = (int*)calloc(N + 1, sizeof(int));
	assert(nums);
	//计数
	for (int i = 0; i < len; i++) {
		nums[a[i] - min] += 1;
	}
	//排序
	len = 0;
	for (int i = min; i <= max; i++) {
		while (nums[i - min]) {
			a[len] = i;
			len += 1;
			nums[i - min] -= 1;
		}
	}
}

//桶排序
typedef struct Bucket {
	int value;//数据
	struct Bucket* next;//同一个桶中的下一个元素结点
}Bucket;
//初始化桶
void Init(Bucket** b,int len) {
	assert(b);
	Bucket* p = *b;
	for (int i = 0; i < len; i++) {
		p[i].value = i;
		p[i].next = NULL;
	}
}
//插入桶元素
void Insert(Bucket** b, int x) {
	assert(b);
	int key = x / 10;
	Bucket* q = *b + key;//前驱指针
	Bucket* p = q->next;//当前结点
	//待插入结点
	Bucket* s = (Bucket*)calloc(1, sizeof(Bucket));
	assert(s);
	s->value = x;
	s->next = NULL;
	//查询插入位置
	while (p && p->value < s->value) {
			q = p;
			p = p->next;
	}
	//后插
	s->next = q->next;
	q->next = s;
}
//删除桶元素
void Delete(Bucket* b, int* a, int* len) {
	assert(b && a && len);
	Bucket* p = b->next;
	while (p) {
		//删除结点
		b->next = p->next;
		p->next = NULL;
		//记录结点数据
		a[*len] = p->value;
		*len += 1;
		//释放结点
		free(p);
		p = b->next;
	}
}
void Destroy(Bucket** b,int len) {
	assert(b);
	for (int i = 0; i < len; i++) {
		Bucket* p = (*b)[i].next;
		while (p) {
			printf("数据%d已丢失\n", p->value);
			(*b)[i].next = p->next;
			p->next = NULL;
			free(p);
			p = (*b)[i].next;
		}
	}
	free(*b);
}

void BucketSort(int* a, int len) {
	assert(a);
	int count = 10;//桶个数
	//创建指向桶的指针
	Bucket* b = (Bucket*)calloc(count, sizeof(Bucket));
	assert(b);
	//初始化桶
	Init(&b, count);
	//插入元素
	for (int i = 0; i < len; i++) {
		Insert(&b, a[i]);
	}
	//元素排序
	len = 0;
	for (int i = 0; i < 10; i++) {
		if (b[i].next) {
			Delete(&b[i], a, &len);
		}
	}
	Destroy(&b, count);
}