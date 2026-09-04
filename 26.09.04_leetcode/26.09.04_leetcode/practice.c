#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.09.04力扣网刷题
//4038. 计算单个区间中出现的整数数量——中级工程师、第517场周赛——简单
//给你一个整数数组 nums。
//如果整数 x 在 nums 中的所有出现位置都位于同一个 连续 区间内，则称 x 为 特殊整数。
//返回 nums 中 不同 特殊整数的数量。
//示例 1：
//输入： nums = [1, 2, 2, 1]
//输出： 1
//解释：
//1 出现在下标 0 和 3，形成了两个分离的区间，因此它不是特殊整数。
//2 在下标[1, 2] 处形成一个连续区间，因此它是特殊整数。
//因此，共有一个特殊整数。
//示例 2：
//输入： nums = [3, 3, 1, 2, 2, 1]
//输出： 2
//解释：
//3 在下标[0, 1] 处形成一个连续区间，因此它是特殊整数。
//1 出现在下标 2 和 5，形成了两个分离的区间，因此它不是特殊整数。
//2 在下标[3, 4] 处形成一个连续区间，因此它是特殊整数。
//因此，共有两个特殊整数。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

typedef struct Hash {
	int key;
	int value;
	bool flag;
}Hash;

Hash* Create(int n) {
	Hash* h = (Hash*)calloc(n, sizeof(Hash));
	assert(h);
	for (int i = 0; i < n; i++) {
		h[i].key = -1;
		h[i].value = -1;
		h[i].flag = true;
	}
	return h;
}
int getKey(Hash* h, int n, int x) {
	int key = x % n;
	while (h[key].key != -1 && h[key].key != x) {
		key = (key + 1) % n;
	}
	return key;
}
void Push(Hash* h, int n, int x, int i) {
	int key = getKey(h, n, x);
	h[key].key = x;
	h[key].value = i;
}
void Destroy(Hash** h) {
	free(*h);
	*h = NULL;
}
int countSpecialIntegers(int* nums, int numsSize) {
	Hash* h = Create(numsSize);
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		int key = getKey(h, numsSize, nums[i]);
		if (h[key].key == -1) {
			Push(h, numsSize, nums[i], i);
			ans += 1;
		}
		else {
			if (h[key].value != i - 1) {
				if (h[key].flag) {
					ans -= 1;
				}
				h[key].flag = false;
			}
			else {
				h[key].value = i;
			}
		}
	}
	Destroy(&h);
	return ans;
}