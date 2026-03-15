#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.15力扣网刷题
//1791. 找出星型图的中心节点k——中级工程师、图、第232场周赛——简单
//有一个无向的 星型 图，由 n 个编号从 1 到 n 的节点组成。星型图有一个 中心 节点，并且恰有 n - 1 条边将中心节点与其他每个节点连接起来。
//给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示在节点 ui 和 vi 之间存在一条边。请你找出并返回 edges 所表示星型图的中心节点。
//示例 1：
//输入：edges = [[1, 2], [2, 3], [4, 2]]
//输出：2
//解释：如上图所示，节点 2 与其他每个节点都相连，所以节点 2 是中心节点。
//示例 2：
//输入：edges = [[1, 2], [5, 1], [1, 3], [1, 4]]
//输出：1
//提示：
//3 <= n <= 10^5
//edges.length == n - 1
//edges[i].length == 2
//1 <= ui, vi <= n
//ui != vi
//题目数据给出的 edges 表示一个有效的星型图

typedef struct Adjacency_Matrix {
	int* Vertex;
	int len_ver;
}AMGraph;

int findCenter1(int** edges, int edgesSize, int* edgesColSize) {
	AMGraph* g = (AMGraph*)calloc(1, sizeof(AMGraph));
	assert(g);
	g->len_ver = edgesSize + 1;
	g->Vertex = (int*)calloc(g->len_ver, sizeof(int));
	assert(g->Vertex);
	for (int i = 0; i < edgesSize; i++) {
		g->Vertex[edges[i][0] - 1] += 1;
		g->Vertex[edges[i][1] - 1] += 1;
	}
	int ans = -1;
	for (int i = 0; i < g->Vertex; i++) {
		if (g->Vertex[i] == edgesSize) {
			ans = i + 1;
			break;
		}
	}
	free(g->Vertex);
	g->Vertex = NULL;
	free(g);
	g = NULL;
	return ans;
}

int findCenter(int** edges, int edgesSize, int* edgesColSize) {
	if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
		return edges[0][0];
	}
	return edges[0][1];
}