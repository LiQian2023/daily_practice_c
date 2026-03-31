#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.03.31力扣网刷题
//3875. 构造奇偶一致的数组 I——中级工程师、数组、数学、第494场周赛——简单
//给你一个长度为 n 的数组 nums1，其中包含 互不相同 的整数。
//你需要构造另一个长度为 n 的数组 nums2，使得 nums2 中的元素要么全部为 奇数，要么全部为 偶数。
//对于每个下标 i，你必须从以下两种选择中 任选其一（顺序不限）：
//nums2[i] = nums1[i]
//nums2[i] = nums1[i] - nums1[j]，其中 j != i
//如果能够构造出满足条件的数组，则返回 true；否则，返回 false。
//示例 1：
//输入： nums1 = [2, 3]
//输出： true
//解释：
//选择 nums2[0] = nums1[0] - nums1[1] = 2 - 3 = -1。
//选择 nums2[1] = nums1[1] = 3。
//nums2 = [-1, 3]，两个元素均为奇数。因此答案为 true。
//示例 2：
//输入： nums1 = [4, 6]
//输出： true
//解释：​​​​​​​
//选择 nums2[0] = nums1[0] = 4。
//选择 nums2[1] = nums1[1] = 6。
//nums2 = [4, 6]，两个元素均为偶数。因此答案为 true。
//提示：
//1 <= n == nums1.length <= 100
//1 <= nums1[i] <= 100
//nums1 中的所有整数互不相同。

bool uniformArray(int* nums1, int nums1Size) {
	return true;
}