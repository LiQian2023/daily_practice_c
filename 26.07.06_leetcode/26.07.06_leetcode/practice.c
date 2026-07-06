#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.07.06力扣网刷题
//1288. 删除被覆盖区间——高级工程师、数组、排序、第15场双周赛——中等
//给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
//只有当 c <= a 且 b <= d 时，我们才认为区间[a, b) 被区间[c, d) 覆盖。
//在完成所有删除操作后，请你返回列表中剩余区间的数目。
//示例：
//输入：intervals = [[1, 4], [3, 6], [2, 8]]
//输出：2
//解释：区间[3, 6] 被区间[2, 8] 覆盖，所以它被删除了。
//提示：​​​​​​
//1 <= intervals.length <= 1000
//0 <= intervals[i][0] < intervals[i][1] <= 10 ^ 5
//对于所有的 i != j：intervals[i] != intervals[j]
int cmp(const void* p1, const void* p2) {
	const int* a = *(int* const*)p1;
	const int* b = *(int* const*)p2;
	if (a[0] != b[0]) {
		return a[0] - b[0];
	}
	return b[1] - a[1];
}
void Print(int** nums, int len) {
	for (int i = 0; i < len; i++) {
		printf("[%d, %d]\t", nums[i][0], nums[i][1]);
	}
	printf("\n");
}
int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
	qsort(intervals, intervalsSize, sizeof(int*), cmp);
	int l = 0, r = 1;
	while (r < intervalsSize) {
		if (intervals[l][1] < intervals[r][1]) {
			l += 1;
			intervals[l][0] = intervals[r][0];
			intervals[l][1] = intervals[r][1];
		}
		r += 1;
	}
	return l + 1;
}