#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.13力扣网刷题
//LCR 150. 彩灯装饰记录 II——树、广度优先搜索、二叉树——简单
//一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从左到右的顺序返回每一层彩灯编号，每一层的结果记录于一行。
//示例 1：
//输入：root = [8, 17, 21, 18, null, null, 6]
//输出： [[8], [17, 21], [18, 6]]
//提示：
//节点总数 <= 1000
//注意：本题与主站 102 题相同：https://leetcode.cn/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 */
 /**
  * Return an array of arrays of size *returnSize.
  * The sizes of the arrays are returned as *returnColumnSizes array.
  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
  */

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TN;
typedef struct Queue {
	TN** data;
	int front;
	int rear;
	int len;
	int baseSize;
}Queue;
Queue* Create() {
	Queue* queue = (Queue*)calloc(1, sizeof(Queue));
	assert(queue);
	queue->baseSize = 4;
	queue->data = (TN**)calloc(queue->baseSize, sizeof(TN*));
	assert(queue->data);
	queue->front = 0;
	queue->rear = 0;
	queue->len = 0;
	return queue;
}
void Destroy(Queue** q) {
	free((*q)->data);
	(*q)->data = NULL;
	free(*q);
	*q = NULL;
}
void Push(Queue* q, TN* node) {
	if (q->len == q->baseSize) {
		int newSize = q->baseSize + q->baseSize / 2;
		TN** tmp = (TN**)calloc(newSize, sizeof(TN*));
		assert(tmp);
		for (int i = q->front, j = 0; j < q->len; i = (i + 1) % q->baseSize) {
			tmp[j] = q->data[i];
			j += 1;
		}
		free(q->data);
		q->data = tmp;
		q->front = 0;
		q->rear = q->len;
		q->baseSize = newSize;
	}
	q->data[q->rear] = node;
	q->rear = (q->rear + 1) % q->baseSize;
	q->len += 1;
}
TN* Pop(Queue* q) {
	if (q->len == 0) {
		return NULL;
	}
	TN* node = q->data[q->front];
	q->front = (q->front + 1) % q->baseSize;
	q->len -= 1;
	return node;
}
int getLevel(TN* root) {
	if (!root) {
		return 0;
	}
	int left = getLevel(root->left);
	int right = getLevel(root->right);
	return left > right ? left + 1 : right + 1;
}
void RecordLevel(int** ans, int* tmp, int level, int size) {
	ans[level] = (int*)calloc(size, sizeof(int));
	assert(ans[level]);
	for (int i = 0; i < size; i++) {
		ans[level][i] = tmp[i];
	}
}
void Print(int* nums, int len) {
	printf("[");
	for (int i = 0; i < len; i++) {
		if (i == len - 1) {
			printf("%d", nums[i]);
		}
		else {
			printf("%d, ", nums[i]);
		}
	}
	printf("]\n\n");
}
void Print_Tree(Queue* q) {
	for (int i = q->front; i != q->rear; i = (i + 1) % q->baseSize) {
		printf("Print_Tree: val = %d, left = %p, right = %p\n", q->data[i]->val, q->data[i]->left, q->data[i]->right);
	}
}
int** decorateRecord(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	Queue* q = Create();
	*returnSize = getLevel(root);
	int** ans = (int**)calloc(*returnSize, sizeof(int*));
	assert(ans);
	*returnColumnSizes = (int*)calloc(*returnSize, sizeof(int));
	assert(*returnColumnSizes);
	int cur = 0, next = 0;
	int level = 0;
	if (root) {
		Push(q, root);
		cur += 1;
		while (q->len) {
			(*returnColumnSizes)[level] = cur;
			int* tmp = (int*)calloc(cur, sizeof(int));
			assert(tmp);
			int size = 0;
			while (cur) {
				TN* node = Pop(q);
				cur -= 1;
				if (node) {
					tmp[size] = node->val;
					size += 1;
					if (node->left) {
						Push(q, node->left);
						next += 1;
					}
					if (node->right) {
						Push(q, node->right);
						next += 1;
					}
				}
			}
			RecordLevel(ans, tmp, level, size);
			free(tmp);
			cur = next;
			next = 0;
			level += 1;
		}
	}
	Destroy(&q);
	return ans;
}