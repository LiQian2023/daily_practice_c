#include <stdio.h>

//2026.05.24力扣网刷题
//3936. 将 0 移到末尾的最少交换次数——中级工程师、第183场双周赛——简单
//给你一个整数数组 nums 。
//在一步操作中，你可以选择任意两个 不同 的下标 i 和 j 并交换 nums[i] 和 nums[j] 。
//返回将所有 0 移动到数组末尾所需的 最少 操作次数。
//示例 1：
//输入： nums = [0, 1, 0, 3, 12]
//输出： 2
//解释：
//我们执行以下交换操作：
//交换 nums[0] 和 nums[3] ，得到 nums = [3, 1, 0, 0, 12] 。
//交换 nums[2] 和 nums[4] ，得到 nums = [3, 1, 12, 0, 0] 。
//因此，答案是 2 。
//示例 2：
//输入： nums = [0, 1, 0, 2]
//输出： 1
//解释：
//我们执行以下交换操作：
//交换 nums[0] 和 nums[3] ，得到 nums = [2, 1, 0, 0] 。
//因此，答案是 1 。
//示例 3：
//输入： nums = [1, 2, 0]
//输出： 0
//解释：
//数组已经满足条件。因此，不需要任何交换操作。
//提示：
//1 <= nums.length <= 100
//0 <= nums[i] <= 100
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int minimumSwaps(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1, ans = 0;
    while (l < r) {
        if (nums[r] != 0) {
            while (l < r && nums[l] != 0) {
                l += 1;
            }
            if (l < r) {
                Swap(&nums[l], &nums[r]);
                ans += 1;
            }
        }
        r -= 1;
    }
    return ans;
}