#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.06.04力扣网刷题
//二叉树的堂兄弟节点——树、深度优先搜索、广度优先搜索、二叉树——简单
//在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k + 1 处。
//如果二叉树的两个节点深度相同，但 父节点不同 ，则它们是一对堂兄弟节点。
//我们给出了具有唯一值的二叉树的根节点 root ，以及树中两个不同节点的值 x 和 y 。
//只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true 。否则，返回 false。
//示例 1：
//输入：root = [1, 2, 3, 4], x = 4, y = 3
//输出：false
//示例 2：
//输入：root = [1, 2, 3, null, 4, null, 5], x = 5, y = 4
//输出：true
//示例 3：
//输入：root = [1, 2, 3, null, 4], x = 2, y = 3
//输出：false
//提示：
//二叉树的节点数介于 2 到 100 之间。
//每个节点的值都是唯一的、范围为 1 到 100 的整数。

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TN;
#define MAXSIZE 100
typedef struct Queue {
    TN* Q[MAXSIZE];                         // 数据域
    int front, rear;                        // 队首指针、队尾指针
}Queue;
bool isCousins(struct TreeNode* root, int x, int y) {
    Queue q = { 0 };                              // 队列
    q.Q[0] = root;
    q.rear = 1;
    int index_x = 0, index_y = 0;
    int parent_x = -1, parent_y = -1;
    int level = 1;
    int num = 1;
    int next_num = 0;
    while (!index_x || !index_y) {
        while (num) {
            // 队首元素出队
            TN* p = q.Q[q.front];
            q.front = (q.front + 1) % MAXSIZE;
            num -= 1;
            // 访问队首元素
            if (p->val == x) {
                index_x = level;
            }
            else if (p->val == y) {
                index_y = level;
            }
            // 孩子入队
            if (p->left) {
                q.Q[q.rear] = p->left;
                q.rear = (q.rear + 1) % MAXSIZE;
                next_num += 1;
                if (p->left->val == x) {
                    parent_x = p->val;
                }
                else if (p->left->val == y) {
                    parent_y = p->val;
                }
            }
            if (p->right) {
                q.Q[q.rear] = p->right;
                q.rear = (q.rear + 1) % MAXSIZE;
                next_num += 1;
                if (p->right->val == x) {
                    parent_x = p->val;
                }
                else if (p->right->val == y) {
                    parent_y = p->val;
                }
            }
        }
        level += 1;
        num = next_num;
        next_num = 0;
    }
    return index_x == index_y && parent_x != parent_y;
}