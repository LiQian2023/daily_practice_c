#include <stdio.h>
#include <string.h>
#include <ctype.h>

//2026.08.08力扣网刷题
//4010. 数对的最大强度——中级工程师、第513场周赛——中等
//给你一个整数数组 nums。
//选择 恰好一对 不同下标 i 和 j。该数对的 强度 定义为：
//(nums[i] * nums[j]) / gcd(nums[i], nums[j])2
//返回所有可能数对中的 最大 强度。
//gcd(a, b) 表示 a 和 b 的 最大公约数 。
//示例 1：
//输入： nums = [2, 3, 5]
//输出： 15
//解释：
//选择 i = 1 和 j = 2，得到强度：
//(3 * 5) / gcd(3, 5)2 = 15 / 1 = 15，这是所有数对中的最大值。
//示例 2：
//输入： nums = [4, 6, 8]
//输出： 12
//解释：
//选择 i = 1 和 j = 2，得到强度：
//(6 * 8) / gcd(6, 8)2 = 48 / 4 = 12，这是所有数对中的最大值。
//示例 3：
//输入： nums = [3, 3]
//输出： 1
//解释：
//选择 i = 0 和 j = 1，得到强度：
//(3 * 3) / gcd(3, 3)2 = 9 / 9 = 1，这是唯一数对的强度。
//提示：
//2 <= nums.length <= 2000
//1 <= nums[i] <= 10^5

long long gcd(int a, int b) {
    int max = a > b ? a : b, min = a > b ? b : a;
    while (max && min && max % min) {
        int tmp = max % min;
        max = min;
        min = tmp;
    }
    return min;
}
long long maxPairStrength(int* nums, int numsSize) {
    long long ans = -1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            long long g = gcd(nums[i], nums[j]);
            long long tmp = (long long)nums[i] * (long long)nums[j] / (g * g);
            if (tmp > ans) {
                ans = tmp;
            }
        }
    }
    return ans;
}