#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//2026.02.25力扣网刷题
//257. 二叉树的所有路径——树、深度优先搜索、字符串、回溯、二叉树——简单
//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
//叶子节点 是指没有子节点的节点。
//示例 1：
//输入：root = [1, 2, 3, null, 5]
//输出：["1->2->5", "1->3"]
//示例 2：
//输入：root = [1]
//输出：["1"]
//提示：
//树中节点的数目在范围[1, 100] 内
//- 100 <= Node.val <= 100

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TN;
int getLeaf(TN* root) {
    if (!root) {
        return 0;
    }
    if(!root->left && !root->right) {
        return 1;
	}
	int left = getLeaf(root->left);
	int right = getLeaf(root->right);
	return left + right;
}
int getSize(TN* root) {
    if (!root) {
        return 0;
    }
	int left = getSize(root->left);
	int right = getSize(root->right);
	return left + right + 1;
}
int getLevel(TN* root) {
    if (!root) {
        return 0;
    }
    int left = getLevel(root->left);
    int right = getLevel(root->right);
    return left > right ? left + 1 : right + 1;
}
char** CreateArray(int row, int col) {
    char** arr = (char**)calloc(row, sizeof(char**));
    assert(arr);
    for (int i = 0; i < row; i++) {
        arr[i] = (char*)calloc((col - 1) * 2 + col * 4 + 1, sizeof(char));
        assert(arr[i]);
    }
    return arr;
}
void Destroy(char*** arr, int row) {
    for (int i = 0; i < row; i++) {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }
    free(*arr);
    *arr = NULL;
}
char* Str(int num) {
    char* tmp = (char*)calloc(5, sizeof(char));
    assert(tmp);
    int begin = 0;
    if (num < 0) {
        tmp[begin] = '-';
        begin += 1;
        num = -num;
    }
    int end = begin;
    for (end; num; end++, num /= 10) {
        tmp[end] = num % 10 + '0';
    }
    for (int l = begin, r = end - 1; l < r; l++, r--) {
        char ch = tmp[l];
        tmp[l] = tmp[r];
        tmp[r] = ch;
    }
    return tmp;
}
void dfs(TN* root, char** parents, char** paths, int* plen, int* llen) {
    if (!root) {
        return;
    }
    char* str = Str(root->val);
    if (!root->left && !root->right) {
        if (*plen == 0) {
            strcpy(paths[*llen], str);
        }
        else {
            strcpy(paths[*llen], parents[*plen - 1]);
            strncat(paths[*llen], "->", 2);
            strcat(paths[*llen], str);
        }
        *llen += 1;
        free(str);
        str = NULL;
        return;
    }
    if (*plen == 0) {
        strcpy(parents[*plen], str);
    }
    else {
        strcpy(parents[*plen], parents[*plen - 1]);
        strncat(parents[*plen], "->", 2);
        strcat(parents[*plen], str);
    }
    free(str);
    str = NULL;
    *plen += 1;
    dfs(root->left, parents, paths, plen, llen);
    dfs(root->right, parents, paths, plen, llen);
    *plen -= 1;
}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
	int plen = getSize(root);
    int level = getLevel(root);
    char** parents = CreateArray(plen, level);
	int llen = getLeaf(root);
    char** paths = CreateArray(llen, level);
    *returnSize = llen;
    int len1 = 0, len2 = 0;
    dfs(root, parents, paths, &len1, &len2);
    Destroy(&parents, plen);
    return paths;
}