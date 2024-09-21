#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.09.20力扣网刷题
//三数之和——数组、双指针、排序——中等
//给你一个整数数组 nums ，判断是否存在三元组[nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
//同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
//示例 1：
//输入：nums = [-1, 0, 1, 2, -1, -4]
//输出： [[-1, -1, 2], [-1, 0, 1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是[-1, 0, 1] 和[-1, -1, 2] 。
//注意，输出的顺序和三元组的顺序并不重要。
//示例 2：
//输入：nums = [0, 1, 1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
//示例 3：
//输入：nums = [0, 0, 0]
//输出： [[0, 0, 0]]
//解释：唯一可能的三元组和为 0 。
//提示：
//3 <= nums.length <= 3000
//- 10^5 <= nums[i] <= 10^5


int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
//方法一：双指针
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	int base = numsSize / 2;
	int** ans = (int**)calloc(base, sizeof(int*));
	assert(ans);
	*returnSize = 0;
	*returnColumnSizes = (int*)calloc(base, sizeof(int));
	assert(*returnColumnSizes);
	for (int i = 0; i < numsSize; i++) {
		if (i && nums[i] == nums[i - 1])
			continue;
		int l = i + 1, r = numsSize - 1;
		int key = nums[i];
		while (l < r) {
			if (nums[l] + nums[r] + key < 0)
				l++;
			else if (nums[l] + nums[r] + key > 0)
				r--;
			else {
				(*returnColumnSizes)[*returnSize] = 3;
				ans[*returnSize] = (int*)calloc(3, sizeof(int));
				assert(ans[*returnSize]);
				ans[*returnSize][0] = key;
				ans[*returnSize][1] = nums[l];
				ans[*returnSize][2] = nums[r];
				l++, r--;
				while (l && l < r && nums[l] == nums[l - 1]) 
					l += 1;
				while (r > l && nums[r] == nums[r + 1])
					r -= 1;
				*returnSize += 1;
				if (*returnSize == base) {
					base += 100;
					int** tmp1 = (int**)realloc(ans, base * sizeof(int*));
					assert(tmp1);
					ans = tmp1;
					int* tmp2 = (int*)realloc(*returnColumnSizes, base * sizeof(int));
					assert(tmp2);
					*returnColumnSizes = tmp2;
				}
			}
		}
	}
	return ans;
}

#if 0
int Binary_Search(int* nums, int l, int r, int key) {
	while (l <= r) {
		int mid = (r - l) / 2 + l;
		if (nums[mid] > key)
			r = mid - 1;
		else if (nums[mid] < key)
			l = mid + 1;
		else
			return mid;
	}
	return -1;
}
void Increase(int** ans,int* len,int a,int b,int c ) {
	(*len) += 1;
	int** tmp = (int**)realloc(ans, (*len) * sizeof(int*));
	if (!tmp) {
		perror("realloc");
		return;
	}
	ans = tmp;
	ans[(*len) - 1] = (int*)calloc(3, sizeof(int));
	assert(ans[(*len) - 1]);
	ans[(*len) - 1][0] = a;
	ans[(*len) - 1][1] = b;
	ans[(*len) - 1][2] = c;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	qsort(nums, numsSize, sizeof(int), cmp);
	//负数数组
	int nag[3000] = { 0 };
	int n = 0;
	//整数数组
	int pos[3000] = { 0 };
	int p = 0;
	//零
	int zero[3000] = { 0 };
	int z = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < 0)
			nag[n++] = nums[i];
		else if (nums[i] > 0)
			pos[p++] = nums[i];
		else
			zero[z++] = nums[i];
	}
	int** ans = NULL;
	int len = 0;
	//处理全负数与全正数
	if (n == numsSize || p == numsSize) {
		*returnSize = 0;
		*returnColumnSizes = NULL;
	}
	//处理全0
	else if (z == numsSize) {
		*returnSize = 1;
		*returnColumnSizes = (int*)calloc(1, sizeof(int));
		assert(*returnColumnSizes);
		(*returnColumnSizes)[0] = 3;
		ans = (int**)calloc(1, sizeof(int*));
		assert(ans);
		ans[0] = (int*)calloc(3, sizeof(int));
		assert(ans[0]);
		ans[0][0] = ans[0][1] = ans[0][2] = 0;
	}
	else {
		int a = 0, b = 0, c = 0;
		//扫描负数
		for (a = 0; a < n; a++) {
			//去重
			if (a && nag[a] == nag[a - 1])
				continue;
			//扫描正数
			for (b = 0; b < p; b++) {
				//去重
				if (b && pos[b] == pos[b - 1])
					continue;
				int key = 0 - (nag[a] + pos[b]);
				int ret = 0;
				//关键字小于0
				if (key < 0) {
					ret = Binary_Search(nag, a + 1, n, key);
					if (ret == -1)
						continue;
					Increase(ans, &len, nag[a], nag[ret], pos[b]);
				}
				//关键字大于0
				else if (key > 0) {
					ret = Binary_Search(pos, b + 1, p, key);
					if (ret == -1)
						continue;
					Increase(ans, &len, nag[a], pos[b], pos[ret]);
				}
				//关键字等于0
				else {
					//无0元素
					if (z == 0) {
						continue;
					}
					Increase(ans, &len, nag[a], 0, pos[b]);
				}
			}
		}
		//存在3个0时
		if (z >= 3) {
			Increase(ans, &len, 0, 0, 0);
		}
		*returnSize = len;
		*returnColumnSizes = (int*)calloc(len, sizeof(int));
		assert(*returnColumnSizes);
		for (int i = 0; i < len; i++) {
			(*returnColumnSizes)[i] = 3;
		}
	}
	return ans;
}
#endif
