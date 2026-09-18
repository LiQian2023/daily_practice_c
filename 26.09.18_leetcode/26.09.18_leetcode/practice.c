#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//2026.09.18力扣网刷题
//79. 单词搜索——深度优先搜索、数组、字符串、回溯、矩阵——中等
//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//示例 1：
//输入：board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']], word = "ABCCED"
//输出：true
//示例 2：
//输入：board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']], word = "SEE"
//输出：true
//示例 3：
//输入：board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']], word = "ABCB"
//输出：false
//提示：
//m == board.length
//n = board[i].length
//1 <= m, n <= 6
//1 <= word.length <= 15
//board 和 word 仅由大小写英文字母组成
//进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？

// 方法一：回溯
bool dfs1(char** board, int row, int* col, char* word, int x, int y, int z, bool** visited, int* move) {
	if (!word[z]) {
		return true;
	}
	if (x >= row || x < 0 || y >= col[x] || y < 0) {
		return false;
	}

	if (board[x][y] != word[z]) {
		return false;
	}
	if (visited[x][y]) {
		return false;
	}
	bool res = false;
	visited[x][y] = true;
	for (int x_ = 0, y_ = 1; y_ < 8; x_ += 2, y_ += 2) {
		res |= dfs1(board, row, col, word, x + move[x_], y + move[y_], z + 1, visited, move);
	}
	visited[x][y] = false;
	return res;
}

// 方法二：回溯 + 剪枝优化
bool dfs(char** board, int row, int* col, char* word, int x, int y, int z, bool** visited, int* move) {
	if (!word[z]) {
		return true;
	}
	if (x >= row || x < 0 || y >= col[x] || y < 0) {
		return false;
	}

	if (board[x][y] != word[z]) {
		return false;
	}
	if (visited[x][y]) {
		return false;
	}
	visited[x][y] = true;
	bool res = false;
	for (int x_ = 0, y_ = 1; !res && y_ < 8; x_ += 2, y_ += 2) {
		res = dfs(board, row, col, word, x + move[x_], y + move[y_], z + 1, visited, move);
	}
	visited[x][y] = false;
	return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
	bool** visited = (bool**)calloc(boardSize, sizeof(bool*));
	assert(visited);
	for (int i = 0; i < boardSize; i++) {
		visited[i] = (bool*)calloc(boardColSize[i], sizeof(bool));
		assert(visited[i]);
	}
	bool ans = false;
	int move[8] = { 0, 1, 0, -1, 1, 0, -1, 0 };
	for (int i = 0; !ans && i < boardSize; i++) {
		for (int j = 0; !ans && j < boardColSize[i]; j++) {
			if (board[i][j] == word[0]) {
				ans = dfs(board, boardSize, boardColSize, word, i, j, 0, visited, move);
			}
		}
	}
	for (int i = 0; i < boardSize; i++) {
		free(visited[i]);
	}
	free(visited);
	return ans;
}