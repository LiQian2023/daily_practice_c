#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.02.24力扣网刷题
//1022. 从根到叶的二进制数之和——资深工程师、树、深度优先搜索、二叉树、第131场周赛——简单
//给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。
//例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
//对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
//返回这些数字之和。题目数据保证答案是一个 32 位 整数。
//示例 1：
//输入：root = [1, 0, 1, 0, 1, 0, 1]
//输出：22
//解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
//示例 2：
//输入：root = [0]
//输出：0
//提示：
//树中的节点数在[1, 1000] 范围内
//Node.val 仅为 0 或 1

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TN;
void Print(int* num, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d, ", num[i]);
    }
    printf("\n");
}
void dfs(TN* root, int* parent, int* leaf, int* plen, int* llen) {
    if (!root) {
        return;
    }
	if (root->left == NULL && root->right == NULL) {
        leaf[*llen] = parent[*plen - 1] * 2 + root->val;
        *llen += 1;
        print("leaf:");
        Print(leaf, *llen);
        return;
    }
    print("parent_val:");
    Print(parent, *plen);
    parent[*plen] = parent[*plen - 1] * 2 + root->val;
    *plen += 1;
    print("parent_left:");
    Print(parent, *plen);
    dfs(root->left, parent, leaf, plen, llen);
    print("parent_right:");
    Print(parent, *plen);
    dfs(root->right, parent, leaf, plen, llen);
    *plen -= 1;
    print("parent_back:");
    Print(parent, *plen);
}
int getSize(TN* root) {
    if (!root) {
        return 0;
    }
    int left = getSize(root->left);
    int right = getSize(root->right);
    return left + right + 1;
}
int getLeaf(TN* root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return 1;
    }
    int left = getLeaf(root->left);
    int right = getLeaf(root->right);
    return left + right;
}
int sumRootToLeaf(struct TreeNode* root) {
    int size = getSize(root);
    int* parent = (int*)calloc(size + 1, sizeof(int));
    assert(parent);
    int lSize = getLeaf(root);
    int* leaf = (int*)calloc(lSize, sizeof(int));
    assert(lSize);
    int plen = 1, llen = 0;
    dfs(root, parent, leaf, &plen, &llen);
    int ans = 0;
    for (int i = 0; i < lSize; i++) {
        ans += leaf[i];
    }
    free(parent);
    free(leaf);
    return ans;
}