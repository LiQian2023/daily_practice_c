#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2026.01.28力扣网刷题
//LCR 179. 查找总价格为目标值的两个商品——数组、二分查找、双指针——简单
//购物车内的商品价格按照升序记录于数组 price。请在购物车中找到两个商品的价格总和刚好是 target。若存在多种情况，返回任一结果即可。
//示例 1：
//输入：price = [3, 9, 12, 15], target = 18
//输出：[3, 15] 或者[15, 3]
//示例 2：
//输入：price = [8, 21, 27, 34, 52, 66], target = 61
//输出：[27, 34] 或者[34, 27]
//提示：
//1 <= price.length <= 10 ^ 5
//1 <= price[i] <= 10 ^ 6
//1 <= target <= 2 * 10 ^ 6

int* twoSum1(int* price, int priceSize, int target, int* returnSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*returnSize = 2;
	int min = price[0], max = price[0];
	for (int i = 0; i < priceSize; i++) {
		if (price[i] < min) {
			min = price[i];
		}
		else if (price[i] > max) {
			max = price[i];
		}
	}
	int size = max - min + 1;
	bool* hash = (bool*)calloc(size, sizeof(bool));
	assert(hash);
	for (int i = 0; i < priceSize; i++) {
		int key = price[i] - min;
		hash[key] = true;
	}
	for (int i = 0; i < priceSize; i++) {
		int key = target - price[i] - min;
		if (key < size && hash[key]) {
			ans[0] = price[i];
			ans[1] = target - price[i];
			break;
		}
	}
	free(hash);
	return ans;
}

int BiSearch(int* price, int priceSize, int l, int r, int key) {
	while (l <= r) {
		int m = (r - l) / 2 + l;
		if (price[m] == key) {
			return m;
		}
		else if (price[m] < key) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return -1;
}
int* twoSum2(int* price, int priceSize, int target, int* returnSize) {
	*returnSize = 2;
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	for (int i = 0; i < priceSize; i++) {
		int key = target - price[i];
		int l = i + 1, r = priceSize - 1;
		if (key < price[r]) {
			int ret = BiSearch(price, priceSize, l, r, key);
			if (ret != -1) {
				ans[0] = price[i];
				ans[1] = key;
				break;
			}
		}
		else if (key == price[r]) {
			ans[0] = price[i];
			ans[1] = key;
			break;
		}
	}
	return ans;
}

int* twoSum(int* price, int priceSize, int target, int* returnSize) {
	*returnSize = 2;
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	for (int l = 0, r = priceSize - 1; l < r;) {
		int key = target - price[l];
		if (key < price[r]) {
			r -= 1;
		}
		else if (key > price[r]) {
			l += 1;
		}
		else {
			ans[0] = price[l];
			ans[1] = price[r];
			break;
		}
	}
	return ans;
}