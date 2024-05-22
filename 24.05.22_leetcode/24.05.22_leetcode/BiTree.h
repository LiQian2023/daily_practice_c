#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//二叉树的初始化
void BTInit(struct TreeNode* root);
//创建二叉树
struct TreeNode* Creat(int* arr, int* i, int n);
//销毁二叉树
void Destroy(struct TreeNode** root);
//功能测试
void test1();
//先序遍历二叉树
int* preorderTraversal(struct TreeNode* root, int* returnSize);
void PreOrder(struct TreeNode* root, int* ans, int* i);