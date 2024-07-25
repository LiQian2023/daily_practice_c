#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"


//2024.07.25力扣网刷题
//最长和谐子序列——数组、哈希、计数、排序、滑动窗口——简单
//和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
//现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。
//数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
//示例 1：
//输入：nums = [1, 3, 2, 2, 5, 2, 3, 7]
//输出：5
//解释：最长的和谐子序列是[3, 2, 2, 2, 3]
//示例 2：
//输入：nums = [1, 2, 3, 4]
//输出：2
//示例 3：
//输入：nums = [1, 1, 1, 1]
//输出：0
//提示：
//1 <= nums.length <= 2 * 10^4
//- 10^9 <= nums[i] <= 10^9

//方法一：堆排序
int findLHS1(int* nums, int numsSize) {
	CreatHeap(nums, numsSize);
	HeapSort(nums, numsSize);
	int i = 0, j = 0;
	int max = 0;
	int count = 0;
	while (i < numsSize && j < numsSize) {
		if (nums[j] - nums[i] == 1) {
			count = j - i + 1;
			j++;
		}
		else{
			if (count > max) {
				max = count;
			}
			if (nums[j] - nums[i] == 2)
				i += 1;
			else if(nums[j] - nums[i] == 0){
				j++;
			}
			else {
				i = j;
			}
			count = 0;
		}
	}
	if (count > max) {
		max = count;
	}
	return max;
}

//方法二：快排——三点取中
int findLHS2(int* nums, int numsSize) {
	srand(time(NULL));
	QuickSort(nums, 0, numsSize - 1);
	int i = 0, j = 0;
	int max = 0;
	int count = 0;
	while (i < numsSize && j < numsSize) {
		if (nums[j] - nums[i] == 1) {
			count = j - i + 1;
			j++;
		}
		else {
			if (count > max) {
				max = count;
			}
			if (nums[j] - nums[i] == 2)
				i += 1;
			else if (nums[j] - nums[i] == 0) {
				j++;
			}
			else {
				i = j;
			}
			count = 0;
		}
	}
	if (count > max) {
		max = count;
	}
	return max;
}

//方法三：希尔排序
int findLHS3(int* nums, int numsSize) {
	ShellSort(nums, numsSize);
	int i = 0, j = 0;
	int max = 0;
	int count = 0;
	while (i < numsSize && j < numsSize) {
		if (nums[j] - nums[i] == 1) {
			count = j - i + 1;
			j++;
		}
		else {
			if (count > max) {
				max = count;
			}
			if (nums[j] - nums[i] == 2)
				i += 1;
			else if (nums[j] - nums[i] == 0) {
				j++;
			}
			else {
				i = j;
			}
			count = 0;
		}
	}
	if (count > max) {
		max = count;
	}
	return max;
}

//方法四：归并排序——递归实现与非递归实先
int findLHS(int* nums, int numsSize) {
	int* tmp = (int*)calloc(numsSize, sizeof(int));
	assert(tmp);
	//MergeSort(nums, 0, numsSize - 1, tmp);
	MergeSort_iterate(nums, 0, numsSize - 1, tmp);
	free(tmp);
	int i = 0, j = 0;
	int max = 0;
	int count = 0;
	while (i < numsSize && j < numsSize) {
		if (nums[j] - nums[i] == 1) {
			count = j - i + 1;
			j++;
		}
		else {
			if (count > max) {
				max = count;
			}
			if (nums[j] - nums[i] == 2)
				i += 1;
			else if (nums[j] - nums[i] == 0) {
				j++;
			}
			else {
				i = j;
			}
			count = 0;
		}
	}
	if (count > max) {
		max = count;
	}
	return max;
}

void test3() {
	//ElemType nums[10] = { 1,2,2,3,4,5,1,1,1,1 };
	ElemType nums[10] = { 1,3,5,7,9,11,13,15,17 };
	int n = 9;
	printf("%d\n", findLHS(nums, n));
}