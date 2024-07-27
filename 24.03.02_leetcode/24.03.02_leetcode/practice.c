#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

//2024.03.02力扣网刷题
//存在重复元素 II——数组、哈希表、滑动窗口——简单
//方法一：哈希表+滑动窗口——2024.07.28完成
//给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
//满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
//示例 1：
//输入：nums = [1, 2, 3, 1], k = 3
//输出：true
//示例 2：
//输入：nums = [1, 0, 1, 1], k = 1
//输出：true
//示例 3：
//输入：nums = [1, 2, 3, 1, 2, 3], k = 2
//输出：false
//提示：
//1 <= nums.length <= 10^5
//- 10^9 <= nums[i] <= 10^9
//0 <= k <= 10^5

//方法一：双指针——超时
bool containsNearbyDuplicate1(int* nums, int numsSize, int k) {
	int l = 0, r = numsSize - 1;
	while (l < r) {
		if (r - l > k) {
			r--;
			continue;
		}
		else {
			if (nums[l] == nums[r])
				return true;
			else {
				if (l == r - 1) {
					l++, r = numsSize - 1;
				}
				else {
					r--;
				}
			}
		}
	}
	return false;
}

//方法二：模拟——超时
bool containsNearbyDuplicate12(int* nums, int numsSize, int k) {
	if (k == 0 || numsSize == 1)
		return false;
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize && j <= i + k; j++) {
			if (nums[i] == nums[j])
				return true;
		}
	}
	return false;
}

//方法三：哈希表——超时
typedef struct Hash {
	int count;
	int value;
	int pi;
}Hash;
bool containsNearbyDuplicate3(int* nums, int numsSize, int k) {
	Hash* H = (Hash*)calloc(numsSize, sizeof(Hash));
	assert(H);
	int min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < min)
			min = nums[i];
	}
	for (int i = 0; i < numsSize; i++) {
		//获取关键字
		int key = (nums[i] - min) % numsSize;
		if (H[key].count == 0) {
			H[key].count = 1;
			H[key].pi = i;
			H[key].value = nums[i];
		}
		else {
			if (H[key].value == nums[i]) {
				if (i - H[key].pi <= k)
					return true;
				else
					H[key].pi = i;
			}
			else {
				while (H[key].value != nums[i] && H[key].count) {
					key++;
				}
				if (H[key].count == 0) {
					H[key].count = 1;
					H[key].value = nums[i];
					H[key].pi = i;
				}
				else {
					if (i - H[key].pi <= k)
						return true;
					else
						H[key].pi = i;
				}
			}
		}
	}
	return false;
}

//方法四：计数——内存太大
#define MAXSIZE 2000000000
bool containsNearbyDuplicate4(int* nums, int numsSize, int k) {
	int min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < min)
			min = nums[i];
	}
	int* tmp = (int*)calloc(MAXSIZE, sizeof(int));
	assert(tmp);
	for (int i = 0; i < numsSize; i++) {
		if (tmp[nums[i] - min] == 0)
			tmp[nums[i] - min] = i;
		else {
			if (i - tmp[nums[i]- min] <= k)
				return true;
			else
				tmp[nums[i] - min] = i;
		}
	}
	return false;
}

//方法五：哈希表+滑动窗口
typedef struct LinkNode {
	int value;
	int pi;
	struct LinkNode* next;
}LN;
typedef struct HashNode {
	int count;
	LN* node;
}HN;
void Init(HN* H, int len) {
	for (int i = 0; i < len; i++) {
		H[i].count = 0;
		H[i].node = (LN*)calloc(1, sizeof(LN));
		assert(H[i].node);
		H[i].node->pi = -1;
		H[i].node->value = 0;
		H[i].node->next = NULL;
	}
}
void Insert(HN* H, int key, int value, int pi) {
	H[key].count += 1;
	LN* p = (LN*)calloc(1, sizeof(LN));
	assert(p);
	p->value = value;
	p->pi = pi;
	p->next = NULL;
	LN* q = H[key].node;
	LN* l = H[key].node->next;
	if (!l) {
		H[key].node->next = p;
	}
	else {
		while (l && l->value < p->value) {
			q = l;
			l = l->next;
		}
		p->next = l;
		q->next = p;
	}
}
LN* Search(HN* H,int key,int value) {
	if (H[key].count == 0)
		return NULL;
	LN* p = H[key].node->next;
	while (p && p->value < value) {
		p = p->next;
	}
	return p;
}
void Delete(HN* H, int key) {
	if (H[key].count) {
		H[key].count -= 1;
		LN* p = H[key].node->next;
		H[key].node->next = p->next;
		p->next = NULL;
		free(p);
	}
}
void Destroy(HN* H,int len) {
	for (int i = 0; i < len; i++) {
		while (H[i].count)
			Delete(H, i);
	}
}
bool containsNearbyDuplicate5(int* nums, int numsSize, int k) {
	if (numsSize <= k + 1) {
		for (int i = 0; i < numsSize - 1; i++) {
			for (int j = i + 1; j < numsSize; j++) {
				if (nums[i] == nums[j])
					return true;
			}
		}
	}
	else {
		int min = nums[0];
		for (int i = 1; i < numsSize; i++) {
			if (nums[i] < min)
				min = nums[i];
		}
		//查找前k+1个元素
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j <= k; j++) {
				if (nums[i] == nums[j])
					return true;
			}
		}
		HN* H = (HN*)calloc(k + 1, sizeof(HN));
		assert(H);
		Init(H, k + 1);
		//创建哈希表
		for (int i = 0; i <= k; i++) {
			int key = (nums[i] - min) % (k + 1);
			Insert(H, key, nums[i], i);
		}
		for (int i = k + 1; i < numsSize; i++) {
			//查找
			int key = (nums[i] - min) % (k + 1);
			LN* p = Search(H, key, nums[i]);
			if (!p || p->value > nums[i]) {
				Delete(H, key);
				Insert(H, key, nums[i], i);
			}
			else if (i - p->pi > k) {
				p->pi = i;
			}
			else if (i - p->pi <= k) {
				Destroy(H, k + 1);
				return true;
			}
		}
		Destroy(H, k + 1);
	}
	return false;
}
void test4() {
	int arr[4] = { 1,0,1,1 };
	int n = 4;
	int k = 1;
	printf("%d\n", containsNearbyDuplicate5(arr, n, k));
}
#if 0
//方法三：哈希表
int isprime(int n) {
	for (n; n >= 4; n--) {
		int i = 0;
		for (i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)
				break;
		}
		if (i > sqrt(n))
			break;
	}
	return n;
}
typedef struct ListNode {
	short data[2];
	short next;
}LN;
typedef struct Hash {
	bool flag;
	LN* value;
}Hash;
//向表中添加元素
void Insert(Hash* h, int value, int index, int key) {
	h[key].flag = 1;
	h[key].value = (LN*)calloc(1, sizeof(LN));
	assert(h[key].value);
	h[key].value->data[0] = value;
	h[key].value->data[1] = index;
	h[key].value->next = -1;
}
int Search(Hash* h, int key) {
	if (h[key].value->next == -1) {

	}
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	// 获取不超过表长的质数
	int p = isprime(numsSize);
	printf("%d\n", p);
	Hash h[100] = { 0 };
	for (int i = 0; i < numsSize; i++) {
		//获取关键字
		int key = abs(nums[i] % p);
		//处理表中无元素的情况
		if (h[key].flag == 0) {
			Insert(h, nums[i], i, key);
		}
		else {
			//处理表中元素相等的情况
			if (h[key].value->data[0] == nums[i]) {
				if (i - h[key].value->data[1] <= k)
					return true;
				h[key].value->data[1] = i;
			}
			else {
				int d = key;
			}
		}
	}
	return false;
}
#endif



void test1() {
	int min = -24500;
	int max = 29999;
	int len = max - min + 1;
	int x = max % len;
	printf("%d\n", x * x);
}

void test2() {
	int k = 0;
	while (scanf("%d", &k) == 1) {
		//printf("%d\n", isprime(k));
	}
}
void test3() {
#define SIZE 1000000000
	printf("%d\n",INT_MAX);
	printf("%d\n",INT_MAX -SIZE);
}
int main() {
	test4();
	return 0;
}