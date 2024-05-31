#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.05.31力扣网刷题
//二叉树中第二小的节点——树、深度搜索、二叉树——简单
//给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
//更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。
//给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。
//如果第二小的值不存在的话，输出 - 1 。
//示例 1：
//输入：root = [2, 2, 5, null, null, 5, 7]
//输出：5
//解释：最小的值是 2 ，第二小的值是 5 。
//示例 2：
//输入：root = [2, 2, 2]
//输出： - 1
//解释：最小的值是 2, 但是不存在第二小的值。
//提示：
//树中节点数目在范围[1, 25] 内
//1 <= Node.val <= 2^31 - 1
//对于树中每个节点 root.val == min(root.left.val, root.right.val)

int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}

void PreOrder(struct TreeNode* root, int* arr, int* pi) {
	if (!root)
		return;
	for (int i = 0; i < *pi; i++) {
		if (root->val > arr[i]) {
			arr[(*pi)++] = root->val;
			break;
		}
	}
	PreOrder(root->left, arr, pi);
	PreOrder(root->right, arr, pi);
}

int findSecondMinimumValue(struct TreeNode* root) {
	int* ans = (int*)calloc(25, sizeof(int));
	assert(ans);
	int i = 0;
	ans[i++] = root->val;
	PreOrder(root, ans, &i);
	qsort(ans, i, sizeof(int), cmp);
	int tmp = ans[1];
	free(ans);
	if (tmp == 0)
		tmp--;
	return tmp;
}