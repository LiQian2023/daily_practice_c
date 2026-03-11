#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.11力扣网刷题
//703. 数据流中的第 K 大元素——树、设计、二叉搜索树、二叉树、数据流、堆（优先队列）——简单
//设计一个找到数据流中第 k 大元素的类（class）。
//注意是排序后的第 k 大元素，不是第 k 个不同的元素。
//请实现 KthLargest 类：
//KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
//int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
//示例 1：
//输入：
//["KthLargest", "add", "add", "add", "add", "add"]
//[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
//输出：[null, 4, 5, 5, 8, 8]
//解释：
//KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
//kthLargest.add(3); // 返回 4
//kthLargest.add(5); // 返回 5
//kthLargest.add(10); // 返回 5
//kthLargest.add(9); // 返回 8
//kthLargest.add(4); // 返回 8
//示例 2：
//输入：
//["KthLargest", "add", "add", "add", "add"]
//[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
//输出：[null, 7, 7, 7, 8]
//解释：
//KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
//kthLargest.add(2); // 返回 7
//kthLargest.add(10); // 返回 7
//kthLargest.add(9); // 返回 7
//kthLargest.add(9); // 返回 8
//提示：
//0 <= nums.length <= 10^4
//1 <= k <= nums.length + 1
//- 10^4 <= nums[i] <= 10^4
//- 10^4 <= val <= 10^4
//最多调用 add 方法 10^4 次

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// 大堆
void AdjustDown(int* nums, int len, int parent) {
	int child = 2 * parent + 1;
	while (child < len) {
		if (child + 1 < len && nums[child] < nums[child + 1]) {
			child += 1;
		}
		if (nums[child] > nums[parent]) {
			Swap(&nums[child], &nums[parent]);
		}
		parent = child;
		child = parent * 2 + 1;
	}
}
// 建大堆
void CreateHeap(int* nums, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		AdjustDown(nums, len, i);
	}
}
// 升序排列
void HeapSort(int* nums, int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap(&nums[0], &nums[i]);
		AdjustDown(nums, i, 0);
	}
}

// 小堆
void AdjustDown_(int* nums, int len, int parent) {
	int child = 2 * parent + 1;
	while (child < len) {
		if (child + 1 < len && nums[child] > nums[child + 1]) {
			child += 1;
		}
		if (nums[child] < nums[parent]) {
			Swap(&nums[child], &nums[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
// 建小堆
void CreateHeap_(int* nums, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		AdjustDown_(nums, len, i);
	}
}
typedef struct {
	int k;
	int* heap;
	int len;
	int min, max;
} KthLargest;

int Min(int a, int b) {
	return a > b ? b : a;
}
int Max(int a, int b) {
	return a > b ? a : b;
}
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
	KthLargest* obj = (KthLargest*)calloc(1, sizeof(KthLargest));
	assert(obj);
	obj->k = k;
	obj->heap = (int*)calloc(k, sizeof(int));
	assert(obj->heap);
	obj->len = 0;
	obj->min = obj->heap[0];
	obj->max = obj->heap[0];
	for (int i = 0; i < numsSize; i++) {
		if (obj->len != obj->k) {
			obj->heap[obj->len] = nums[i];
			obj->len += 1;
			if (obj->len == obj->k) {
				CreateHeap_(obj->heap, obj->k);
			}
		}
		else {
			if (obj->heap[0] < nums[i]) {
				obj->heap[0] = nums[i];
				AdjustDown_(obj->heap, obj->k, 0);
			}
		}
		obj->min = Min(obj->min, nums[i]);
		obj->max = Max(obj->max, nums[i]);
	}
	return obj;
}


int kthLargestAdd(KthLargest* obj, int val) {
	obj->min = Min(obj->min, val);
	obj->max = Max(obj->max, val);
	if (obj->len < obj->k) {
		obj->heap[obj->len] = val;
		obj->len += 1;
		if (obj->len == obj->k) {
			CreateHeap_(obj->heap, obj->k);
		}
		else {
			return obj->min;
		}
	}
	else {
		if (val > obj->heap[0]) {
			obj->heap[0] = val;
			AdjustDown_(obj->heap, obj->k, 0);
		}
	}
	return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
	free(obj->heap);
	free(obj);
}