#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.06.03力扣网刷题
//二叉搜索树节点最小距离——树、深度优先搜索、广度优先搜索、二叉搜索树、二叉树——简单
//给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//差值是一个正数，其数值等于两值之差的绝对值。
//示例 1：
//输入：root = [4, 2, 6, 1, 3]
//输出：1
//示例 2：
//输入：root = [1, 0, 48, null, null, 12, 49]
//输出：1
//提示：
//树中节点的数目范围是[2, 100]
//0 <= Node.val <= 10^5
//注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
void visit(TN* root, int* tmp, int* pi) {
	if (root) {
		tmp[*pi] = root->val;
		*pi += 1;
	}
}
void dfs(TN* root, int* tmp, int* pi) {
	if (root) {
		dfs(root->left, tmp, pi);
		visit(root, tmp, pi);
		dfs(root->right, tmp, pi);
	}
}
int Get_Size(TN* root) {
	if (!root)
		return 0;
	int left = Get_Size(root->left);
	int right = Get_Size(root->right);
	return left + right + 1;
}
int minDiffInBST(struct TreeNode* root) {
	int size = Get_Size(root);
	int* tmp = (int*)calloc(size, sizeof(int));
	assert(tmp);
	int i = 0;
	dfs(root, tmp, &i);
	int ans = abs(tmp[0] - tmp[1]);
	for (int j = 1; j < i - 1; j++) {
		int key = abs(tmp[j] - tmp[j + 1]);
		ans = ans < key ? ans : key;
	}
	free(tmp);
	tmp = NULL;
	return ans;
}