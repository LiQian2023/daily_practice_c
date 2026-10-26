#include <stdio.h>
#include <stdlib.h>
//2026.10.26力扣网刷题
//4056. 统计相交区间对 I——中级工程师、第520场周赛——简单
//给你一个包含 n 个元素的二维整数数组 intervals，其中 intervals[i] = [starti, endi] 表示从 starti 到 endi 的 闭区间 。
//返回满足 0 <= i < j < n，且 intervals[i] 与 intervals[j] 相交 的下标对(i, j) 的数量。
//如果两个区间至少有一个公共点，则称它们 相交。仅共享一个端点的情况也视为相交。
//示例 1：
//输入： intervals = [[1, 2], [2, 3], [3, 4]]
//输出： 2
//解释：
//共有 2 对相交区间：
//区间[1, 2] 和[2, 3] 在点 2 处相交。
//区间[2, 3] 和[3, 4] 在点 3 处相交。
//示例 2：
//输入： intervals = [[1, 5], [2, 4], [3, 6]]
//输出： 3
//解释：
//共有 3 对相交区间：
//[1, 5] 和[2, 4] 的交集为[2, 4]。
//[1, 5] 和[3, 6] 的交集为[3, 5]。
//[2, 4] 和[3, 6] 的交集为[3, 4]。
//示例 3：
//输入： intervals = [[1, 2], [3, 4], [5, 6]]
//输出： 0
//解释：
//不存在相交的区间对。因此，答案为 0。
//提示：
//2 <= intervals.length <= 100
//intervals[i] == [starti, endi]
//0 <= starti <= endi <= 100

int countIntersectingIntervals1(int** intervals, int intervalsSize, int* intervalsColSize) {
	int ans = 0;
	for (int i = 0; i < intervalsSize; i++) {
		for (int j = i + 1; j < intervalsSize; j++) {
			int maxBegin = intervals[i][0] > intervals[j][0] ? intervals[i][0] : intervals[j][0];
			int minEnd = intervals[i][1] < intervals[j][1] ? intervals[i][1] : intervals[j][1];
			ans += (minEnd - maxBegin) >= 0;
		}
	}
	return ans;
}


int countIntersectingIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
	int starts[101] = { 0 }, ends[101] = { 0 };
	for (int i = 0; i < intervalsSize; i++) {
		starts[intervals[i][0]] += 1;
		ends[intervals[i][1]] += 1;
	}
	int active = 0, ans = 0;
	for (int i = 0; i < 101; i++) {
		ans += active * starts[i] + starts[i] * (starts[i] - 1) / 2;
		active += starts[i] - ends[i];
	}
	return ans;
}