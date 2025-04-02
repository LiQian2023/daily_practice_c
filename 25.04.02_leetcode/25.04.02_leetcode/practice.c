#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2025.04.02力扣网刷题
//有序三元组中的最大值 I——数组——简单
//给你一个下标从 0 开始的整数数组 nums 。
//请你从所有满足 i < j < k 的下标三元组(i, j, k) 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 0 。
//下标三元组(i, j, k) 的值等于(nums[i] - nums[j]) * nums[k] 。
//示例 1：
//输入：nums = [12, 6, 1, 2, 7]
//输出：77
//解释：下标三元组(0, 2, 4) 的值是(nums[0] - nums[2]) * nums[4] = 77 。
//可以证明不存在值大于 77 的有序下标三元组。
//示例 2：
//输入：nums = [1, 10, 3, 4, 19]
//输出：133
//解释：下标三元组(1, 2, 4) 的值是(nums[1] - nums[2]) * nums[4] = 133 。
//可以证明不存在值大于 133 的有序下标三元组。
//示例 3：
//输入：nums = [1, 2, 3]
//输出：0
//解释：唯一的下标三元组(0, 1, 2) 的值是一个负数，(nums[0] - nums[1]) * nums[2] = -3 。因此，答案是 0 。
//提示：
//3 <= nums.length <= 100
//1 <= nums[i] <= 10^6

long long maximumTripletValue(int* nums, int numsSize) {
    // 最大值作为分界线
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > nums[max]) {
            max = i;
        }
    }
    int left[2] = { 0 }; // 左侧找最大差值
    // 左侧
    if (max >= 2) {
        for (int i = 0; i < max - 1; i++) {
            for (int j = i + 1; j < max; j++) {
                int tmp = nums[left[0]] - nums[left[1]];
                if (nums[i] - nums[j] > tmp) {
                    left[0] = i;
                    left[1] = j;
                }
            }
        }
    }
    int right[2] = { -1, -1 }; // 右侧找最小值与最大值
    // 右侧
    if (max < numsSize - 2) {
        for (int i = max + 1; i < numsSize - 1; i++) {
            int tmp[2] = { right[0], right[1] };
            if (tmp[0] == -1 || nums[i] < nums[tmp[0]]) {
                tmp[0] = i;
                for (int j = i + 1; j < numsSize; j++) {
                    if (tmp[1] == -1 || tmp[1] <= tmp[0] ||
                        nums[j] > nums[tmp[1]]) {
                        tmp[1] = j;
                    }
                }
            }
            if (right[0] == -1 || (long long)(nums[max] - nums[right[0]]) *
                (long long)nums[right[1]] <
                (long long)(nums[max] - nums[tmp[0]]) *
                (long long)nums[tmp[1]]) {
                right[0] = tmp[0];
                right[1] = tmp[1];
            }
        }
    }
    // 无左侧
    if (max < 2) {
        if (right[0] != -1) {
            return (long long)(nums[max] - nums[right[0]]) *
                (long long)nums[right[1]];
        }
        return 0;
    }
    // 无右侧
    if (max >= numsSize - 2) {
        if (nums[left[0]] - nums[left[1]] > 0)
            return (long long)(nums[left[0]] - nums[left[1]]) *
            (long long)nums[max];
        return 0;
    }
    // 即有左侧，也有右侧
    long long tmp1 =
        (long long)(nums[left[0]] - nums[left[1]]) * (long long)nums[max];
    long long tmp2 =
        (long long)(nums[max] - nums[right[0]]) * (long long)nums[right[1]];
    return tmp1 > tmp2 ? tmp1 : tmp2;
}