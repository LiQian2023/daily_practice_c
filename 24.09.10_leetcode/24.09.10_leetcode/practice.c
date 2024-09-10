#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.09.10力扣网刷题
//库存管理 II——数组、哈希表、分治、计数、排序——简单
//仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品 id，可能存在重复。请返回库存表中数量大于 stock.length / 2 的商品 id。
//示例 1:
//输入: stock = [6, 1, 3, 1, 1, 1]
//输出 : 1
//限制：
//1 <= stock.length <= 50000
//给定数组为非空数组，且存在结果数字

void ShellSort(int* a, int len) {
	for (int gap = len / 2; gap; gap /= 2) {
		for (int i = 0; i < len - gap; i++) {
			int key = a[i + gap];
			int j = i;
			while (j >= 0 && a[j] > key) {
				a[j + gap] = a[j];
				j -= gap;
			}
			a[j + gap] = key;
		}
	}
}

int inventoryManagement(int* stock, int stockSize) {
	ShellSort(stock, stockSize);
	int l = 0, r = 0;
	int key = stockSize / 2;
	while (r < stockSize) {
		if (stock[l] == stock[r]) {
			r++;
		}
		else {
			if (r - l > key) {
				break;
			}
			else {
				l = r;
			}
		}
	}
	return stock[l];
}

void test() {
	int a[] = { 12,52,12,70,12,61,12,12,50,72,82,12,11,25,28,43,40,12,12,53,12,12,98,12,12,92,81,2,12,15,40,12,12,9,12,31,12,12,12,12,77,12,12,50,12,12,12,93,41,92,12,12,12,12,12,12,12,12,12,37,48,14,12,70,82,12,80,12,12,12,12,56,30,12,8,12,50,12,20,12,21,97,12,42,12,10,12,38,73,15,9,11,79,12,12,28,51,12,15,12 };
	int len = 100;
	printf("%d\n", inventoryManagement(a, len));
}

int main() {
	test();
	return 0;
}