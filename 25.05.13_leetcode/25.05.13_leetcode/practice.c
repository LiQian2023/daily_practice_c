#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2025.05.13力扣网刷题
//删除后的最大子数组元素和——贪心、数组、哈希表——简单
//给你一个整数数组 nums 。
//你可以从数组 nums 中删除任意数量的元素，但不能将其变为 空 数组。执行删除操作后，选出 nums 中满足下述条件的一个子数组：
//子数组中的所有元素 互不相同 。
//最大化 子数组的元素和。
//返回子数组的 最大元素和 。
//子数组 是数组的一个连续、非空 的元素序列。
//示例 1：
//输入：nums = [1, 2, 3, 4, 5]
//输出：15
//解释：
//不删除任何元素，选中整个数组得到最大元素和。
//示例 2：
//输入：nums = [1, 1, 0, 1, 1]
//输出：1
//解释：
//删除元素 nums[0] == 1、nums[1] == 1、nums[2] == 0 和 nums[3] == 1 。选中整个数组[1] 得到最大元素和。
//示例 3：
//输入：nums = [1, 2, -1, -2, 1, 0, -1]
//输出：3
//解释：
//删除元素 nums[2] == -1 和 nums[3] == -2 ，从[1, 2, 1, 0, -1] 中选中子数组[2, 1] 以获得最大元素和。
//提示：
//1 <= nums.length <= 100
//- 100 <= nums[i] <= 100

int maxSum(int* nums, int numsSize) {
    int max = nums[0], min = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
        else if (min > nums[i]) {
            min = nums[i];
        }
    }
    int size = max - min + 1;
    int* hash = (int*)calloc(size, sizeof(int));
    assert(hash);
    for (int i = 0; i < numsSize; i++) {
        int key = nums[i] - min;
        hash[key] += 1;
    }
    int ans = 0;
    int tmp = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (i + min == 0) {
            break;
        }
        if (hash[i]) {
            tmp += i + min;
        }
        if (ans == 0 || tmp > ans) {
            ans = tmp;
        }
    }
    free(hash);
    return ans;
}