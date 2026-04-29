#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.04.29力扣网刷题
//LCP 07. 传递信息——深度优先搜索、广度优先搜索、图、动态规划——简单
//小朋友 A 在和 ta 的小伙伴们玩传信息游戏，游戏规则如下：
//有 n 名玩家，所有玩家编号分别为 0 ～ n - 1，其中小朋友 A 的编号为 0
//每个玩家都有固定的若干个可传信息的其他玩家（也可能没有）。传信息的关系是单向的（比如 A 可以向 B 传信息，但 B 不能向 A 传信息）。
//每轮信息必须需要传递给另一个人，且信息可重复经过同一个人
//给定总玩家数 n，以及按[玩家编号, 对应可传递玩家编号] 关系组成的二维数组 relation。返回信息从小 A(编号 0) 经过 k 轮传递到编号为 n - 1 的小伙伴处的方案数；若不能到达，返回 0。
//示例 1：
//输入：n = 5, relation = [[0, 2], [2, 1], [3, 4], [2, 3], [1, 4], [2, 0], [0, 4]], k = 3
//输出：3
//解释：信息从小 A 编号 0 处开始，经 3 轮传递，到达编号 4。共有 3 种方案，分别是 0->2->0->4， 0->2->1->4， 0->2->3->4。
//示例 2：
//输入：n = 3, relation = [[0, 2], [2, 1]], k = 2
//输出：0
//解释：信息不能从小 A 处经过 2 轮传递到编号 2
//限制：
//2 <= n <= 10
//1 <= k <= 5
//1 <= relation.length <= 90, 且 relation[i].length == 2
//0 <= relation[i][0], relation[i][1] < n 且 relation[i][0] != relation[i][1]

#if 0
// 十字链表
#define MAXSIZE 5
typedef int VerType;
typedef int ArcType;
//边结点
typedef struct ArcNode {
	int tailvex;				// 弧尾顶点编号
	int headvex;				// 弧头顶点编号
	struct ArcNode* hlink;		// 头链表指针
	struct ArcNode* tlink;		// 尾链表指针
	//ArcType info;				// 边信息（权值），可以省略
}ArcNode;
//顶点结点
typedef struct VerNode {
	VerType data;				// 顶点信息
	ArcNode* firstin;			// 入边表（逆邻接表）
	ArcNode* firstout;			// 出边表（邻接表）
}VerNode;
//十字链表
typedef struct Orthogonal_List {
	VerNode* ver_list;	// 顶点表
	int ver_num;				// 当前顶点数两
	int arc_num;				// 当前弧的数量
}OLGraph;

OLGraph* Create(int ver, int arc) {
	OLGraph* graph = (OLGraph*)calloc(1, sizeof(OLGraph));
	assert(graph);
	graph->arc_num = arc;
	graph->ver_num = ver;
	graph->ver_list = (VerNode*)calloc(ver, sizeof(VerNode));
	assert(graph->ver_list);
	for (int i = 0; i < ver; i++) {
		graph->ver_list[i].data= i;
		graph->ver_list[i].firstin = (ArcNode*)calloc(1, sizeof(ArcNode));
		assert(graph->ver_list[i].firstin);
		graph->ver_list[i].firstin->tailvex = i;
		graph->ver_list[i].firstin->tlink = NULL;
		graph->ver_list[i].firstin->headvex = -1;
		graph->ver_list[i].firstin->hlink = NULL;
	}
	return graph;
}
void Push(OLGraph* graph, int* arc) {
	ArcNode* node = (ArcNode*)calloc(1, sizeof(ArcNode));
	assert(node);
	int out = arc[0];
	int in = arc[1];
	// 入度
	ArcNode* pre_point_in = graph->ver_list[in].firstin;
	ArcNode* point_in = pre_point_in->hlink;
	while (point_in) {
		pre_point_in->hlink = point_in;
		point_in = point_in->hlink;
	}
	pre_point_in->hlink = node;
	node->hlink = point_in;
	// 出度
	ArcNode* pre_point_out = graph->ver_list[out].firstout;
	ArcNode* point_out = pre_point_out->tlink;
	while (point_out) {
		pre_point_out = point_out;
		point_out = point_out->tlink;
	}
	pre_point_out->tlink = node;
	node->tlink = point_out;
}
ArcNode* find(ArcNode* link, ArcNode* node) {

}
void Delete(OLGraph* graph, int ver) {
	ArcNode* point_in = graph->ver_list[ver].firstin;
	ArcNode* point_out = graph->ver_list[ver].firstout;

}
#endif

// 邻接表 —— 有向图
typedef struct ArcNode {
	int adjver;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct VerNode {
	int data;
	ArcNode* firstArc;
}VerNode;
typedef struct Adjacency_List_Method_Graph {
	VerNode* verlist;
	int vernum;
	int arcnum;
}ALMGraph;
void PrintGraph(ALMGraph* graph) {
	for (int i = 0; i < graph->vernum; i++) {
		printf("%d: head->", graph->verlist[i].data);
		ArcNode* head = graph->verlist[i].firstArc;
		ArcNode* p = head->nextarc;
		while (p) {
			printf("[%d, %d]->", graph->verlist[i].data, p->adjver);
			p = p->nextarc;
		}
		printf("NULL\n");
	}
}
ALMGraph* Create(int vernum, int arcnum) {
	ALMGraph* graph = (ALMGraph*)calloc(1, sizeof(ALMGraph));
	assert(graph);
	graph->arcnum = arcnum;
	graph->vernum = vernum;
	graph->verlist = (VerNode*)calloc(vernum, sizeof(VerNode));
	assert(graph->verlist);
	for (int i = 0; i < vernum; i++) {
		graph->verlist[i].data = i;
		graph->verlist[i].firstArc = (ArcNode*)calloc(1, sizeof(ArcNode));
		assert(graph->verlist[i].firstArc);
		graph->verlist[i].firstArc->adjver = -1;
		graph->verlist[i].firstArc->nextarc = NULL;
	}
	return graph;
}
void Destroy(ALMGraph** graph) {
	for (int i = 0; i < (*graph)->vernum; i++) {
		ArcNode* head = (*graph)->verlist[i].firstArc;
		ArcNode* p = head->nextarc;
		while (p) {
			head->nextarc = p->nextarc;
			p->nextarc = NULL;
			free(p);
			p = head->nextarc;
		}
		free(head);
		head = NULL;
		(*graph)->verlist[i].firstArc = NULL;
	}
	free((*graph)->verlist);
	(*graph)->verlist = NULL;
	free(*graph);
	*graph = NULL;
}
void Push(ALMGraph* graph, int* arc) {
	ArcNode* node = (ArcNode*)calloc(1, sizeof(ArcNode));
	assert(node);
	int out = arc[0], in = arc[1];
	node->adjver = in;
	node->nextarc = NULL;
	ArcNode* head = graph->verlist[out].firstArc;
	ArcNode* pre = head;
	ArcNode* p = head->nextarc;
	while (p) {
		pre = p;
		p = p->nextarc;
	}
	pre->nextarc = node;
}
void dfs(ALMGraph* graph, int cur, int rest, int target, int* ans) {
	if (rest == 0) {
		if (cur == target) {
			(*ans)++;
		}
		return;
	}

	ArcNode* p = graph->verlist[cur].firstArc->nextarc;

	while (p) {
		dfs(graph, p->adjver, rest - 1, target, ans);
		p = p->nextarc;
	}
}
int numWays(int n, int** relation, int relationSize, int* relationColSize,
			int k) {
	ALMGraph* graph = Create(n, relationSize);

	for (int i = 0; i < relationSize; i++) {
		Push(graph, relation[i]);
	}

	int ans = 0;
	dfs(graph, 0, k, n - 1, &ans);
	Destroy(&graph);
	return ans;
}

// 方法二：动态规划
void Print(int* nums, int len) {
	printf("[ ");
	for (int i = 0; i < len; i++) {
		if (i == len - 1) {
			printf("%d ", nums[i]);
		}
		else {
			printf("%d, ", nums[i]);
		}
	}
	printf("]\n\n");
}
int numWays(int n, int** relation, int relationSize, int* relationColSize, int k) {
	int* dp = (int*)calloc(n, sizeof(int));
	assert(dp);
	dp[0] = 1;
	for (int i = 0; i < k; i++) {
		int* next = (int*)calloc(n, sizeof(int));
		assert(next);
		for (int j = 0; j < relationSize; j++) {
			int from = relation[j][0];
			int to = relation[j][1];
			next[to] += dp[from];
		}
		for (int i = 0; i < n; i++) {
			dp[i] = next[i];
		}
		free(next);
		next = NULL;
	}
	int ans = dp[n - 1];
	free(dp);
	dp = NULL;
	return ans;
}