#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//2024.09.08力扣网刷题
//训练计划 I——数组、双指针、排序——简单
//教练使用整数数组 actions 记录一系列核心肌群训练项目编号。
//为增强训练趣味性，需要将所有奇数编号训练项目调整至偶数编号训练项目之前。
//请将调整后的训练项目编号以 数组 形式返回。
//示例 1：
//输入：actions = [1, 2, 3, 4, 5]
//输出：[1, 3, 5, 2, 4]
//解释：为正确答案之一
//提示：
//0 <= actions.length <= 50000
//0 <= actions[i] <= 10000

int* trainingPlan(int* actions, int actionsSize, int* returnSize) {
	int* ans = (int*)calloc(actionsSize, sizeof(int));
	assert(ans);
	*returnSize = actionsSize;
	int l = 0, r = actionsSize - 1;
	for (int i = 0; i < actionsSize; i++) {
		if (actions[i] % 2) {
			ans[l++] = actions[i];
		}
		else {
			ans[r--] = actions[i];
		}
	}
	return ans;
}