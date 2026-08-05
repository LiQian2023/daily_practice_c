#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.08.05力扣网刷题
//3310. 移除可疑的方法——资深工程师、深度优先搜索、广度优先搜索、图、第418场周赛——中等
//你正在维护一个项目，该项目有 n 个方法，编号从 0 到 n - 1。
//给你两个整数 n 和 k，以及一个二维整数数组 invocations，其中 invocations[i] = [ai, bi] 表示方法 ai 调用了方法 bi。
//已知如果方法 k 存在一个已知的 bug。那么方法 k 以及它直接或间接调用的任何方法都被视为 可疑方法 ，我们需要从项目中移除这些方法。
//只有当一组方法没有被这组之外的任何方法调用时，这组方法才能被移除。
//返回一个数组，包含移除所有 可疑方法 后剩下的所有方法。你可以以任意顺序返回答案。如果无法移除 所有 可疑方法，则 不 移除任何方法。
//示例 1:
//输入: n = 4, k = 1, invocations = [[1, 2], [0, 1], [3, 2]]
//输出 : [0, 1, 2, 3]
//解释 :
//方法 2 和方法 1 是可疑方法，但它们分别直接被方法 3 和方法 0 调用。由于方法 3 和方法 0 不是可疑方法，我们无法移除任何方法，故返回所有方法。
//示例 2:
//输入: n = 5, k = 0, invocations = [[1, 2], [0, 2], [0, 1], [3, 4]]
//输出 : [3, 4]
//解释 :
//方法 0、方法 1 和方法 2 是可疑方法，且没有被任何其他方法直接调用。我们可以移除它们。
//示例 3:
//输入: n = 3, k = 2, invocations = [[1, 2], [0, 1], [2, 0]]
//输出 : []
//解释 :
//所有方法都是可疑方法。我们可以移除它们。
//提示:
//1 <= n <= 10^5
//0 <= k <= n - 1
//0 <= invocations.length <= 2 * 10^5
//invocations[i] == [ai, bi]
//0 <= ai, bi <= n - 1
//ai != bi
//invocations[i] != invocations[j]

//// 边表结点
//typedef struct EdgeNode {
//	int adjVer;
//	struct EdgeNode* next;
//}EdgeNode, * EdgeList;
//// 顶点表结点
//typedef struct VerNode {
//	int data;
//	EdgeNode* first;
//}VerNode, * VerList;
//// 邻接表
//typedef struct ALGraph {
//	VerList list;
//	int verNum;
//}ALGraph;
//// 创建邻接表
//ALGraph* Create(int n) {
//	ALGraph* obj = (ALGraph*)calloc(1, sizeof(ALGraph));
//	assert(obj);
//	obj->verNum = n;
//	obj->list = (VerNode*)calloc(n, sizeof(VerNode));
//	assert(obj->list);
//	for (int i = 0; i < n; i++) {
//		obj->list[i].data = i;
//		// 边表头结点
//		obj->list[i].first = (EdgeNode*)calloc(1, sizeof(EdgeNode));
//		assert(obj->list[i].first);
//		obj->list[i].first->adjVer = -1;
//		obj->list[i].first->next = NULL;
//	}
//	return obj;
//}
//// 添加元素
//void Push(ALGraph* obj, int begin, int end) {
//	EdgeNode* newEdge = (EdgeNode*)calloc(1, sizeof(EdgeNode));
//	assert(newEdge);
//	newEdge->adjVer = end;
//	// 前插
//	newEdge->next = obj->list[begin].first->next;
//	obj->list[begin].first->next = newEdge;
//}
//// 销毁元素
//void Destroy(ALGraph** obj) {
//	for (int i = 0; i < (*obj)->verNum; i++) {
//		EdgeNode* q = (*obj)->list[i].first;
//		EdgeNode* p = (*obj)->list[i].first->next;
//		while (p) {
//			q->next = p->next;
//			p->next = NULL;
//			free(p);
//			p = q->next;
//		}
//		free((*obj)->list[i].first);
//		(*obj)->list[i].first = NULL;
//	}
//	free((*obj)->list);
//	(*obj)->list = NULL;
//	free(*obj);
//	*obj = NULL;
//}
//// 深搜
//void Mark(ALGraph* obj, int k, bool flag, bool* visited, int begin,int* del, int* pi) {
//	// 更新状态
//	visited[k] = flag;
//	// 记录可疑方法
//	if (del != NULL) {
//		del[*pi] = k;
//		*pi += 1;
//	}
//	if (obj->list[k].first->next == NULL) {
//		return;
//	}
//	EdgeNode* p = obj->list[k].first->next;
//	while (p && p->adjVer != begin) {
//		Mark(obj, p->adjVer, flag, visited, begin, del, pi);
//		p = p->next;
//	}
//}
//int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
//	// 邻接表记录有向边
//	ALGraph* obj = Create(n);
//	for (int i = 0; i < invocationsSize; i++) {
//		int begin = invocations[i][0], end = invocations[i][1];
//		Push(obj, begin, end);
//	}
//	// 更新访问记录并记录可疑方法
//	bool* visited = (bool*)calloc(n, sizeof(bool));
//	assert(visited);
//	int* del = (int*)calloc(n, sizeof(int));
//	assert(del);
//	int count = 0;
//	Mark(obj, k, true, visited, k, del, &count);
//	for (int i = 0; i < n; i++) {
//		if (!visited[i]) {
//			Mark(obj, i, false, visited, i, NULL, NULL);
//		}
//	}
//	// 判断是否删除
//	bool flag = true;
//	for (int i = 0; i < count; i++) {
//		int key = del[i];
//		if (visited[key] == false) {
//			flag = false;
//			break;
//		}
//	}
//	// 获取最终结果
//	int size = 0;
//	for (int i = 0; i < n; i++) {
//		if (visited[i] == false) {
//			size += 1;
//		}
//	}
//	if (flag == false) {
//		size = n;
//	}
//	*returnSize = 0;
//	int* ans = (int*)calloc(size, sizeof(int));
//	assert(ans);
//
//	if (flag == false) {
//		for (int i = 0; i < n; i++) {
//			ans[i] = i;
//		}
//		*returnSize = n;
//	}
//	else {
//		for (int i = 0; i < n; i++) {
//			if (visited[i] == false) {
//				ans[*returnSize] = i;
//				*returnSize += 1;
//			}
//		}
//	}
//
//	Destroy(&obj);
//	free(visited);
//	visited = NULL;
//	free(del);
//	del = NULL;
//	return ans;
//}


// 边表结点
typedef struct EdgeNode {
	int adjVer;
	struct EdgeNode* next;
}EdgeNode, * EdgeList;

// 顶点表结点
typedef struct VerNode {
	int data;
	EdgeNode* first;
}VerNode, * VerList;

// 邻接表
typedef struct ALGraph {
	VerList list;
	int verNum;
}ALGraph;

// 创建邻接表
ALGraph* Create(int n) {
	ALGraph* obj = (ALGraph*)calloc(1, sizeof(ALGraph));
	assert(obj);

	obj->verNum = n;
	obj->list = (VerNode*)calloc(n, sizeof(VerNode));
	assert(obj->list);

	for (int i = 0; i < n; i++) {
		obj->list[i].data = i;

		// 边表头结点
		obj->list[i].first = (EdgeNode*)calloc(1, sizeof(EdgeNode));
		assert(obj->list[i].first);

		obj->list[i].first->adjVer = -1;
		obj->list[i].first->next = NULL;
	}

	return obj;
}

// 添加元素
void Push(ALGraph* obj, int begin, int end) {
	EdgeNode* newEdge = (EdgeNode*)calloc(1, sizeof(EdgeNode));
	assert(newEdge);

	newEdge->adjVer = end;

	// 前插
	newEdge->next = obj->list[begin].first->next;
	obj->list[begin].first->next = newEdge;
}

// 销毁元素
void Destroy(ALGraph** obj) {
	if (obj == NULL || *obj == NULL) {
		return;
	}

	for (int i = 0; i < (*obj)->verNum; i++) {
		EdgeNode* q = (*obj)->list[i].first;
		EdgeNode* p = q->next;

		while (p) {
			q->next = p->next;
			p->next = NULL;
			free(p);
			p = q->next;
		}

		free((*obj)->list[i].first);
		(*obj)->list[i].first = NULL;
	}

	free((*obj)->list);
	(*obj)->list = NULL;

	free(*obj);
	*obj = NULL;
}

// 深搜，标记从 k 出发能够到达的可疑方法
void Mark(ALGraph* obj, int k, bool* visited) {
	// 防止重复访问和有向环
	if (visited[k]) {
		return;
	}

	visited[k] = true;

	EdgeNode* p = obj->list[k].first->next;

	while (p) {
		if (!visited[p->adjVer]) {
			Mark(obj, p->adjVer, visited);
		}

		p = p->next;
	}
}

int* remainingMethods(
	int n,
	int k,
	int** invocations,
	int invocationsSize,
	int* invocationsColSize,
	int* returnSize
) {
	(void)invocationsColSize;

	// 邻接表记录有向边
	ALGraph* obj = Create(n);

	for (int i = 0; i < invocationsSize; i++) {
		int begin = invocations[i][0];
		int end = invocations[i][1];

		Push(obj, begin, end);
	}

	// 记录可疑方法
	bool* visited = (bool*)calloc(n, sizeof(bool));
	assert(visited);

	// 从 k 出发，找到所有可疑方法
	Mark(obj, k, visited);

	/*
	 * 判断是否能够删除可疑方法。
	 *
	 * 如果存在：
	 * 非可疑方法 -> 可疑方法
	 *
	 * 那么可疑方法不能被删除。
	 */
	bool flag = true;

	for (int i = 0; i < invocationsSize; i++) {
		int begin = invocations[i][0];
		int end = invocations[i][1];

		if (!visited[begin] && visited[end]) {
			flag = false;
			break;
		}
	}

	// 计算最终结果数量
	int size = 0;

	if (flag == false) {
		size = n;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				size += 1;
			}
		}
	}

	*returnSize = 0;

	/*
	 * size 可能为 0。
	 * 至少申请一个 int，避免 calloc(0, ...) 返回 NULL 后断言失败。
	 */
	int capacity = size > 0 ? size : 1;

	int* ans = (int*)calloc(capacity, sizeof(int));
	assert(ans);

	// 不能删除，返回全部方法
	if (flag == false) {
		for (int i = 0; i < n; i++) {
			ans[*returnSize] = i;
			*returnSize += 1;
		}
	}
	// 可以删除，返回所有非可疑方法
	else {
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				ans[*returnSize] = i;
				*returnSize += 1;
			}
		}
	}

	Destroy(&obj);

	free(visited);
	visited = NULL;

	return ans;
}