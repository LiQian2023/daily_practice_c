#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//2024.09.30力扣网刷题
//最大间距——数组、桶排序、基数排序、排序——中等
//给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。
//您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
//示例 1:
//输入: nums = [3, 6, 9, 1]
//输出 : 3
//解释 : 排序后的数组是[1, 3, 6, 9], 其中相邻元素(3, 6) 和(6, 9) 之间都存在最大差值 3。
//示例 2 :
//输入 : nums = [10]
//输出 : 0
//解释 : 数组元素个数小于 2，因此返回 0。
//提示 :
//1 <= nums.length <= 10^5
//0 <= nums[i] <= 10^9

int cmp(const void* p1, const void* p2) {
	return *(int*)p1 - *(int*)p2;
}
int maximumGap1(int* nums, int numsSize) {
	ShellSort(nums, numsSize);
	int max = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] - nums[i - 1] > max)
			max = nums[i] - nums[i - 1];
	}
	return max;
}

int maximumGap2(int* nums, int numsSize) {
	ShellSort(nums, numsSize);
	int max = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] - nums[i - 1] > max)
			max = nums[i] - nums[i - 1];
	}
	return max;
}

int maximumGap3(int* nums, int numsSize) {
	HeapSort(nums, numsSize);
	int max = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] - nums[i - 1] > max)
			max = nums[i] - nums[i - 1];
	}
	return max;
}
void test() {
	int arr[53] = { 494767408,862126209,213511142,768240025,631263193,839199222,990848796,214568815,540853864,760724418,980162605,976743981,168965760,680875496,256709197,970953816,948680062,347254784,732201399,786249847,782805044,40906641,674241381,784330934,175502610,731105392,424650824,549764101,986090032,710542549,249208107,448419816,527708664,158499246,223421723,114552457,466978424,821491411,19614107,115389497,902211438,2644108,744489871,897895073,372311214,551142753,933294894,426217662,217504874,983488406,516890023,426853110,971124103 };
	int size = 53;
	printf("%d\n", maximumGap(arr, size));
}