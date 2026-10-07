#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//2026.10.07力扣网刷题
//4065. 移除不同值重排数组——中级工程师、数组、哈希表、计数、有序集合、排序、模拟、堆（优先队列）、第521场周赛——简单
//给你一个整数数组 nums。
//初始时，你有一个 空 数组 ans。重复执行以下操作，直到 nums 变为 空 ：
//找出当前 nums 中 所有不同 的值。
//将当前 nums 中每个 不同 的值各移除一个，并按 升序 将这些值依次添加到 ans 中。
//返回数组 ans。
//示例 1：
//输入： nums = [3, 1, 3, 2, 1, 3]
//输出：[1, 2, 3, 1, 3, 3]
//解释：
//操作	添加到 ans 的值	操作后的 nums	操作后的 ans
//1	1, 2, 3[3, 1, 3][1, 2, 3]
//2	1, 3[3][1, 2, 3, 1, 3]
//3	3[][1, 2, 3, 1, 3, 3]
//此时 nums 已为空，因此答案为[1, 2, 3, 1, 3, 3]。
//示例 2：
//输入： nums = [7, 7, 4, 4, 4]
//输出：[4, 7, 4, 7, 4]
//解释：
//操作	添加到 ans 的值	操作后的 nums	操作后的 ans
//1	4, 7[7, 4, 4][4, 7]
//2	4, 7[4][4, 7, 4, 7]
//3	4[][4, 7, 4, 7, 4]
//此时 nums 已为空，因此答案为[4, 7, 4, 7, 4]。
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 100

int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
	int max = nums[0], min = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max){
			max = nums[i];
		}
		else if (nums[i] < min) {
			min = nums[i];
		}
	}
	int size = max - min + 1;
	int* hash = (int*)calloc(size, sizeof(int));
	assert(hash);
	int dif = 0;
	for (int i = 0; i < numsSize; i++) {
		int key = nums[i] - min;
		if (!hash[key]) {
			dif += 1;
		}
		hash[key] += 1;
	}

	int* ans = (int*)calloc(numsSize, sizeof(int));
	assert(ans);
	*returnSize = 0;
	while (dif) {
		for (int i = 0; i < size; i++) {
			if (hash[i]) {
				ans[*returnSize] = i + min;
				*returnSize += 1;
				hash[i] -= 1;
				if (!hash[i]) {
					dif -= 1;
				}
			}
		}
	}
	free(hash);
	return ans;
}