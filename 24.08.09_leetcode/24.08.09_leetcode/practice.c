#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//2024.08.09力扣网刷题
// 找出与数组相加的整数 II——数组、双指针、枚举、排序——中等
//给你两个整数数组 nums1 和 nums2。
//从 nums1 中移除两个元素，并且所有其他元素都与变量 x 所表示的整数相加。如果 x 为负数，则表现为元素值的减少。
//执行上述操作后，nums1 和 nums2 相等 。当两个数组中包含相同的整数，并且这些整数出现的频次相同时，两个数组 相等 。
//返回能够实现数组相等的 最小 整数 x 。
//示例 1:
//输入：nums1 = [4, 20, 16, 12, 8], nums2 = [14, 18, 10]
//输出： - 2
//解释：
//移除 nums1 中下标为[0, 4] 的两个元素，并且每个元素与 - 2 相加后，nums1 变为[18, 14, 10] ，与 nums2 相等。
//示例 2:
//输入：nums1 = [3, 5, 5, 3], nums2 = [7, 7]
//输出：2
//解释：
//移除 nums1 中下标为[0, 3] 的两个元素，并且每个元素与 2 相加后，nums1 变为[7, 7] ，与 nums2 相等。
//提示：
//3 <= nums1.length <= 200
//nums2.length == nums1.length - 2
//0 <= nums1[i], nums2[i] <= 1000
//测试用例以这样的方式生成：存在一个整数 x，nums1 中的每个元素都与 x 相加后，再移除两个元素，nums1 可以与 nums2 相等。

//方法一：计数排序 + 模拟
void CountSort(int* a, int len) {
	int num[1001] = { 0 };
	int max = a[0];
	int min = a[0];
	//计数
	for (int i = 0; i < len; i++) {
		num[a[i]] += 1;
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	len = 0;
	//排序
	for (int i = min; i <= max; i++) {
		while (num[i]) {
			a[len++] = i;
			num[i] -= 1;
		}
	}
}

int minimumAddedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	CountSort(nums1, nums1Size);
	CountSort(nums2, nums2Size);
	int ans = 1001;
	for (int i = 0; i < nums1Size; i++) {
		int x = nums2[0] - nums1[i];
		int flag = 0;
		for (int j = 0, z = 0; j < nums1Size && z < nums2Size; j++, z++) {
			while (j < nums1Size && nums1[j] + x != nums2[z]) {
				j += 1;
				flag += 1;
			}
			if (z == nums2Size - 1 && flag < 2) {
				flag = 2;
			}
			if (flag > 2)
				break;
		}
		if (flag == 2 && x < ans) {
			ans = x;
		}
	}
	return ans;
}

void test() {
	int a[10] = { 15,20,16,12,11 };
	int b[10] = { 14,15,10 };
	int len1 = 5;
	int len2 = 3;
	printf("%d\n", minimumAddedInteger(a, len1, b, len2));
}

int main() {
	test();
	return 0;
}