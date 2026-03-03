#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.03.03力扣网刷题
//590. N 叉树的后序遍历——栈、树、深度优先搜索——简单
//给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。
//n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
//示例 1：
//输入：root = [1, null, 3, 2, 4, null, 5, 6]
//输出：[5, 6, 3, 2, 4, 1]
//示例 2：
//输入：root = [1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14]
//输出：[2, 6, 14, 11, 7, 3, 12, 8, 4, 13, 9, 10, 5, 1]
//提示：
//节点总数在范围[0, 10^4] 内
//0 <= Node.val <= 10^4
//n 叉树的高度小于或等于 1000
//进阶：递归法很简单，你可以使用迭代法完成此题吗 ?

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};
typedef struct Node NTN;
void dfs(NTN* root, int* ans, int* pi) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->numChildren; i++) {
        dfs(root->children[i], ans, pi);
    }
    ans[*pi] = root->val;
    *pi += 1;
}
int getSize(NTN* root) {
    if (!root) {
        return 0;
    }
    int child = 0;
    for (int i = 0; i < root->numChildren; i++) {
        child += getSize(root->children[i]);
    }
    return child + 1;
}
int* postorder(struct Node* root, int* returnSize) {
    *returnSize = getSize(root);
    int* ans = (int*)calloc(*returnSize, sizeof(int));
    assert(ans);
    int i = 0;
    dfs(root, ans, &i);
    return ans;
}