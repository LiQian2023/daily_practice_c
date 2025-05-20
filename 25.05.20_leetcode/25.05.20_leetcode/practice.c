#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.20力扣网刷题
//开幕式焰火——树、深度优先搜索、广度优先搜索、二叉树、哈希表——简单
//「力扣挑战赛」开幕式开始了，空中绽放了一颗二叉树形的巨型焰火。 给定一棵二叉树 root 代表焰火，节点值表示巨型焰火这一位置的颜色种类。请帮小扣计算巨型焰火有多少种不同的颜色。
//示例 1：
//输入：root = [1, 3, 2, 1, null, 2]
//输出：3
//解释：焰火中有 3 个不同的颜色，值分别为 1、2、3
//示例 2：
//输入：root = [3, 3, 3]
//输出：1
//解释：焰火中仅出现 1 个颜色，值为 3
//提示：
//1 <= 节点个数 <= 1000
//1 <= Node.val <= 1000


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode TN;
void visit(TN* root, int* hash, int* ans) {
    int key = root->val;
    if (hash[key] == 0) {
        *ans += 1;
    }
    hash[key] += 1;
}
void dfs(TN* root, int* hash, int* ans) {
    if (root) {
        visit(root, hash, ans);
        dfs(root->left, hash, ans);
        dfs(root->right, hash, ans);
    }
}
int numColor(struct TreeNode* root) {
    int* hash = (int*)calloc(1001, sizeof(int));
    assert(hash);
    int ans = 0;
    dfs(root, hash, &ans);
    free(hash);
    hash = NULL;
    return ans;
}