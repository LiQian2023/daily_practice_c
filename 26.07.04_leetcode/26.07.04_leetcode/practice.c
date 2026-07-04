#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2026.07.04力扣网刷题
//2492. 两个城市间路径的最小分数——资深工程师、深度优先搜索、广度优先搜索、图、并查集、第322场周赛——中等
//给你一个正整数 n ，表示总共有 n 个城市，城市从 1 到 n 编号。给你一个二维数组 roads ，其中 roads[i] = [ai, bi, distancei] 表示城市 ai 和 bi 之间有一条 双向 道路，道路距离为 distancei 。城市构成的图不一定是连通的。
//两个城市之间一条路径的 分数 定义为这条路径中道路的 最小 距离。
//返回城市 1 和城市 n 之间的所有路径的 最小 分数。
//注意：
//一条路径指的是两个城市之间的道路序列。
//一条路径可以 多次 包含同一条道路，你也可以沿着路径多次到达城市 1 和城市 n 。
//测试数据保证城市 1 和城市n 之间 至少 有一条路径。
//示例 1：
//输入：n = 4, roads = [[1, 2, 9], [2, 3, 6], [2, 4, 5], [1, 4, 7]]
//输出：5
//解释：城市 1 到城市 4 的路径中，分数最小的一条为：1 -> 2 -> 4 。这条路径的分数是 min(9, 5) = 5 。
//不存在分数更小的路径。
//示例 2：
//输入：n = 4, roads = [[1, 2, 2], [1, 3, 4], [3, 4, 7]]
//输出：2
//解释：城市 1 到城市 4 分数最小的路径是：1 -> 2 -> 1 -> 3 -> 4 。这条路径的分数是 min(2, 2, 4, 7) = 2 。
//提示：
//2 <= n <= 10^5
//1 <= roads.length <= 10^5
//roads[i].length == 3
//1 <= ai, bi <= n
//ai != bi
//1 <= distancei <= 10^4
//不会有重复的边。
//城市 1 和城市 n 之间至少有一条路径。
typedef struct EdgeNode {
	int data;
	int info;
	struct EdgeNode* next;
}EdgeNode, * EdgeList;
typedef struct VerNode {
	bool visited;
	int data;
	int EdgeNum;
	EdgeList firstEdge;
}VerNode,*VerList;
typedef struct ALMGraph {
	VerList ver;
	int verNum;
}ALMGraph;
ALMGraph* Create(int n) {
	ALMGraph* graph = (ALMGraph*)calloc(1, sizeof(ALMGraph));
	assert(graph);
	graph->verNum = n;
	graph->ver = (VerList)calloc(n, sizeof(VerNode));
	assert(graph->ver);
	for (int i = 0; i < n; i++) {
		graph->ver[i].data = i + 1;
		graph->ver[i].EdgeNum = 0;
		graph->ver[i].firstEdge = NULL;
	}
	return graph;
}
void Push(ALMGraph* obj, int ver, int adjEdge, int distance) {
	if (obj->ver[ver - 1].EdgeNum == 0) {
		obj->ver[ver - 1].firstEdge = (EdgeNode*)calloc(1, sizeof(EdgeNode));
		assert(obj->ver[ver - 1].firstEdge);
		obj->ver[ver - 1].firstEdge->data = adjEdge;
		obj->ver[ver - 1].firstEdge->info = distance;
		obj->ver[ver - 1].firstEdge->next = NULL;
	}
	else {
		EdgeNode* node = (EdgeNode*)calloc(1, sizeof(EdgeNode));
		assert(node);
		node->data = adjEdge;
		node->info = distance;
		node->next = obj->ver[ver - 1].firstEdge->next;
		obj->ver[ver - 1].firstEdge->next = node;
	}
	obj->ver[ver - 1].EdgeNum += 1;
}
void DFS(ALMGraph* obj, int ver, int* ans) {
	VerNode p = obj->ver[ver - 1];
	if (p.EdgeNum == 0 || p.visited) {
		return;
	}
	obj->ver[ver - 1].visited = true;
	EdgeNode* node = p.firstEdge;
	for (int i = 0; i < p.EdgeNum; i++) {
		if (*ans == -1 || node->info < *ans) {
			*ans = node->info;
		}
		DFS(obj, node->data, ans);
		node = node->next;
	}
}
void Destroy(ALMGraph** obj) {
	for (int i = 0; i < (*obj)->verNum; i++) {
		// 删除链表节点
		while ((*obj)->ver[i].EdgeNum > 1) {
			EdgeNode* p = (*obj)->ver[i].firstEdge->next;
			(*obj)->ver[i].firstEdge->next = p->next;
			p->next = NULL;
			free(p);
			p = NULL;
			(*obj)->ver[i].EdgeNum -= 1;
		}
		// 删除头结点
		free((*obj)->ver[i].firstEdge);
		(*obj)->ver[i].firstEdge = NULL;
		(*obj)->ver[i].EdgeNum -= 1;
	}
	free((*obj)->ver);
	(*obj)->ver = NULL;
	free(*obj);
	*obj = NULL;
}
int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
	ALMGraph* obj = Create(n);
	for (int i = 0; i < roadsSize; i++) {
		int begin = roads[i][0];
		int end = roads[i][1];
		int distance = roads[i][2];
		Push(obj, begin, end, distance);
		Push(obj, end, begin, distance);
	}
	int ans = -1;
	DFS(obj, 1, &ans);
	Destroy(&obj);
	return ans;
}