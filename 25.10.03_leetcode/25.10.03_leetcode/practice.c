#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

//2025.10.03力扣网刷题
//将数组分成和相等的三个部分——贪心、数组、第129场周赛——简单
//给你一个整数数组 arr，只有可以将其划分为三个和相等的 非空 部分时才返回 true，否则返回 false。
//形式上，如果可以找出索引 i + 1 < j 且满足(arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1]) 就可以将数组三等分。
//示例 1：
//输入：arr = [0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1]
//输出：true
//解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
//示例 2：
//输入：arr = [0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1]
//输出：false
//示例 3：
//输入：arr = [3, 3, 6, 5, -2, 2, 5, 1, -9, 4]
//输出：true
//解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
//提示：
//3 <= arr.length <= 5 * 10^4
//- 10^4 <= arr[i] <= 10^4


bool canThreePartsEqualSum(int* arr, int arrSize) {
	int left = arr[0], mid = 0, right = arr[arrSize - 1];
	for (int i = 1; i < arrSize - 1; i++) {
		mid += arr[i];
	}
	for (int i = 0, j = arrSize - 1; i < j - 1;) {
		if (left == mid && mid == right) {
			return true;
		}
		if ((left < mid && left <= right) || (left > mid && left >= right)) {
			i += 1;
			left += arr[i];
			mid -= arr[i];
		}
		else if ((right < mid && right <= left) || (right > mid && right >= left)) {
			j -= 1;
			right += arr[j];
			mid -= arr[j];
		}
	}
	return false;
}