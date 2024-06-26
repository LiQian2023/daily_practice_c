#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
//2024.06.26力扣网刷题
//最长公共前缀——字典树、字符串——简单
//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。
//示例 1：
//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//示例 2：
//输入：strs = ["dog", "racecar", "car"]
//输出：""
//解释：输入不存在公共前缀。
//提示：
//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] 仅由小写英文字母组成


char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 1)
		return strs[0];
	//找到最短字符串
	int min = strlen(strs[0]);
	int n = 0;
	for (int i = 0; i < strsSize; i++) {
		if (min > strlen(strs[i])) {
			min = strlen(strs[i]);
			n = i;
		}
	}
	if (!min)
		return strs[n];
	//记录最短字符串前缀
	char* ans = (char*)calloc(min + 1, sizeof(char));
	assert(ans);
	for (int i = 0; i < min - 1; i++) {
		ans[i] = strs[n][i];
	}
	//字符串匹配
	int len = min - 1;
	for (int i = 0; i < strsSize; i++) {
		int tmp = 0;
		for (int j = 0; j < len; j++) {
			if (strs[i][j] != ans[j]) {
				break;
			}
			tmp++;
		}
		if (len > tmp)
			len = tmp;
	}
	ans[len] = '\0';
	return ans;
}

void test() {

}

#if 0
//特别的排列——位运算、数组、动态规划、状态压缩——中等
//给你一个下标从 0 开始的整数数组 nums ，它包含 n 个 互不相同 的正整数。如果 nums 的一个排列满足以下条件，我们称它是一个特别的排列：
//对于 0 <= i < n - 1 的下标 i ，要么 nums[i] % nums[i + 1] == 0 ，要么 nums[i + 1] % nums[i] == 0 。
//	请你返回特别排列的总数目，由于答案可能很大，请将它对 109 + 7 取余 后返回。
//	示例 1：
//	输入：nums = [2, 3, 6]
//	输出：2
//	解释：[3, 6, 2] 和[2, 6, 3] 是 nums 两个特别的排列。
//	示例 2：
//	输入：nums = [1, 4, 3]
//	输出：2
//	解释：[3, 1, 4] 和[4, 1, 3] 是 nums 两个特别的排列。
//	提示：
//	2 <= nums.length <= 1^4
//	1 <= nums[i] <= 10^9

int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}

int specialPerm(int* nums, int numsSize) {
	int count = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
				count++;
		}
	}
	return count % (1000000000 + 7);
}
#endif