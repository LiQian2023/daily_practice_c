#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//2024.09.15力扣网刷题
//与车相交的点——数组、哈希表、前缀和——简单
//给你一个下标从 0 开始的二维整数数组 nums 表示汽车停放在数轴上的坐标。
//对于任意下标 i，nums[i] = [starti, endi] ，其中 starti 是第 i 辆车的起点，endi 是第 i 辆车的终点。
//返回数轴上被车 任意部分 覆盖的整数点的数目。
//示例 1：
//输入：nums = [[3, 6], [1, 5], [4, 7]]
//输出：7
//解释：从 1 到 7 的所有点都至少与一辆车相交，因此答案为 7 。
//示例 2：
//输入：nums = [[1, 3], [5, 8]]
//输出：7
//解释：1、2、3、5、6、7、8 共计 7 个点满足至少与一辆车相交，因此答案为 7 。
//提示：
//1 <= nums.length <= 100
//nums[i].length == 2
//1 <= starti <= endi <= 100

//方法一：排序+合并区间+求和
int cmp(const void** p1, const void** p2) {
	if (((int**)p1)[0][0] == ((int**)p2)[0][0]) {
		return ((int**)p1)[0][1] - ((int**)p2)[0][1];
	}
	return ((int**)p1)[0][0] - ((int**)p2)[0][0];
}

int numberOfPoints(int** nums, int numsSize, int* numsColSize) {
	//排序
	qsort(nums, numsSize, sizeof(nums[0]), cmp);
	//合并区间
	for (int i = 1; i < numsSize; i++) {
		int start = nums[i][0], end = nums[i][1];
		if (start >= nums[i - 1][0] && start <= nums[i - 1][1]) {
			nums[i][0] = nums[i - 1][0];
			nums[i - 1][0] = 0;
			if (end < nums[i - 1][1]) {
				nums[i][1] = nums[i - 1][1];
			}
			nums[i - 1][1] = 0;
		}
		else if (start >= nums[i - 1][0] && start > nums[i - 1][1]) {
			continue;
		}
	}
	//求和
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i][0] == 0) {
			continue;
		}
		ans += nums[i][1] - nums[i][0] + 1;
	}
	return ans;
}
void test() {
	int a[2] = { 1,3 };
	int b[2] = { 6,7 };
	int c[2] = { 1,4 };
	int d[2] = { 6,8 };
	int* arr[4] = { a,b,c,d };
	int row = 4;
	int col[4] = { 2,2,2,2 };
	printf("%d\n", numberOfPoints(arr, row, col));
}

int main() {
	test();
	return 0;
}