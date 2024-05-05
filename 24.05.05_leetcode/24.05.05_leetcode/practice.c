#define _CRT_SECURE_NO_WARNINGS 1

#include "BTree.h"

//2024.05.05力扣网刷题
// 计算二叉树的深度——树、深度优先搜索、二叉树、广度优先搜索——简单
//某公司架构以二叉树形式记录，请返回该公司的层级数。
//示例 1：
//输入：root = [1, 2, 2, 3, null, null, 5, 4, null, null, 4]
//输出: 4
//解释 : 上面示例中的二叉树的最大深度是 4，沿着路径 1 -> 2 -> 3 -> 4 或 1 -> 2 -> 5 -> 4 到达叶节点的最长路径上有 4 个节点。
//提示：
//节点总数 <= 10000

int calculateDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	//if (root->left == NULL && root->right == NULL)
	//	return 0;
	int left = calculateDepth(root->left);
	int right = calculateDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

int Treehight(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = Treehight(root->left);
	int right = Treehight(root->right);
	return left > right ? left + 1 : right + 1;
}
int TreeSize(struct TreeNode* root) {
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void visit(struct TreeNode* root, int* num, int i) {
	num[i - 1] = root->val;
}
void inorder(struct TreeNode* root, int* num,int* i) {
	if (root == NULL) 
		return;
	if (root->left == NULL && root->right == NULL) {
		++(*i);
		return;
	}
	inorder(root->left, num, i);
	visit(root, num, *i);
	inorder(root->right, num, i);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	*returnSize = TreeSize(root);
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	int i = 0;
	inorder(root, ans, &i);
	return ans;
}


void deepsearch(struct TreeNode* root, int* num, int size) {
	if (!root)
		return 0;
	deepsearch(root->left, num, --size);

}