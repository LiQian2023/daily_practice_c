#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//2025.09.19力扣网刷题
//汇总区间——数组——简单
//给定一个  无重复元素 的 有序 整数数组 nums 。
//区间[a, b] 是从 a 到 b（包含）的所有整数的集合。
//返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个区间但不属于 nums 的数字 x 。
//列表中的每个区间范围[a, b] 应该按如下格式输出：
//"a->b" ，如果 a != b
//"a" ，如果 a == b
//示例 1：
//输入：nums = [0, 1, 2, 4, 5, 7]
//输出：["0->2", "4->5", "7"]
//解释：区间范围是：
//[0, 2] -- > "0->2"
//[4, 5] -- > "4->5"
//[7, 7] -- > "7"
//示例 2：
//输入：nums = [0, 2, 3, 4, 6, 8, 9]
//输出：["0", "2->4", "6", "8->9"]
//解释：区间范围是：
//[0, 0] -- > "0"
//[2, 4] -- > "2->4"
//[6, 6] -- > "6"
//[8, 9] -- > "8->9"
//提示：
//0 <= nums.length <= 20
//- 2^31 <= nums[i] <= 2^31 - 1
//nums 中的所有值都 互不相同
//nums 按升序排列
int get_size(int num) {
	int n = 1;
	long long elem = (long long)num;
	if (elem < 0) {
		n += 1;
		elem *= -1;
	}
	while (elem >= 10) {
		n += 1;
		elem /= 10;
	}
	return n;
}
void append(char** ans, int* returnSize, int num, int* size) {
	int n = get_size(num);
	long long elem = (long long)num;
	if (elem < 0) {
		ans[*returnSize][*size] = '-';
		*size += 1;
		elem *= -1;
		n -= 1;
	}
	for (*size; n; *size += 1, n -= 1) {
		int div = (int)pow(10, n - 1);
		ans[*returnSize][*size] = elem / div + '0';
		elem %= div;
	}
}
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
	char** ans = (char**)calloc(numsSize, sizeof(char*));
	assert(ans);
	*returnSize = 0;
	if (numsSize) {
		int begin = nums[0], end = nums[0];
		for (int i = 1; i <= numsSize; i++) {
			while (i < numsSize && end + 1 == nums[i]) {
				end = nums[i];
				i += 1;
			}
			int size = get_size(begin);
			if (begin < 0) {
				size += 1;
			}
			if (begin != end) {
				size += get_size(end) + 2;
				if (end < 0) {
					size += 1;
				}
			}
			ans[*returnSize] = (char*)calloc(size + 1, sizeof(char));
			assert(ans[*returnSize]);
			int pi = 0;
			append(ans, returnSize, begin, &pi);
			if (begin != end) {
				ans[*returnSize][pi] = '-';
				ans[*returnSize][pi + 1] = '>';
				pi += 2;
				append(ans, returnSize, end, &pi);
			}
			*returnSize += 1;
			if (i == numsSize) {
				break;
			}
			begin = end = nums[i];
		}
	}
	return ans;
}