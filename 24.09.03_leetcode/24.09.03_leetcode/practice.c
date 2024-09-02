#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.09.03力扣网刷题
//重新分装苹果——贪心、数组、排序——简单
//给你一个长度为 n 的数组 apple 和另一个长度为 m 的数组 capacity 。
//一共有 n 个包裹，其中第 i 个包裹中装着 apple[i] 个苹果。同时，还有 m 个箱子，第 i 个箱子的容量为 capacity[i] 个苹果。
//请你选择一些箱子来将这 n 个包裹中的苹果重新分装到箱子中，返回你需要选择的箱子的 最小 数量。
//注意，同一个包裹中的苹果可以分装到不同的箱子中。
//示例 1：
//输入：apple = [1, 3, 2], capacity = [4, 3, 1, 5, 2]
//输出：2
//解释：使用容量为 4 和 5 的箱子。
//总容量大于或等于苹果的总数，所以可以完成重新分装。
//示例 2：
//输入：apple = [5, 5, 5], capacity = [2, 4, 2, 7]
//输出：4
//解释：需要使用所有箱子。
//提示：
//1 <= n == apple.length <= 50
//1 <= m == capacity.length <= 50
//1 <= apple[i], capacity[i] <= 50
//输入数据保证可以将包裹中的苹果重新分装到箱子中。

void CountSort(int* a, int n) {
	int nums[51] = { 0 };
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++) {
		nums[a[i]] += 1;
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	n = 0;
	for (int i = max; i >= min; i--) {
		while (nums[i]) {
			a[n++] = i;
			nums[i] -= 1;
		}
	}
}

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
	CountSort(capacity, capacitySize);
	int sum = 0;
	for (int i = 0; i < appleSize; i++) {
		sum += apple[i];
	}
	int ans = 0;
	for (int i = 0; i < capacitySize; i++) {
		sum -= capacity[i];
		ans += 1;
		if (sum <= 0) {
			break;
		}
	}
	return ans;
}