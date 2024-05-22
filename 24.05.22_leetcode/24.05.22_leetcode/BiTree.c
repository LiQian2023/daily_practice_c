#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//二叉树的初始化
void BTInit(struct TreeNode** root) {
	assert(root);
	*root = NULL;
}

//创建二叉树
struct TreeNode* Creat(int* arr, int* i,int n) {
	assert(arr && i);
	if (*i == n)
		return NULL;
	if (arr[*i] == 101) {
		(*i)++;
		return NULL;
	}
	struct TreeNode* p = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
	assert(p);
	p->val = arr[(*i)++];
	p->left = Creat(arr, i, n);
	p->right = Creat(arr, i, n);
	return p;
}

//销毁二叉树
void Destroy(struct TreeNode** root) {
	if (!root)
		return;
	Destroy((*root)->left);
	Destroy((*root)->right);
	free(*root);
	*root = NULL;
}

//功能测试
void test1() {
	struct TreeNode* T;
	BTInit(&T);
	int n = 0;
	while (scanf("%d", &n) == 1) {
		int arr[100] = { 0 };
		int i = 0;
		for (i; i < n; i++)
			scanf("%d", &arr[i]);
		printf("\n");
		i = 0;
		T = Creat(arr, &i, n);
		int size = 0;
		int* ret = preorderTraversal(T, &size);
		printf("\n");
		for (int i = 0; i < size; i++)
			printf("%d ", ret[i]);
		printf("\n");
	}
}