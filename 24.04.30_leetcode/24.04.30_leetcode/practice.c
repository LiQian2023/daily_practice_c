#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
//2024.04.30力扣网刷题
//满足目标工作时长的员工数目——数组——简单
//公司里共有 n 名员工，按从 0 到 n - 1 编号。每个员工 i 已经在公司工作了 hours[i] 小时。
//公司要求每位员工工作 至少 target 小时。
//给你一个下标从 0 开始、长度为 n 的非负整数数组 hours 和一个非负整数 target 。
//请你用整数表示并返回工作至少 target 小时的员工数。
//示例 1：
//输入：hours = [0, 1, 2, 3, 4], target = 2
//输出：3
//解释：公司要求每位员工工作至少 2 小时。
//- 员工 0 工作 0 小时，不满足要求。
//- 员工 1 工作 1 小时，不满足要求。
//- 员工 2 工作 2 小时，满足要求。
//- 员工 3 工作 3 小时，满足要求。
//- 员工 4 工作 4 小时，满足要求。
//共有 3 位满足要求的员工。
//示例 2：
//输入：hours = [5, 1, 4, 2, 2], target = 6
//输出：0
//解释：公司要求每位员工工作至少 6 小时。
//共有 0 位满足要求的员工。
//提示：
//1 <= n == hours.length <= 50
//0 <= hours[i], target <= 10^5

int cmp(const void* p1, const void* p2) {
	return *(int*)p2 - *(int*)p1;
}

int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target) {
	qsort(hours, hoursSize, sizeof(int), cmp);
	if (hours[0] < target)
		return 0;
	if (hours[hoursSize - 1] >= target)
		return hoursSize;
	int l = 0, r = hoursSize - 1, flag = 0;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (hours[mid] >= target) 
			l = mid + 1;
		else {
			flag = mid;
			r = mid - 1;
		}
	}
	if (hours[r] < target)
		return r;
	return flag;
}

void test() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int num[50] = { 0 };
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		int k = 0;
		scanf("%d", &k);
		int ret = numberOfEmployeesWhoMetTarget(num, n, k);
		printf("%d\n", ret);
	}
}

int main() {
	test();
	return 0;
}