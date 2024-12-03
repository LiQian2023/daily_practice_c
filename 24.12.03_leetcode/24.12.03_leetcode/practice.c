#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//2024.12.03力扣网刷题
//检查棋盘方格颜色是否相同——数学、字符串——简单
//给你两个字符串 coordinate1 和 coordinate2，代表 8 x 8 国际象棋棋盘上的两个方格的坐标。
//以下是棋盘的参考图。
//如果这两个方格颜色相同，返回 true，否则返回 false。
//坐标总是表示有效的棋盘方格。坐标的格式总是先字母（表示列），再数字（表示行）。
//示例 1：
//输入： coordinate1 = "a1", coordinate2 = "c3"
//输出： true
//解释：
//两个方格均为黑色。
//示例 2：
//输入： coordinate1 = "a1", coordinate2 = "h3"
//输出： false
//解释：
//方格 "a1" 是黑色，而 "h3" 是白色。
//提示：
//coordinate1.length == coordinate2.length == 2
//'a' <= coordinate1[0], coordinate2[0] <= 'h'
//'1' <= coordinate1[1], coordinate2[1] <= '8'

int JudgeColor(char* str) {
	if (((str[0] - 'a') % 2 == 0 && (str[1] - '0') % 2 == 1) || ((str[0] - 'a') % 2 == 1 && (str[1] - '0') % 2 == 0))
		return 1;
	return 0;
}
bool checkTwoChessboards(char* coordinate1, char* coordinate2) {
	return JudgeColor(coordinate1) == JudgeColor(coordinate2);
}