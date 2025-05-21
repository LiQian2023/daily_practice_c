#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.21力扣网刷题
//两数之和 IV - 输入二叉搜索树——树、深度优先搜索、广度优先搜索、二叉搜索树、哈希表、双指针、二叉树——简单
//给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。
//示例 1：
//输入 : root = [5, 3, 6, 2, 4, null, 7], k = 9
//输出 : true
//示例 2：
//输入 : root = [5, 3, 6, 2, 4, null, 7], k = 28
//输出 : false
//提示 :
//二叉树的节点个数的范围是[1, 10^4].
//- 10^4 <= Node.val <= 10^4
//题目数据保证，输入的 root 是一棵 有效 的二叉搜索树
//- 10^5 <= k <= 10^5

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TN;
void visit(TN* root, int* hash, int min) {
    int key = root->val - min;
    hash[key] += 1;
}
void dfs(TN* root, int* hash, int min) {
    if (root) {
        visit(root, hash, min);
        dfs(root->left, hash, min);
        dfs(root->right, hash, min);
    }
}
void Get_Boundary(TN* root, int* max, int* min) {
    if (root) {
        if (root->val > *max) {
            *max = root->val;
        }
        else if (root->val < *min) {
            *min = root->val;
        }
        Get_Boundary(root->left, max, min);
        Get_Boundary(root->right, max, min);
    }
}
bool findTarget(struct TreeNode* root, int k) {
    int max = root->val, min = root->val;
    Get_Boundary(root, &max, &min);
    int size = max - min + 1;
    int* hash = (int*)calloc(size, sizeof(int));
    assert(hash);
    dfs(root, hash, min);
    bool flag = false;
    if (k - max <= max) {
        for (int i = min; i <= max; i++) {
            int key1 = i - min;
            if (hash[key1]) {
                hash[key1] -= 1;
                int key2 = k - key1 - 2 * min;
                if (key2 >= 0 && key2 < size && hash[key2]) {
                    flag = true;
                    break;
                }
                hash[key1] += 1;
            }
        }
    }
    free(hash);
    hash = NULL;
    return flag;
}