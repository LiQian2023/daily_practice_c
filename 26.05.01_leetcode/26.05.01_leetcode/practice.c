#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.01力扣网刷题
//LCP 72. 补给马车——简单
//远征队即将开启未知的冒险之旅，不过在此之前，将对补给车队进行最后的检查。supplies[i] 表示编号为 i 的补给马车装载的物资数量。 考虑到车队过长容易被野兽偷袭，他们决定将车队的长度变为原来的一半（向下取整），计划为：
//找出车队中 物资之和最小 两辆 相邻 马车，将它们车辆的物资整合为一辆。若存在多组物资之和相同的马车，则取编号最小的两辆马车进行整合；
//重复上述操作直到车队长度符合要求。
//请返回车队长度符合要求后，物资的分布情况。
//示例 1：
//输入：supplies = [7, 3, 6, 1, 8]
//输出：[10, 15]
//解释： 第 1 次合并，符合条件的两辆马车为 6, 1，合并后的车队为[7, 3, 7, 8]； 第 2 次合并，符合条件的两辆马车为(7, 3) 和(3, 7)，取编号最小的(7, 3)，合并后的车队为[10, 7, 8]； 第 3 次合并，符合条件的两辆马车为 7, 8，合并后的车队为[10, 15]； 返回[10, 15]
//
//示例 2：
//输入：supplies = [1, 3, 1, 5]
//输出：[5, 5]
//解释：
//2 <= supplies.length <= 1000
//1 <= supplies[i] <= 1000

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* supplyWagon(int* supplies, int suppliesSize, int* returnSize) {
	int* tmp = (int*)calloc(suppliesSize, sizeof(int));
	assert(tmp);
	for (int i = 0; i < suppliesSize; i++) {
		tmp[i] = supplies[i];
	}
	*returnSize = suppliesSize / 2;
	for (int size = suppliesSize; size > *returnSize; size--) {
		// 获取最小值
		int min = tmp[0] + tmp[1];
		int pi = 0;
		for (int i = 0; i < size - 1; i++) {
			if (tmp[i] + tmp[i + 1] < min) {
				min = tmp[i] + tmp[i + 1];
				pi = i;
			}
		}
		// 合并
		for (int i = 0; i < size - 1; i++) {
			if (i == pi) {
				tmp[i] += tmp[i + 1];
				for (i += 1; i < size - 1; i++) {
					tmp[i] = tmp[i + 1];
				}
			}
		}
	}
	int* ans = (int*)calloc(*returnSize, sizeof(int));
	assert(ans);
	for (int i = 0; i < *returnSize; i++) {
		ans[i] = tmp[i];
	}
	free(tmp);
	return ans;
}