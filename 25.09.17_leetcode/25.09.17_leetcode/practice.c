#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//2025.09.17力扣网刷题
//面试题 10.05.稀疏数组搜索——数组、字符串、二分查找——简单
//稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。
//示例 1：
//输入：words = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""], s = "ta"
//输出： - 1
//说明：不存在返回 - 1。
//示例 2：
//输入：words = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""], s = "ball"
//输出：4
//提示 :
//words的长度在[1, 1000000]之间

int index(char** list, char* s, int len) {
	for (int i = 0; i < len; i++) {
		if (strcmp(list[i], s) == 0) {
			return i;
		}
	}
	return -1;
}
int findString(char** words, int wordsSize, char* s) {
	return index(words, s, wordsSize);
}