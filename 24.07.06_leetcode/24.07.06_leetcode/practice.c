#define _CRT_SECURE_NO_WARNINGS 1

#include "BiTree.h"

//2024.07.06力扣网刷题
//使所有元素都可以被 3 整除的最少操作数——数组、数学——简单
//给你一个整数数组 nums 。一次操作中，你可以将 nums 中的 任意 一个元素增加或者减少 1 。
//请你返回将 nums 中所有元素都可以被 3 整除的 最少 操作次数。
//示例 1：
//输入：nums = [1, 2, 3, 4]
//输出：3
//解释：
//通过以下 3 个操作，数组中的所有元素都可以被 3 整除：
//将 1 减少 1 。
//将 2 增加 1 。
//将 4 减少 1 。
//示例 2：
//输入：nums = [3, 6, 9]
//输出：0
//提示：
//1 <= nums.length <= 50
//1 <= nums[i] <= 50
int minimumOperations(int* nums, int numsSize) {
	int ans = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] % 3)
			ans++;
	}
	return ans;
}

#if 0

// 二叉树的所有路径——树、深度优先搜索、字符串、回溯、二叉树——简单
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

typedef struct TreeNode TN;

void Visit(TN* root, char** ans, int* pi) {
	ans[*pi] = (char*)calloc(2, sizeof(char));
	assert(ans[*pi]);
	ans[*pi][0] = root->val + '0';
	ans[*pi][1] = '\0';
	*pi += 1;
}
void Connect(char** ans, int* pi, char* tmp) {
	for (*pi; *pi > 0; *pi -= 1) {
		if (ans[*pi] != "") {
			strcat(ans[*pi - 2], tmp);
			strcat(ans[*pi - 2], ans[*pi - 1]);
		}
		free(ans[*pi]);
	}
}
char* PreOrder(TN* root, char** ans, int* pi, char* tmp) {
	if (!root) {
		ans[*pi] = (char*)calloc(1, sizeof(char));
		assert(ans[*pi]);
		ans[*pi] = "";
		*pi += 1;
		return;
	}
	char* l = PreOrder(root->left, ans, pi, tmp);
	char* r = PreOrder(root->right, ans, pi, tmp);
	Visit(root, ans, pi);
	Connect(ans, pi, tmp);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
	char** ans = (char**)calloc(100, sizeof(char*));
	assert(ans);
	char* tmp = "->";
	ans[0] = PreOrder(root, ans, returnSize, tmp);
	return ans;
}


//最长回文子串——双指针、字符串、动态规划——中等
//给你一个字符串 s，找到 s 中最长的回文子串。
//示例 1：
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
//示例 2：
//输入：s = "cbbd"
//输出："bb"
//提示：
//1 <= s.length <= 1000
//s 仅由数字和英文字母组成

//方法一：模拟
bool isPalindrome(char* s, int l, int r) {
	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++, r--;
	}
	return true;
}

char* longestPalindrome(char* s) {
	int len = strlen(s);
	int min = len / 2;
	int l = min, r = min;
	if (len % 2 == 0) {
		min -= 1;
		l = min;
	}

}

void test() {
	char s[1000] = { 0 };
	while (scanf("%s", s) == 1) {
		char* ret = longestPalindrome(s);
		printf("%s\n", ret);
		free(ret);
	}
}
#endif


int main() {
	test();
	return 0;
}