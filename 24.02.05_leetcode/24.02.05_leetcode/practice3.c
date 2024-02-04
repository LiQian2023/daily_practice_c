#define _CRT_SECURE_NO_WARNINGS 1

#include "pratice.h"

//2024.02.05力扣网刷题
//三角形的最大周长——贪心、数组、数学、排序——简单
//给定由一些正数（代表长度）组成的数组 nums ，返回 由其中三个长度组成的、面积不为零的三角形的最大周长 。如果不能形成任何面积不为零的三角形，返回 0。
//示例 1：
//输入：nums = [2, 1, 2]
//输出：5
//解释：你可以用三个边长组成一个三角形 : 1 2 2。
//示例 2：
//输入：nums = [1, 2, 1, 10]
//输出：0
//解释：
//你不能用边长 1, 1, 2 来组成三角形。
//不能用边长 1, 1, 10 来构成三角形。
//不能用边长 1、2 和 10 来构成三角形。
//因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。
//提示：
//3 <= nums.length <= 10^4
//1 <= nums[i] <= 10^6

int cmp_int(const void* p1, const void* p2) {
	return *(int*)p2 - *(int*)p1;
}
bool Istriangle(int x, int y, int z) {
	if (x + y > z && x + z > y && y + z > x)
		return true;
	return false;
}
int largestPerimeter(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp_int);
	int sum = 0;
	for (int i = 0; i < numsSize - 2; i++) {
		if (Istriangle(nums[i], nums[i + 1], nums[i + 2])){
			sum=nums[i]+nums[i+1]+nums[i+2];
			break;
		}
	}
	return sum;
}

void test3() {
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int* p = (int*)calloc(n, sizeof(int));
		assert(p);
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i]);
		int ret = largestPerimeter(p, n);
		printf("%d\n", ret);
		free(p);
	}
}