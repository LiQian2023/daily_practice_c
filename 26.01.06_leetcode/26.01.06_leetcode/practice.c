#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.01.06力扣网刷题
//3718. 缺失的最小倍数——数组、哈希表、第427场周赛——简单
//给你一个整数数组 nums 和一个整数 k，请返回从 nums 中缺失的、最小的正整数 k 的倍数。
//倍数 指能被 k 整除的任意正整数。
//示例 1：
//输入： nums = [8, 2, 3, 4, 6], k = 2
//输出： 10
//解释：
//当 k = 2 时，其倍数为 2、4、6、8、10、12……，其中在 nums 中缺失的最小倍数是 10。
//示例 2：
//输入： nums = [1, 4, 7, 10, 15], k = 5
//输出： 5
//解释：
//当 k = 5 时，其倍数为 5、10、15、20……，其中在 nums 中缺失的最小倍数是 5。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
//1 <= k <= 100

int missingMultiple(int* nums, int numsSize, int k) {
	int max = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i]>max) {
			max = nums[i];
		}
	}
	int* hash = (int*)calloc(max + 1, sizeof(int));
	assert(hash);
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i];
		hash[key] += 1;
	}
	int ans = 0;
	for (int i = 1; 1; i++) {
		if (i * k > max || hash[i * k] == 0) {
			ans = i * k;
			break;
		}
	}
	free(hash);
	hash = NULL;
	return ans;
}