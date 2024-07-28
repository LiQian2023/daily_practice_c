#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.07.28力扣网刷题
//根据数字二进制下 1 的数目排序——位运算、数组、计数、排序——简单
//给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
//如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
//请你返回排序后的数组。
//示例 1：
//输入：arr = [0, 1, 2, 3, 4, 5, 6, 7, 8]
//输出：[0, 1, 2, 4, 8, 3, 5, 6, 7]
//解释：[0] 是唯一一个有 0 个 1 的数。
//[1, 2, 4, 8] 都有 1 个 1 。
//[3, 5, 6] 有 2 个 1 。
//[7] 有 3 个 1 。
//按照 1 的个数排序得到的结果数组为[0, 1, 2, 4, 8, 3, 5, 6, 7]
//示例 2：
//输入：arr = [1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1]
//输出：[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]
//解释：数组中所有整数二进制下都只有 1 个 1 ，所以你需要按照数值大小将它们排序。
//示例 3：
//输入：arr = [10000, 10000]
//输出：[10000, 10000]
//示例 4：
//输入：arr = [2, 3, 5, 7, 11, 13, 17, 19]
//输出：[2, 3, 5, 17, 7, 11, 13, 19]
//示例 5：
//输入：arr = [10, 100, 1000, 10000]
//输出：[10, 100, 10000, 1000]
//提示：
//1 <= arr.length <= 500
//0 <= arr[i] <= 10 ^ 4


//方法一：桶排序
typedef struct LinkNode {
	int val;
	struct LinkNode* next;
}LN;

typedef struct Bucket {
	int nums;
	LN* node;
}Bucket;

int One_num(int num) {
	int count = 0;
	while (num) {
		count += num & 1;
		num >>= 1;
	}
	return count;
}
void Init(Bucket* B) {
	for (int i = 0; i < 32; i++) {
		B[i].nums = 0;
		B[i].node = (LN*)calloc(1, sizeof(LN));
		assert(B[i].node);
		B[i].node->next = NULL;
		B[i].node->val = 0;
	}
}
void Insert(Bucket* B, int key, int value) {
	LN* p = (LN*)calloc(1, sizeof(LN));
	assert(p);
	p->next = NULL;
	p->val = value;
	if (B[key].nums == 0) {
		B[key].node->next = p;
	}
	else {
		LN* q = B[key].node, * l = B[key].node->next;
		while (l && l->val <= p->val) {
			q = l;
			l = l->next;
		}
		p->next = q->next;
		q->next = p;
	}
	B[key].nums += 1;
}
LN* Delete(Bucket* B, int key) {
	LN* p = B[key].node->next;
	if (B[key].nums) {
		B[key].node->next = p->next;
		p->next = NULL;
		B[key].nums -= 1;
	}
	return p;
}
void Destroy(Bucket* B, int len) {
	for (int i = 0; i < len; i++) {
		free(B[i].node);
	}
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
	*returnSize = arrSize;
	Bucket* B = (Bucket*)calloc(32, sizeof(Bucket));
	assert(B);
	Init(B);
	for (int i = 0; i < arrSize; i++) {
		int key = One_num(arr[i]);// 获取桶序号
		Insert(B, key, arr[i]);
	}
	int* ans = (int*)calloc(arrSize, sizeof(int));
	assert(B);
	int len = 0;
	for (int i = 0; i < 32;) {
		LN* p = Delete(B, i);
		if (p) {
			ans[len++] = p->val;
			free(p);
		}
		else
			i++;
		if (len == arrSize)
			break;
	}
	Destroy(B, 32);
	free(B);
	return ans;
}

void test4() {
	int arr[11] = { 1024,512,256,128,64,32,16,8,4,2,1 };
	int n = 11;
	int size = 0;
	int* ret = sortByBits(arr, n, &size);
	Print_Int(ret, size);
	free(ret);
}