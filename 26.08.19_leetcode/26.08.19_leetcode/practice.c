#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2026.08.19力扣网刷题
//1386. 安排电影院座位——高级工程师、贪心、位运算、数组、哈希表、第22场双周赛——中等
//如上图所示，电影院的观影厅中有 n 行座位，行编号从 1 到 n ，且每一行内总共有 10 个座位，列编号从 1 到 10 。
//给定一个二维数组 reservedSeats ，其中 reservedSeats[i] = [rowi, seati] 表示第 rowi 行的座位 seati 已经被预定。
//四人小组必须被安排在同一排的四个座位上。该小组可以坐在以下座位块之一：
//座位 2, 3, 4, 5
//座位 4, 5, 6, 7
//座位 6, 7, 8, 9
//只有当该块中的所有座位都 没有 被预订时，才能使用该块。每个座位 最多 只能分配给一个小组。
//返回一个整数，表示可以分配的 最大 四人小组数量。
//示例 1：
//输入：n = 3, reservedSeats = [[1, 2], [1, 3], [1, 8], [2, 6], [3, 1], [3, 10]]
//输出：4
//解释：上图所示是最优的安排方案，总共可以安排 4 个家庭。蓝色的叉表示被预约的座位，橙色的连续座位表示一个 4 人家庭。
//示例 2：
//输入：n = 2, reservedSeats = [[2, 1], [1, 8], [2, 6]]
//输出：2
//示例 3：
//输入：n = 4, reservedSeats = [[4, 3], [1, 4], [4, 6], [1, 7]]
//输出：4
//提示：
//1 <= n <= 10^9
//1 <= reservedSeats.length <= min(10 * n, 10^4)
//reservedSeats[i] == [rowi, seati]
//1 <= rowi <= n
//1 <= seati <= 10
//所有 reservedSeats[i] 都是互不相同的。


// 方法一：暴力哈希
int maxNumberOfFamilies1(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
	int ans = 0;
	int** hash = (int**)calloc(n, sizeof(int*));
	assert(hash);
	for (int i = 0; i < n; i++) {
		hash[i] = (int*)calloc(2, sizeof(int));
		assert(hash[i]);
		hash[i][0] = 2;
		hash[i][1] = 9;
	}
	for (int i = 0; i < reservedSeatsSize; i++) {
		int row = reservedSeats[i][0], col = reservedSeats[i][1];
		if (col >= 2 && col < 6 && col >= hash[row - 1][0]) {
			hash[row - 1][0] = col + 1;
		}
		else if (col >= 6 && col <= 9 && col <= hash[row - 1][1]) {
			hash[row - 1][1] = col - 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int l = hash[i][0], r = hash[i][1];
		if (l == 2) {
			ans += (r - l + 1) / 4;
		}
		else if (l > 2 && l <= 4) {
			ans += (r - 4 + 1) / 4;
		}
		else if (l > 4 && l <= 6) {
			if (r == 9) {
				ans += 1;
			}
		}
		free(hash[i]);
		hash[i] = NULL;
	}
	free(hash);
	return ans;
}

typedef struct Hash {
	int key;
	int val;
}Hash;
Hash* Create(int n) {
	Hash* h = (Hash*)calloc(n, sizeof(Hash));
	assert(h);
	for (int i = 0; i < n; i++) {
		h[i].key = -1;
	}
	return h;
}

int getKey(Hash* h, int len, int x) {
	int key = x % len;
	while (h[key].key != x && h[key].key != -1) {
		key = (key + 1) % len;
	}
	return key;
}
void Push(Hash* h, int len, int row, int col) {
	int key = getKey(h, len, row);
	h[key].key = row;
	h[key].val |= 1 << (col - 2);
}
void Destroy(Hash** h) {
	free(*h);
	*h = NULL;
}
int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
	Hash* h = Create(reservedSeatsSize);
	for (int i = 0; i < reservedSeatsSize; i++) {
		int row = reservedSeats[i][0], col = reservedSeats[i][1];
		if (col >= 2 && col <= 9) {
			Push(h, reservedSeatsSize, row, col);
		}
	}
	int left = 0x0F;
	int mid = 0x3C;
	int right = 0xF0;
	int ans = n * 2;
	for (int i = 0; i < reservedSeatsSize; i++) {
		if (h[i].key != -1) {
			int l = (left & h[i].val) == 0,
				m = (mid & h[i].val) == 0,
				r = (right & h[i].val) == 0;
			if (l || m || r) {
				ans -= 1;
			}
			else if(!l && !m && !r){
				ans -= 2;
			}
		}
	}
	Destroy(&h);
	return ans;
}
