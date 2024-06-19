#define _CRT_SECURE_NO_WARNINGS 1
#include "BiTree.h"

//2024.06.19力扣网刷题
//二叉树展开为链表——栈、树、深度优先搜索、链表、二叉树——中等
//给你二叉树的根结点 root ，请你将它展开为一个单链表：
//展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
//展开后的单链表应该与二叉树 先序遍历 顺序相同。
//示例 1：
//输入：root = [1, 2, 5, 3, 4, null, 6]
//输出：[1, null, 2, null, 3, null, 4, null, 5, null, 6]
//示例 2：
//输入：root = []
//输出：[]
//示例 3：
//输入：root = [0]
//输出：[0]
//提示：
//树中结点数在范围[0, 2000] 内
//- 100 <= Node.val <= 100
//进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？

//方法一：递归
struct TreeNode* PostOrder(struct TreeNode* root) {
	if (!root)
		return NULL;
	struct TreeNode* l = PostOrder(root->left);
	struct TreeNode* r = PostOrder(root->right);
	if (!l) {
		return root;
	}
	struct TreeNode* tmp = l;
	while (tmp && tmp->right) {
		tmp = tmp->right;
	}
	root->left = NULL;
	root->right = l;
	if (tmp) {
		tmp->left = NULL;
		tmp->right = r;
	} 
	return root;
}

void flatten1(struct TreeNode* root) {
	if (!root)
		return;
	PostOrder(root);
}

//方法二：栈
void flatten(struct TreeNode* root) {
	if (!root)
		return;
	struct TreeNode* l = root->left;
	struct TreeNode* r = root->right;
	if (!l && !r)
		return;
	struct TreeNode* S[1000] = { 0 };
	int top = 0;
	struct TreeNode* tmp = root;
	while (l || r || top) {
		if (r)
			S[top++] = r;
		tmp->left = NULL;
		tmp->right = l;
		if(l)
			tmp = l; 
		else {
			r = S[--top];
			tmp->right = r;
			tmp = r;
		}
		l = tmp->left;
		r = tmp->right;
	}
}