#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.12.06力扣网刷题
//可以被一步捕获的棋子数——数组、矩阵、模拟——简单
//给定一个 8 x 8 的棋盘，只有一个 白色的车，用字符 'R' 表示。棋盘上还可能存在白色的象 'B' 以及黑色的卒 'p'。空方块用字符 '.' 表示。
//车可以按水平或竖直方向（上，下，左，右）移动任意个方格直到它遇到另一个棋子或棋盘的边界。如果它能够在一次移动中移动到棋子的方格，则能够 吃掉 棋子。
//注意：车不能穿过其它棋子，比如象和卒。这意味着如果有其它棋子挡住了路径，车就不能够吃掉棋子。
//返回白车 攻击 范围内 兵的数量。
//示例 1：
//输入： [[".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", "p", ".", ".", ".", "."], [".", ".", ".", "R", ".", ".", ".", "p"], [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", "p", ".", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."]]
//输出：3
//解释：
//在本例中，车能够吃掉所有的卒。
//示例 2：
//输入： [[".", ".", ".", ".", ".", ".", ".", "."], [".", "p", "p", "p", "p", "p", ".", "."], [".", "p", "p", "B", "p", "p", ".", "."], [".", "p", "B", "R", "B", "p", ".", "."], [".", "p", "p", "B", "p", "p", ".", "."], [".", "p", "p", "p", "p", "p", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."]]
//输出：0
//解释：
//象阻止了车吃掉任何卒。
//示例 3：
//输入： [[".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", "p", ".", ".", ".", "."], [".", ".", ".", "p", ".", ".", ".", "."], ["p", "p", ".", "R", ".", "p", "B", "."], [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", "B", ".", ".", ".", "."], [".", ".", ".", "p", ".", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."]]
//输出：3
//解释：
//车可以吃掉位置 b5，d6 和 f5 的卒。
//提示：
//board.length == 8
//board[i].length == 8
//board[i][j] 可以是 'R'，'.'，'B' 或 'p'
//只有一个格子上存在 board[i][j] == 'R'

void Index(char** board, int boardSize, int* boardColSize, int* row, int* col) {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardColSize[i]; j++) {
			if (board[i][j] == 'R') {
				*row = i;
				*col = j;
				return;
			}
		}
	}
}
void Search_ans(char** board, int boardSize, int* boardColSize, int row, int col, int flag, int* ans) {
	for (int i = row; i >= 0 && i < boardSize; i += flag) {
		if (board[i][col] == 'p') {
			*ans += 1;
			break;
		}
		else if (board[i][col] == 'B') {
			break;
		}
	}
	for (int j = col; j >= 0 && j < boardColSize[row]; j += flag) {
		if (board[row][j] == 'p') {
			*ans += 1;
			break;
		}
		else if (board[row][j] == 'B') {
			break;
		}
	}
}
int numRookCaptures(char** board, int boardSize, int* boardColSize) {
	int row = 0, col = 0;
	Index(board, boardSize, boardColSize, &row, &col);
	int ans = 0;
	Search_ans(board, boardSize, boardColSize, row, col, -1, &ans);
	Search_ans(board, boardSize, boardColSize, row, col, +1, &ans);
	return ans;
}