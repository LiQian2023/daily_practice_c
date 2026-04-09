#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.04.08力扣网刷题
//LCR 059. 数据流中的第 K 大元素——树、设计、二叉搜索树、二叉树、数据流、堆（优先队列）——简单
//设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
//请实现 KthLargest 类：
//KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
//int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
//示例：
//输入：
//["KthLargest", "add", "add", "add", "add", "add"]
//[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
//输出：
//[null, 4, 5, 5, 8, 8]
//解释：
//KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
//kthLargest.add(3);   // return 4
//kthLargest.add(5);   // return 5
//kthLargest.add(10);  // return 5
//kthLargest.add(9);   // return 8
//kthLargest.add(4);   // return 8
//提示：
//1 <= k <= 10^4
//0 <= nums.length <= 10^4
//- 10^4 <= nums[i] <= 10^4
//- 10^4 <= val <= 10^4
//最多调用 add 方法 10^4 次
//题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素
//注意：本题与主站 703 题相同： https ://leetcode.cn/problems/kth-largest-element-in-a-stream/

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
typedef struct {
	int maxLen;
	int len;
	int* data;
} KthLargest;

void adjustDown(KthLargest* obj, int len, int parent) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && obj->data[child + 1] < obj->data[child]) {
			child += 1;
		}
		if (obj->data[child] < obj->data[parent]) {
			Swap(&(obj->data[child]), &(obj->data[parent]));
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void CreateHeap(KthLargest* obj) {
	for (int i = (obj->len - 2) / 2; i >= 0; i--) {
		adjustDown(obj, obj->len, i);
	}
}
void push(KthLargest* obj, int val) {
	obj->data[obj->len] = val;
	obj->len += 1;
	if (obj->len == obj->maxLen) {
		CreateHeap(obj);
	}
}
int kthLargestAdd(KthLargest* obj, int val) {
	if (obj->len == obj->maxLen) {
		if (val > obj->data[0]) {
			obj->data[0] = val;
			adjustDown(obj, obj->len, 0);
		}
	}
	else {
		push(obj, val);
	}
	return obj->data[0];
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
	KthLargest* heap = (KthLargest*)calloc(1, sizeof(KthLargest));
	assert(heap);
	heap->maxLen = k;
	heap->len = 0;
	heap->data = (int*)calloc(k, sizeof(int));
	assert(heap->data);
	for (int i = 0; i < numsSize; i++) {
		int ret = kthLargestAdd(heap, nums[i]);
	}
	return heap;
}



void kthLargestFree(KthLargest* obj) {
	free(obj->data);
	free(obj);
}


/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/