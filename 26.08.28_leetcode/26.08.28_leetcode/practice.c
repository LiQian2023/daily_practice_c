#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//2026.08.28力扣网刷题
//3996. 偶数次骑士移动——中级工程师、数组、数学、第511场周赛——简单
//给你两个整数数组 start 和 target，每个数组的形式均为[x, y]，表示标准 8 x 8 国际象棋棋盘上的一个格子。
//如果骑士可以用 偶数 次移动从 start 到达 target，则返回 true；否则返回 false。
//注意：骑士的一次合法移动是：沿一个方向移动两格，再沿与其垂直的方向移动一格。下图展示了骑士从一个格子出发时所有 8 种可能的移动方式。
//示例 1：
//输入： start = [1, 1], target = [2, 2]
//输出： true
//解释：
//一种可行的移动序列为(1, 1) -> (3, 2) -> (2, 4) -> (4, 3) -> (2, 2)。
//骑士经过 4 次移动到达目标位置，4 是偶数。因此答案为 true。
//示例 2：
//输入： start = [4, 5], target = [6, 6]
//输出： false
//解释：
//骑士无法用偶数次移动从 start = [4, 5] 到达 target = [6, 6]。因此答案为 false。
//提示：
//start.length == target.length == 2
//0 <= start[i], target[i] <= 7

bool DFS(bool** visited, int x1, int y1, int x2, int y2, int step) {
	if (x1 < 0 || y1 < 0 || x1 >= 8 || y1 >= 8) {
		return false;
	}
	if (x1 == x2 && y1 == y2) {
		return step % 2 == 0;
	}
	if (visited[x1][y1]) {
		return false;
	}
	visited[x1][y1] = true;
	bool flag1 = DFS(visited, x1 + 2, y1 + 1, x2, y2, step + 1);
	bool flag2 = DFS(visited, x1 + 2, y1 - 1, x2, y2, step + 1);
	bool flag3 = DFS(visited, x1 - 2, y1 + 1, x2, y2, step + 1);
	bool flag4 = DFS(visited, x1 - 2, y1 - 1, x2, y2, step + 1);
	bool flag5 = DFS(visited, x1 + 1, y1 + 2, x2, y2, step + 1);
	bool flag6 = DFS(visited, x1 - 1, y1 + 2, x2, y2, step + 1);
	bool flag7 = DFS(visited, x1 + 1, y1 - 2, x2, y2, step + 1);
	bool flag8 = DFS(visited, x1 - 1, y1 - 2, x2, y2, step + 1);
	return flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8;
}
bool canReach1(int* start, int startSize, int* target, int targetSize) {
	bool** visited = (bool**)calloc(8, sizeof(bool*));
	assert(visited);
	for (int i = 0; i < 8; i++) {
		visited[i] = (bool*)calloc(8, sizeof(bool));
		assert(visited[i]);
	}
	int step = 0;
	bool ans = DFS(visited, start[0], start[1], target[0], target[1], step);
	for (int i = 0; i < 8; i++) {
		free(visited[i]);
		visited[i] = NULL;
	}
	free(visited);
	visited = NULL;
	return ans;
}
bool canReach(int* start, int startSize, int* target, int targetSize) {
	return (start[0] + start[1]) % 2 == (target[0] + target[1]) % 2;
}