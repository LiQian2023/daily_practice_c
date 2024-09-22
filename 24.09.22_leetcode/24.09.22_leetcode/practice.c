#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.09.22力扣网刷题
//找到小镇的法官——图、数组、哈希表——简单
//小镇里有 n 个人，按从 1 到 n 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。
//如果小镇法官真的存在，那么：
//小镇法官不会信任任何人。
//每个人（除了小镇法官）都信任这位小镇法官。
//只有一个人同时满足属性 1 和属性 2 。
//给你一个数组 trust ，其中 trust[i] = [ai, bi] 表示编号为 ai 的人信任编号为 bi 的人。
//如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 - 1 。
//示例 1：
//输入：n = 2, trust = [[1, 2]]
//输出：2
//示例 2：
//输入：n = 3, trust = [[1, 3], [2, 3]]
//输出：3
//示例 3：
//输入：n = 3, trust = [[1, 3], [2, 3], [3, 1]]
//输出： - 1
//提示：
//1 <= n <= 1000
//0 <= trust.length <= 104
//trust[i].length == 2
//trust 中的所有trust[i] = [ai, bi] 互不相同
//ai != bi
//1 <= ai, bi <= n

//方法一：暴力求解
int cmp(const void** p1, const void** p2) {
	//if ((*(int**)p1)[0] == (*(int**)p2)[0])
		return (*(int**)p1)[1] - (*(int**)p2)[1];
	//return (*(int**)p1)[0] - (*(int**)p2)[0];
}

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
	if (trustSize == 0) {
		if (n == 1)
			return 1;
		return -1;
	}
	qsort(trust, trustSize, sizeof(int*), cmp);
	int ans = -1;
	int i = 0, j = 0;
	while (i < trustSize) {
		int count = 1;
		//记录平民人数
		for (int z = i; z + 1 < trustSize && trust[z][1] == trust[z + 1][1]; z++) {
			count += 1;
			j += 1;
		}
		bool flag = true;
		if (count == n - 1) {
			//判断信任对象
			int key = trust[i][1];
			for (int z = 0; z < trustSize; z++) {
				if (trust[z][0] == key) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans = trust[i][1];
				break;
			}
		}
		if (count == 1) {
			j += 1;
		}
		i = j;
	}
	return ans;
}


void test() {
	int a1[2] = { 1,3 };
	int a2[2] = { 1,4 };
	int a3[2] = { 2,3 };
	int a4[2] = { 2,4 };
	int a5[2] = { 4,3 };
	int a6[2] = { 3,1 };
	int* arr[5] = { a1,a3,a2,a4,a5 };
	int col[5] = { 2,2,2,2,2 };
	int n = 4;
	printf("%d\n", findJudge(n, arr, 5, col));
}

int main() {
	test();
	return 0;
}