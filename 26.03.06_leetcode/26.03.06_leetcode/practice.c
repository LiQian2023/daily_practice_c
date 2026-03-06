#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.06力扣网刷题
//897. 递增顺序搜索树——中级工程师、栈、树、深度优先搜索、二叉搜索树、二叉树、第100场周赛——简单
//给你一棵二叉搜索树的 root ，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
//示例 1：
//输入：root = [5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]
//输出：[1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9]
//示例 2：
//输入：root = [5, 1, 7]
//输出：[1, null, 5, null, 7]
//提示：
//树中节点数的取值范围是[1, 100]
//0 <= Node.val <= 1000

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
int getSize(TN* root) {
	if (!root) {
		return 0;
	}
	int l = getSize(root->left);
	int r = getSize(root->right);
	return l + r + 1;
}
void Print(TN** ans) {
	TN* p = *ans;
	while (p){
		printf("p->val = %d\n", p->val);
		p = p->right;
	}
	printf("\n\n");
}
void visited(TN* root, TN** ans, TN** tail) {
	root->left = NULL;
	if (!(*ans)) {
		(*ans) = root;
		(*tail) = (*ans);
	}
	else {
		(*tail)->left = NULL;
		(*tail)->right = root;
		(*tail) = (*tail)->right;
	}
}
void dfs(TN* root, TN** ans, TN** tail, TN* pre) {
	if (!root) {
		return;
	}
	dfs(root->left, ans, tail, root);
	visited(root, ans, tail);
	Print(ans);
	dfs(root->right, ans, tail, root);
}
struct TreeNode* increasingBST(struct TreeNode* root) {
	TN* p = root;
	TN* ans = NULL;
	TN* tail = NULL;
	dfs(root, &ans, &tail, NULL);
	return ans;
}