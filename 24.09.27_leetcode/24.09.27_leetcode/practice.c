#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//2024.09.27力扣网刷题
//合并区间——数组、排序——中等
//以数组
//intervals表示若干个区间的集合，其中单个区间为intervals[i] = [starti, endi]。
//请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
//示例
//1：
//输入：intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
//输出： [[1, 6], [8, 10], [15, 18]]
//解释：区间[1, 3]和[2, 6]重叠, 将它们合并为[1, 6].
//示例
//2：
//输入：intervals = [[1, 4], [4, 5]]
//输出： [[1, 5]]
//解释：区间[1, 4]和[4, 5]可被视为重叠区间。
//提示：
//1 <= intervals.length <= 10 ^ 4
//intervals[i].length == 2
//0 <= starti <= endi <= 10 ^ 4


int cmp(const void** p1, const void** p2) {
	if ((*(int**)p1)[0] == (*(int**)p2)[0])
		return (*(int**)p1)[1] - (*(int**)p2)[1];
	return (*(int**)p1)[0] - (*(int**)p2)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
	qsort(intervals, intervalsSize, sizeof(int*), cmp);
	for (int i = 0; i < intervalsSize - 1; i++) {
		//找起点
		if (intervals[i][0] <= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][0]) {
			intervals[i + 1][0] = intervals[i][0];
			intervals[i][0] = -1;
			//找终点
			if (intervals[i][1] > intervals[i + 1][1]) {
				intervals[i + 1][1] = intervals[i][1];
			}
			intervals[i][1] = -1;
		}

	}
	int** ans = (int**)calloc(intervalsSize, sizeof(int*));
	if (ans == NULL) {
		perror("calloc");
		return NULL;
	}
	*returnColumnSizes = (int*)calloc(intervalsSize, sizeof(int));
	if (*returnColumnSizes == NULL) {
		perror("calloc");
		return NULL;
	}
	*returnSize = 0;
	for (int i = 0; i < intervalsSize; i++) {
		if (intervals[i][0] != -1) {
			ans[*returnSize] = (int*)calloc(2, sizeof(int));
			if (ans[*returnSize] == NULL) {
				perror("calloc");
				return ans;
			}
			ans[*returnSize][0] = intervals[i][0];
			ans[*returnSize][1] = intervals[i][1];
			(*returnColumnSizes)[*returnSize] = 2;
			*returnSize += 1;
		}
	}
	return ans;
}