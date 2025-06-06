#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.06.06力扣网刷题
//寻找图中是否存在路径——深度优先搜索、广度优先搜索、并查集、图——简单
//有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。
//图中的边用一个二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 
//每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。
//请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。
//给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 true，否则返回 false 。
//示例 1：
//输入：n = 3, edges = [[0, 1], [1, 2], [2, 0]], source = 0, destination = 2
//输出：true
//解释：存在由顶点 0 到顶点 2 的路径:
//-0 → 1 → 2
//- 0 → 2
//示例 2：
//输入：n = 6, edges = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]], source = 0, destination = 5
//输出：false
//解释：不存在由顶点 0 到顶点 5 的路径.
//提示：
//1 <= n <= 2 * 10^5
//0 <= edges.length <= 2 * 10^5
//edges[i].length == 2
//0 <= ui, vi <= n - 1
//ui != vi
//0 <= source, destination <= n - 1
//不存在重复边
//不存在指向顶点自身的边
typedef struct EdgeNode {
	int ver_x;
	int ver_y;
	struct EdgeNode* edge_x, * edge_y;
}ENode;
typedef struct VerNode {
	int val;
	ENode* first_edge;
}VNode;
typedef struct Cross_Linked_List {
	VNode* ver_list;
	int ver_num;
	int edge_num;
}CLLGraph;
CLLGraph* Initial_CLLGraph(int n, int m) {
	CLLGraph* g = (CLLGraph*)calloc(1, sizeof(CLLGraph));
	assert(g);
	g->ver_num = n;
	g->edge_num = m;
	g->ver_list = (VNode*)calloc(n, sizeof(VNode));
	assert(g->ver_list);
	for (int i = 0; i < n; i++) {
		g->ver_list[i].val = i;
		ENode* head = (ENode*)calloc(1, sizeof(ENode));
		assert(head);
		g->ver_list[i].first_edge = head;
	}
	return g;
}
void AddEdge(CLLGraph* g, int x, int y) {
	ENode* head = g->ver_list[x].first_edge;
	ENode* p = head->edge_x;
	ENode* q = head;
	while (p && p->ver_y != y) {
		q = p;
		p = p->edge_x;
	}
	if (!p) {
		p = (ENode*)calloc(1, sizeof(ENode));
		assert(p);
		p->ver_x = x;
		p->ver_y = y;
		q->edge_x = p;
		p->edge_x = NULL;
		p->edge_y = NULL;
	}
}
void Connect_y(CLLGraph* g) {
	for (int i = 0; i < g->ver_num; i++) {
		ENode* head_x = g->ver_list[i].first_edge;
		ENode* px = head_x->edge_x;
		while (px) {
			int y = px->ver_y;
			ENode* py = g->ver_list[y].first_edge->edge_x;
			px->edge_y = py;
			px = px->edge_x;
		}
	}
}
void Destroy_CLLGraph(CLLGraph** g) {
	for (int i = 0; i < (*g)->ver_num; i++) {
		ENode* head = (*g)->ver_list[i].first_edge;
		ENode* p = head->edge_x;
		while (p) {
			head->edge_x = p->edge_x;
			p->edge_x = NULL;
			free(p);
			p = head->edge_x;
			(*g)->edge_num -= 1;
		}
		free(head);
		head = NULL;
		(*g)->ver_list[i].first_edge = head;
	}
	free((*g)->ver_list);
	(*g)->ver_list = NULL;
	free(*g);
	*g = NULL;
}
void Print_Node(ENode* p) {
	printf("p->ver_x = %d\n", p->ver_x);
	printf("p->ver_y = %d\n", p->ver_y);
}
void Print_CLLGraph(CLLGraph* g) {
	for (int i = 0; i < g->ver_num; i++) {
		printf("%d:{\t", g->ver_list[i].val);
		ENode* head = g->ver_list[i].first_edge;
		ENode* p = head->edge_x;
		while (p) {
			printf("(%d, %d),\t", p->ver_x, p->ver_y);
			p = p->edge_x;
		}
		printf("}\n");
	}
}
void Print_Route(CLLGraph* g) {
	for (int i = 0; i < g->ver_num; i++) {
		printf("%d:{\t", g->ver_list[i].val);
		ENode* head = g->ver_list[i].first_edge;
		ENode* x = head->edge_x;
		while (x) {
			printf("(%d, %d)->", x->ver_x, x->ver_y);
			ENode* y = x->edge_y;
			while (y) {
				printf("(%d, %d)->", y->ver_x, y->ver_y);
				y = y->edge_y;
			}
			printf("\t");
			x = x->edge_x;
		}
		printf("}\n");
	}
}
void DFS(CLLGraph* g, int x, int y) {
	if (g->ver_list[y].first_edge) {

	}
}
bool validPath1(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
	if (source == 0 && destination == 0)
		return true;
	CLLGraph* g = Initial_CLLGraph(n, edgesSize);
	for (int i = 0; i < edgesSize; i++) {
		int x = edges[i][0];
		int y = edges[i][1];
		AddEdge(g, x, y);
	}
	Connect_y(g);
	Print_CLLGraph(g);
	bool flag = false;
	ENode* head = g->ver_list[source].first_edge;
	ENode* p = head->edge_x;
	while (p) {
		if (p->ver_y == destination) {
			flag = true;
			break;
		}
		else {
			bool flag_x = false;
			bool flag_y = false;
			if (p->ver_x == source || p->ver_y == source) {
				flag_x = true;
			}
			else if (p->ver_y == destination || p->ver_x == destination) {
				flag_y = true;
			}
			ENode* y = p->edge_y;
			while (y && (!flag_x || !flag_y)) {
				if (y->ver_x == source || y->ver_y == source) {
					flag_x = true;
				}
				else if (y->ver_x = destination || y->ver_y == destination) {
					flag_y = true;
				}
				y = y->edge_y;
			}
			flag = flag_x && flag_y;
			if (flag) {
				break;
			}
			p = p->edge_x;
		}
	}
	Destroy_CLLGraph(&g);
	return flag;
}

//顺序存储
typedef struct DSUNode {
	int parent;				// 双亲位置信息
	int rank;				// 秩
}DSUNode;					// 并查集结点
typedef struct DSU {
	DSUNode* list;			// 顺序表
	int len;				// 表长
}DSU;						// 并查集
DSU* Creat_DSU(int n) {
	DSU* dsu = (DSU*)calloc(1, sizeof(DSU));
	assert(dsu);
	dsu->len = n;
	dsu->list = (DSUNode*)calloc(n, sizeof(DSUNode));
	assert(dsu->list);
	for (int i = 0; i < n; i++) {
		dsu->list[i].parent = i;
		dsu->list[i].rank = 0;
	}
	return dsu;
}
// 查找根结点
int Find(DSU* dsu, int x) {
	if (dsu->list[x].parent != x) {
		dsu->list[x].parent = Find(dsu, dsu->list[x].parent);
	}
	return dsu->list[x].parent;
}
// 合并集合
void Union(DSU* dsu, int x, int y) {
	int root_x = Find(dsu, x);
	int root_y = Find(dsu, y);
	// 根结点不同，合并两个集合
	if (root_x != root_y) {
		// 按秩合并
		if (dsu->list[root_x].rank < dsu->list[root_y].rank) {
			dsu->list[root_x].parent = root_y;		// 秩小合并到秩大
		}
		else if (dsu->list[root_x].rank > dsu->list[root_y].rank) {
			dsu->list[root_y].parent = root_x;
		}
		else {
			dsu->list[root_x].parent = root_y;		// 秩相同，树x合并到树y
			dsu->list[root_y].rank += 1;			// 树y的秩增加1
		}
	}
}
bool Connect(DSU* dsu, int x, int y) {
	return Find(dsu, x) == Find(dsu, y);
}
void Destroy(DSU** dsu) {
	free((*dsu)->list);
	(*dsu)->list = NULL;
	free(*dsu);
	*dsu = NULL;
}
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
	if (source == destination)
		return true;
	DSU* dsu = Creat_DSU(n);
	for (int i = 0; i < edgesSize; i++) {
		int x = edges[i][0];
		int y = edges[i][1];
		Union(dsu, x, y);
	}
	bool flag = Connect(dsu, source, destination);
	Destroy(&dsu);
	return flag;
}