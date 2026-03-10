#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.10力扣网刷题
//938. 二叉搜索树的范围和——高级工程师、树、深度优先搜索、二叉搜索树、二叉树、第110场周赛——简单
//给定二叉搜索树的根结点 root，返回值位于范围[low, high] 之间的所有结点的值的和。
//示例 1：
//输入：root = [10, 5, 15, 3, 7, null, 18], low = 7, high = 15
//输出：32
//示例 2：
//输入：root = [10, 5, 15, 3, 7, 13, 18, 1, null, 6], low = 6, high = 10
//输出：23
//提示：
//树中节点数目在范围[1, 2 * 10^4] 内
//1 <= Node.val <= 10^5
//1 <= low <= high <= 10^5
//所有 Node.val 互不相同

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TN;
void dfs(TN* root, int low, int high, int* sum) {
    if (!root) {
        return;
    }
    if (root->val >= low && root->val <= high) {
		*sum += root->val;
    }
    if (root->val >= low) {
		dfs(root->left, low, high, sum);
    }
    if (root->val <= high) {
        dfs(root->right, low, high, sum);
    }
}
int rangeSumBST(struct TreeNode* root, int low, int high) {
    int sum = 0;
    dfs(root, low, high, &sum);
    return sum;
}