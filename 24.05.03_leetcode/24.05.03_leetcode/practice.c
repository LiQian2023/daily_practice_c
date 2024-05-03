#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//2024.05.03力扣网刷题
//去掉最低工资和最高工资后的工资平均值——数组、排序——简单
//给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。
//请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。
//示例 1：
//输入：salary = [4000, 3000, 1000, 2000]
//输出：2500.00000
//解释：最低工资和最高工资分别是 1000 和 4000 。
//去掉最低工资和最高工资以后的平均工资是(2000 + 3000) / 2 = 2500
//示例 2：
//输入：salary = [1000, 2000, 3000]
//输出：2000.00000
//解释：最低工资和最高工资分别是 1000 和 3000 。
//去掉最低工资和最高工资以后的平均工资是(2000) / 1 = 2000
//示例 3：
//输入：salary = [6000, 5000, 4000, 3000, 2000, 1000]
//输出：3500.00000
//示例 4：
//输入：salary = [8000, 9000, 2000, 3000, 6000, 1000]
//输出：4750.00000
//提示：
//3 <= salary.length <= 100
//10 ^ 3 <= salary[i] <= 10 ^ 6
//salary[i] 是唯一的。
//与真实值误差在 10 ^ -5 以内的结果都将视为正确答案。

//方法一：qsort排序
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}

double average1(int* salary, int salarySize) {
	qsort(salary, salarySize, sizeof(int), cmp);
	double ans = 0;
	for (int i = 1; i < salarySize - 1; i++)
		ans += salary[i];
	return ans / (salarySize - 2);
}

//方法二：堆排序
void Swap(int* pa, int* pb) {
	assert(pa && pb);
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void AdjustDown(int* num, int n,int parent) {
	assert(num);
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && num[child] < num[child + 1])
			child++;
		//建大堆
		if (num[parent] < num[child]) {
			Swap(&num[parent], &num[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

double average(int* salary, int salarySize) {
	//建大堆
	for (int i = (salarySize - 2) / 2; i >= 0; i--)
		AdjustDown(salary, salarySize, i);
	//堆排序——升序
	int end = salarySize - 1;//取最后一个元素
	while (end > 0) {
		Swap(&salary[end], &salary[0]);//首尾元素互换
		AdjustDown(salary, end, 0);
		end--;
	}
	double ans = 0;
	for (int i = 1; i < salarySize - 1; i++)
		ans += salary[i];
	return ans / (salarySize - 2);
}

void test() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int num[100] = { 0 };
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		double ret = average(num, n);
		printf("%d\n", ret);
	}
}

int main() {
	test();
	return 0;
}