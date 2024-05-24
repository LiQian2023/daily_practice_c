#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.05.24力扣网刷题
//左叶子之和——树、深度优先搜索、广度优先搜索、二叉树——简单
//给定二叉树的根节点 root ，返回所有左叶子之和。
//示例 1：
//输入: root = [3, 9, 20, null, null, 15, 7]
//输出 : 24
//解释 : 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
//示例 2 :
//	输入 : root = [1]
//	输出 : 0
//	提示 :
//	节点数在[1, 1000] 范围内
//	- 1000 <= Node.val <= 1000

//广度优先搜索
int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}

int sumOfLeftLeaves(struct TreeNode* root) {
	if (!root->left && !root->right)
		return 0;
	struct TreeNode* arr[500] = { 0 };//队列
	int r = 1;//队尾指针
	int f = 0;//队头指针
	int sum = 0;
	struct TreeNode* p = root;
	arr[0] = p;//首元素入队
	int num[2048] = { 0 };
	num[0] = 1001;
	num[1] = 1001;
	int i = 2;
	while (f != r) {
		p = arr[f++];
		f %= 500;
		if (p->left) {
			arr[r++] = p->left;
			r %= 500;
			if (!p->left->left && !p->left->right)
				num[i++] = p->left->val;
			else
				num[i++] = 1001;
		}
		else
			num[i++] = 1001;
		if (p->right) {
			arr[r++] = p->right;
			r %= 500;
			num[i++] = 1001;
		}
		else
			num[i++] = 1001;
	}
	qsort(num, i, sizeof(int), cmp);
	for (int j = 0; num[j] != 1001; j++)
		sum += num[j];
	return sum;
}

int sumOfLeftLeaves(struct TreeNode* root) {
	if (!root)
		return 0;
	int  ans = 0;
	if (root->left && !root->left->left && !root->left->right)
		ans = root->left->val;
	int l = sumOfLeftLeaves(root->left);
	int r = sumOfLeftLeaves(root->right);
	return l + r + ans;
}