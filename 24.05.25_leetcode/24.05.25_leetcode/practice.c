#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.05.25力扣网刷题
// 二叉树的层平均值——树、深度优先搜索、广度优先搜索、二叉树
//给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
//示例 1：
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：[3.00000, 14.50000, 11.00000]
//解释：第 0 层的平均值为 3, 第 1 层的平均值为 14.5, 第 2 层的平均值为 11 。
//因此返回[3, 14.5, 11] 。
//示例 2:
//输入：root = [3, 9, 20, 15, 7]
//输出：[3.00000, 14.50000, 11.00000]
//提示：
//树中节点数量在[1, 10^4] 范围内
//- 2^31 <= Node.val <= 2^31 - 1

int Depth(struct TreeNode* root) {
	if (!root)
		return 0;
	int l = Depth(root->left);
	int r = Depth(root->right);
	return l > r ? l + 1 : r + 1;
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
	int k = Depth(root);//获取层数
	*returnSize = k;
	double* ans = (double*)calloc(k, sizeof(double));
	assert(ans);
	struct TreeNode* Q[5000] = { 0 };
	int f = 0;//队头指针
	int r = 0;//队尾指针
	struct TreeNode* p = root;
	Q[r++] = p;//根结点入队
	int i = 0;
	int num = 1;
	ans[i++] = p->val * 1.0;
	int next_num = 0;
	for (k; k > 1; k--) {
		while (num) {
			//出队
			p = Q[f++];
			f %= 5000;
			num--;
			if (p->left) {
				Q[r++] = p->left;
				r %= 5000;
				next_num++;
				ans[i] += p->left->val * 1.0;
			}
			if (p->right) {
				Q[r++] = p->right;
				r %= 5000;
				next_num++;
				ans[i] += p->right->val * 1.0;
			}
		}
		ans[i] /= next_num;//获取下一层的平均值
		num = next_num;
		next_num = 0;
		i++;
	}
	return ans;
}