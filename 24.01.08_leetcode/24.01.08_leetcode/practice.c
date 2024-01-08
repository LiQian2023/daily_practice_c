#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.01.08力扣网刷题
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
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
double average(int* salary, int salarySize) {
	qsort(salary, salarySize, 4, cmp);
	int sum = 0;
	for (int i = 1; i < salarySize - 1; i++)
		sum += salary[i];
	return sum / (salarySize - 2.0);
}
int main() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int* L = (int*)calloc(n, sizeof(int));
		for (int i = 0; i < n; i++)
			scanf("%d", &L[i]);
		double ret = average(L, n);
		printf("%.5lf\n", ret);
	}
	return 0;
}