#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.11.23力扣网刷题
//求出胜利玩家的数目——数组、哈希表、计数——简单
//给你一个整数 n ，表示在一个游戏中的玩家数目。同时给你一个二维整数数组 pick ，其中 pick[i] = [xi, yi] 表示玩家 xi 获得了一个颜色为 yi 的球。
//如果玩家 i 获得的球中任何一种颜色球的数目 严格大于 i 个，那么我们说玩家 i 是胜利玩家。换句话说：
//如果玩家 0 获得了任何的球，那么玩家 0 是胜利玩家。
//如果玩家 1 获得了至少 2 个相同颜色的球，那么玩家 1 是胜利玩家。
//...
//如果玩家 i 获得了至少 i + 1 个相同颜色的球，那么玩家 i 是胜利玩家。
//请你返回游戏中 胜利玩家 的数目。
//注意，可能有多个玩家是胜利玩家。
//示例 1：
//输入：n = 4, pick = [[0, 0], [1, 0], [1, 0], [2, 1], [2, 1], [2, 0]]
//输出：2
//解释：
//玩家 0 和玩家 1 是胜利玩家，玩家 2 和玩家 3 不是胜利玩家。
//示例 2：
//输入：n = 5, pick = [[1, 1], [1, 2], [1, 3], [1, 4]]
//输出：0
//解释：
//没有胜利玩家。
//示例 3：
//输入：n = 5, pick = [[1, 1], [2, 4], [2, 4], [2, 4]]
//输出：1
//解释：
//玩家 2 是胜利玩家，因为玩家 2 获得了 3 个颜色为 4 的球。
//提示：
//2 <= n <= 10
//1 <= pick.length <= 100
//pick[i].length == 2
//0 <= xi <= n - 1
//0 <= yi <= 10
#define Ball 11
typedef struct Player {
	int key;
	int* value;
}Player;
void Init(Player** p, int len) {
	assert(p);
	for (int i = 0; i < len; i++) {
		(*p)[i].key = -1;
		(*p)[i].value = (int*)calloc(Ball, sizeof(int));
		assert((*p)[i].value);
		for (int j = 0; j < Ball; j++) {
			(*p)[i].value[j] = 0;
		}
	}
}
void Destroy(Player** p, int len) {
	assert(p);
	for (int i = 0; i < len; i++) {
		free((*p)[i].value);
	}
	free(*p);
}
void Print(Player* p, int len) {
	for (int i = 0; i < len; i++) {
		printf("p[%d].key = %d\n", i, p[i].key);
		for (int j = 0; j < Ball; j++) {
			printf("p[%d].value[%d] = %d ", i, j, p[i].value[j]);
		}
	}
}
int winningPlayerCount(int n, int** pick, int pickSize, int* pickColSize) {
	Player* players = (Player*)calloc(n, sizeof(Player));
	assert(players);
	Init(&players, n);
	for (int i = 0; i < pickSize; i++) {
		int player_key = pick[i][0];
		int ball_key = pick[i][1];
		if (players[player_key].key == -1) {
			players[player_key].key = pick[i][0];
		}
		players[player_key].value[ball_key] += 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < Ball; j++) {
			if (players[i].key != -1 && players[i].value[j] > players[i].key) {
				ans += 1;
				break;
			}
		}
	}
	Destroy(&players, n);
	return ans;
}