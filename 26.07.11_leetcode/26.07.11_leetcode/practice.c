#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.07.11力扣网刷题
//2685. 统计完全连通分量的数量——资深工程师、深度优先搜索、广度优先搜索、并查集、图、第345场周赛——中等
//给你一个整数 n 。现有一个包含 n 个顶点的 无向 图，顶点按从 0 到 n - 1 编号。给你一个二维整数数组 edges 其中 edges[i] = [ai, bi] 表示顶点 ai 和 bi 之间存在一条 无向 边。
//返回图中 完全连通分量 的数量。
//如果在子图中任意两个顶点之间都存在路径，并且子图中没有任何一个顶点与子图外部的顶点共享边，则称其为 连通分量 。
//如果连通分量中每对节点之间都存在一条边，则称其为 完全连通分量 。
//示例 1：
//输入：n = 6, edges = [[0, 1], [0, 2], [1, 2], [3, 4]]
//输出：3
//解释：如上图所示，可以看到此图所有分量都是完全连通分量。
//示例 2：
//输入：n = 6, edges = [[0, 1], [0, 2], [1, 2], [3, 4], [3, 5]]
//输出：1
//解释：包含节点 0、1 和 2 的分量是完全连通分量，因为每对节点之间都存在一条边。
//包含节点 3 、4 和 5 的分量不是完全连通分量，因为节点 4 和 5 之间不存在边。
//因此，在图中完全连接分量的数量是 1 。
//提示：
//1 <= n <= 50
//0 <= edges.length <= n * (n - 1) / 2
//edges[i].length == 2
//0 <= ai, bi <= n - 1
//ai != bi
//不存在重复的边
typedef struct AMGraph {
	int** vertex;
	int edgeNum;
	int verNum;
}AMGraph;
AMGraph* Create(int n) {
	AMGraph* obj = (AMGraph*)calloc(1, sizeof(AMGraph));
	assert(obj);
	obj->verNum = n;
	obj->vertex = (int**)calloc(n, sizeof(int*));
	assert(obj->vertex);
	for (int i = 0; i < n; i++) {
		obj->vertex[i] = (int*)calloc(n, sizeof(int));
		assert(obj->vertex[i]);
	}
	return obj;
}
void Push(AMGraph* obj, int* edge) {
	int a = edge[0], b = edge[1];
	obj->vertex[a][b] += 1;
	obj->vertex[b][a] += 1;
}
void DFS(AMGraph* obj, int ver, bool* visited, int* verNum, int* edgeNum) {
	if (visited[ver]) {
		return;
	}
	visited[ver] = true;
	*verNum += 1;
	for (int i = 0; i < obj->verNum; i++) {
		if (obj->vertex[ver][i]) {
			*edgeNum += 1;
			DFS(obj, i, visited, verNum, edgeNum);
		}
	}
}
void Destroy(AMGraph** obj) {
	for (int i = 0; i < (*obj)->verNum; i++) {
		free((*obj)->vertex[i]);
		(*obj)->vertex[i] = NULL;
	}
	free((*obj)->vertex);
	(*obj)->vertex = NULL;
	free(*obj);
	*obj = NULL;
}
int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
	AMGraph* obj = Create(n);
	for (int i = 0; i < edgesSize; i++) {
		Push(obj, edges[i]);
	}
	int ans = 0;
	bool* visited = (bool*)calloc(n, sizeof(bool));
	assert(visited);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int verNum = 0, edgeNum = 0;
			DFS(obj, i, visited, &verNum, &edgeNum);
			if (edgeNum == verNum * (verNum - 1)) {
				ans += 1;
			}
		}
	}
	Destroy(&obj);
	free(visited);
	return ans;
}