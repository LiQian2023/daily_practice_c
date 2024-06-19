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