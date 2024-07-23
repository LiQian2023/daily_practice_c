#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//2024.07.23力扣网刷题
//合并两个有序数组——数组、双指针、排序——简单
//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
//为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
//示例 1：
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//解释：需要合并[1, 2, 3] 和[2, 5, 6] 。
//合并结果是[1, 2, 2, 3, 5, 6] ，其中斜体加粗标注的为 nums1 中的元素。
//示例 2：
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]
//解释：需要合并[1] 和[] 。
//合并结果是[1] 。
//示例 3：
//输入：nums1 = [0], m = 0, nums2 = [1], n = 1
//输出：[1]
//解释：需要合并的数组是[] 和[1] 。
//合并结果是[1] 。
//注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
//提示：
//nums1.length == m + n
//nums2.length == n
//0 <= m, n <= 200
//1 <= m + n <= 200
//- 10^9 <= nums1[i], nums2[j] <= 10^9
//进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？

//方法一：归并排序——分区归并
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int* tmp = (int*)calloc(n + m, sizeof(int));
	assert(tmp);
	int len = 0;
	int i = 0, j = 0;
	while ( i < m && j < n) {
		if (nums1[i] <= nums2[j]) {
			tmp[len++] = nums1[i++];
		}
		else {
			tmp[len++] = nums2[j++];
		}
	}
	while (i < m) tmp[len++] = nums1[i++];
	while (j < n) tmp[len++] = nums2[j++];
	for (i = 0; i < m + n; i++)
		nums1[i] = tmp[i];
	free(tmp);
}


//第三大的数——数组、排序——简单
//给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
//示例 1：
//输入：[3, 2, 1]
//输出：1
//解释：第三大的数是 1 。
//示例 2：
//输入：[1, 2]
//输出：2
//解释：第三大的数不存在, 所以返回最大的数 2 。
//示例 3：
//输入：[2, 2, 3, 1]
//输出：1
//解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
//此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
//提示：
//1 <= nums.length <= 10^4
//- 2^31 <= nums[i] <= 2^31 - 1
//进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？

//方法一：暴力求解
void Print(int* num, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
}
void Swap(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//方法一：暴力求解
int thirdMax1(int* nums, int numsSize) {
	if (numsSize == 1)
		return nums[0];
	if (numsSize == 2)
		return nums[0] >= nums[1] ? nums[0] : nums[1];
	//确保数组前三个元素各不相等
	for (int i = 1; i < 3; i++) {
		bool same = false;
		for (int j = i - 1; j >= 0; j--) {
			if (nums[i] == nums[j]) {
				same = true;
				break;
			}
		}
		if (!same)
			continue;
		for (int j = i + 1; j < numsSize; j++) {
			bool change = true;
			for (int z = i - 1; z >= 0; z--) {
				if (nums[z] == nums[j]) {
					change = false;
					break;
				}
			}
			if (change) {
				Swap(&nums[j], &nums[i]);
				break;
			}
		}
	}
	//判断前三个数中不相等的数字的个数
	int num = 0;
	if (nums[1] != nums[2])
		num++;
	if (nums[1] != nums[0])
		num++;
	if (nums[0] != nums[2])
		num++;

	//找前三大的数
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < numsSize; j++) {
			if (nums[j] > nums[i]) {
				bool change = true;
				for (int z = i - 1; z >= 0; z--) {
					if (nums[j] == nums[z]) {
						change = false;
						break;
					}
				}
				if (change) {
					Swap(&nums[j], &nums[i]);
				}
			}
		}
	}
	if (num <= 2)
		nums[2] = nums[0];
	return nums[2];
}



void Adjust_Down(int* nums, int parent, int len) {
	int child = parent * 2 + 1;
	while (child < len) {
		if (child + 1 < len && nums[child] > nums[child + 1])
			child += 1;
		if (nums[parent] > nums[child]) {
			Swap(&nums[child], &nums[parent]);
		}
		parent = child;
		child = parent * 2 + 1;
	}
}
void HeapSort(int* nums, int len) {
	for (int i = len - 1; i > 0; i--) {
		Swap(&nums[0], &nums[i]);
		Adjust_Down(nums, 0, i);
	}
}
//去重
int* getSingle(int* one_num, int* nums, int* len,int size) {
	for (int i = 0; i < size; i++) {
		bool flag = true;
		//查重
		for (int j = *len - 1; j >= 0; j--) {
			if (nums[i] == one_num[j]) {
				flag = false;
				break;
			}
		}
		//非重元素存入数组one_num
		if (flag) {
			int* tmp = NULL;
			tmp = (int*)realloc(one_num, (*len + 1)*sizeof(int));
			assert(tmp);
			one_num = tmp;
			one_num[*len] = nums[i];
			*len += 1;
			Print(one_num, *len);
		}
	}
	return one_num;
}
//方法二：堆排序
int thirdMax2(int* nums, int numsSize) {
	int len = 1;
	int* one_num = (int*)calloc(len, sizeof(int));
	assert(one_num);
	one_num[0] = nums[0];
	//去重
	one_num = getSingle(one_num, nums, &len, numsSize);
	Print(one_num, len);
	//建小堆
	for (int i = (len - 1) / 2; i >= 0; i--) {
		Adjust_Down(one_num, i, len);
	}
	//排序
	HeapSort(one_num, len);
	int ans = 0;
	if (len < 3)
		ans = one_num[0];
	else
		ans = one_num[2];
	free(one_num);
	return ans;
}
//方法三：qsort
int cmp(const void* p1, const void* p2) {
	if (*(int*)p2 > *(int*)p1)
		return 1;
	else if (*(int*)p2 < *(int*)p1)
		return -1;
	return 0;
}
int thirdMax3(int* nums, int numsSize) {
	int len = 1;
	int* one_num = (int*)calloc(len, sizeof(int));
	assert(one_num);
	one_num[0] = nums[0];
	//去重
	one_num = getSingle(one_num, nums, &len, numsSize);
	//排序
	qsort(one_num, len, sizeof(int), cmp);
	int ans = 0;
	if (len < 3)
		ans = one_num[0];
	else
		ans = one_num[2];
	free(one_num);
	return ans;
}
//方法四：暴力求解优化
int thirdMax4(int* nums, int numsSize) {
	int len = 1;
	int* one_num = (int*)calloc(len, sizeof(int));
	assert(one_num);
	one_num[0] = nums[0];
	//去重
	one_num = getSingle(one_num, nums, &len, numsSize);
	//暴力求解
	for (int i = 1; i < len; i++) {
		if (one_num[i] > one_num[0]){
			Swap(&one_num[i], &one_num[0]);
		}
			
	}
	int ans = 0;
	if (len < 3)
		ans = one_num[0];
	else {
		int mid = one_num[0];
		int min = one_num[0];
		for (int i = 2; i < len; i++) {
			if (one_num[i] > one_num[1])
				Swap(&one_num[i], &one_num[1]);
		}
		for (int i = 3; i < len; i++) {
			if (one_num[i] > one_num[2])
				Swap(&one_num[i], &one_num[2]);
		}
		ans = one_num[2];
	}
	free(one_num);
	return ans;
}

//方法五：简单选择排序
void SelectSort(int A[], int len) {
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < len; j++) {
			if (A[i] < A[j])
				Swap(&A[i], &A[j]);
		}
	}
}
int thirdMax5(int* nums, int numsSize) {
	int len = 1;
	int* one_num = (int*)calloc(len, sizeof(int));
	assert(one_num);
	one_num[0] = nums[0];
	//去重
	one_num = getSingle(one_num, nums, &len, numsSize);
	//暴力求解
	SelectSort(one_num, len);
	int ans = 0;
	if (len < 3)
		ans = one_num[0];
	else
		ans = one_num[2];
	free(one_num);
	return ans;
}
void test() {
	int nums[10] = { 1,2,2,5,3,5 };
	int n = 6;
	int ret = thirdMax(nums, n);
	printf("%d\n", ret);
}

int main() {
	test();
	return 0;
}