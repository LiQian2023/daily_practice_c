#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.19力扣网刷题
//无人机方阵——数组、哈希表、计数、矩阵——简单
//在 「力扣挑战赛」 开幕式的压轴节目 「无人机方阵」中，每一架无人机展示一种灯光颜色。 无人机方阵通过两种操作进行颜色图案变换：
//调整无人机的位置布局
//切换无人机展示的灯光颜色
//给定两个大小均为 N * M 的二维数组 source 和 target 表示无人机方阵表演的两种颜色图案，由于无人机切换灯光颜色的耗能很大，请返回从 source 到 target 最少需要多少架无人机切换灯光颜色。
//注意： 调整无人机的位置布局时无人机的位置可以随意变动。
//示例 1：
//输入：source = [[1, 3], [5, 4]], target = [[3, 1], [6, 5]]
//输出：1
//解释： 最佳方案为 将[0, 1] 处的无人机移动至[0, 0] 处； 
//将[0, 0] 处的无人机移动至[0, 1] 处； 将[1, 0] 处的无人机移动至[1, 1] 处； 
//将[1, 1] 处的无人机移动至[1, 0] 处，其灯光颜色切换为颜色编号为 6 的灯光； 
//因此从source 到 target 所需要的最少灯光切换次数为 1。8819ccdd664e91c78cde3bba3c701986.gif
//示例 2：
//输入：source = [[1, 2, 3], [3, 4, 5]], target = [[1, 3, 5], [2, 3, 4]]
//输出：0 解释： 仅需调整无人机的位置布局，便可完成图案切换。因此不需要无人机切换颜色
//提示： 
//n == source.length == target.length 
//m == source[i].length == target[i].length 
//1 <= n, m <= 100 
//1 <= source[i][j], target[i][j] <= 10 ^ 4

int minimumSwitchingTimes(int** source, int sourceSize, int* sourceColSize, int** target, int targetSize, int* targetColSize) {
	int n = sourceSize;
	int* m = (int*)calloc(n, sizeof(int));
	assert(m);
	for (int i = 0; i < n; i++) {
		m[i] = sourceColSize[i];
	}
	int* hash = (int*)calloc(10001, sizeof(int));
	assert(hash);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m[i]; j++) {
			int key1 = source[i][j];
			int key2 = target[i][j];
			hash[key1] += 1;
			hash[key2] -= 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 10001; i++) {
		if (hash[i] > 0) {
			ans += hash[i];
		}
	}
	free(m);
	m = NULL;
	free(hash);
	hash = NULL;
	return ans;
}