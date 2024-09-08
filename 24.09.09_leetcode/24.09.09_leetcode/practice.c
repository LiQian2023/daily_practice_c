#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2024.09.09力扣网刷题
//库存管理 III——数组、分治、快速选择、排序、堆（优先队列）——简单
//仓库管理员以数组 stock 形式记录商品库存表，其中 stock[i] 表示对应商品库存余量。
//请返回库存余量最少的 cnt 个商品余量，返回 顺序不限。
//示例 1：
//输入：stock = [2, 5, 7, 4], cnt = 1
//输出：[2]
//示例 2：
//输入：stock = [0, 2, 3, 6], cnt = 2
//输出：[0, 2] 或[2, 0]
//提示：
//0 <= cnt <= stock.length <= 10000
//0 <= stock[i] <= 10000
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Adjust_down(int* a, int n, int parent) {
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && a[child] < a[child + 1])
			child += 1;
		if (a[parent] < a[child])
			Swap(&a[parent], &a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}
void CreatHeap(int* a, int n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		Adjust_down(a, n, i);
	}
}
void HeapSort(int* a, int n) {
	for (int i = n - 1; i > 0; i--) {
		Swap(&a[i], &a[0]);
		Adjust_down(a, i, 0);
	}
}

int* inventoryManagement(int* stock, int stockSize, int cnt, int* returnSize) {
	int* ans = (int*)calloc(cnt, sizeof(int));
	assert(ans);
	*returnSize = cnt;
	CreatHeap(stock, stockSize);
	HeapSort(stock, stockSize);
	for (int i = 0; i < cnt; i++) {
		ans[i] = stock[i];
	}
	return ans;
}

void test() {
	int a[10] = { 2,5,7,4 };
	int cnt = 1;
	int size = 0;
	int* ret = inventoryManagement(a, 4, cnt, &size);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", ret[i]);
	}
	printf("\n");
	free(ret);
}

int main() {
	test();
	return 0;
}