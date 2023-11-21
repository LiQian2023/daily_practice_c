#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//leetcode每日练习

//找到最接近0的数字
//给你一个长度n的整数数组nums，请你返回nums中最接近0的数字。
//如果有多个答案，请你返回它们中的最大值
//输入：nums={-4,-2,1,4,8};
//输出：1;
//-4 到 0 的距离为 | -4 | = 4 。
//- 2 到 0 的距离为 | -2 | = 2 。
//1 到 0 的距离为 | 1 | = 1 。
//4 到 0 的距离为 | 4 | = 4 。
//8 到 0 的距离为 | 8 | = 8 。
//所以，数组中距离 0 最近的数字为 1 。
//输入：nums = [2, -1, 1]
//输出：1
//解释：1 和 - 1 都是距离 0 最近的数字，所以返回较大值 1 。
//1<=n<=1000
//-10^5<=nums[i]<=10^5
int findClosestNumber(int* nums, int numsSize) {
	int min = nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		if (abs(nums[i]) < abs(min))
		{
			min = nums[i];
		}
		else if ((abs(nums[i]) == abs(min)) && (nums[i] > min))
		{
			min = nums[i];
		}
	}
	return min;
}



#if 0
////栈、贪心、数组——难度中等
////美化数组的最少删除数
////给你一个下标从 0 开始的整数数组nums，
////如果满足下述条件，则认为数组nums是一个美丽数组：
////nums.length为偶数
////对所有满足i%2==0的下标i，nums[i]!=nums[i+1]均成立
////注意，空数组同样认为是美丽数组。
////你可以从nums中删除任意数量的元素。
////当你删除一个元素时，
////被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，
////而左侧的元素将会保持 不变 。
////返回使nums变为美丽数组所需删除的最少元素数目
////1<=nums.length<=10^5
////0<=nums[i]<=10^5
////输入：nums={1,1,2,3,5,}
////输出：1
////解释：可以删除nums[0]或nums[1]，这样得到的nums={1,2,3,5}是一个美丽数组。
////可以证明想要使nums变为美丽数组，至少需要删除1个元素
////输入：nums={1,1,2,2,3,3,}
////输出：2
////解释：可以删除nums[0]和nums[5]，这样得到的nums={1,2,2,3}是一个美丽数组。
////可以证明，要想使nums变为美丽数组，至少需要删除2个元素。
//#define NUM 100000
//
//int Beautiful_nums(int nums[], int sz)
//{
//	int count = 0;
//	for (int i = 0; i < sz; i+=2)
//	{
//		if ( nums[i] == nums[i + 1])
//		{
//			nums[i] = 0;
//			for (int j = i; j < sz-1; j++)
//			{
//				int tmp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = tmp;
//				count++;
//			}
//		}
//	}
//	return count;//满足条件，返回count
//}
//
//int main()
//{
//	int nums[NUM] = { 0 };
//	int sz = 0;
//	for (int i = 0;  ; i++)
//	{
//		scanf("%d", &nums[i]);
//		sz++;
//	}
//	int ret = Beautiful_nums(nums, sz);
//	printf("%d\n", ret);
//	return 0;
//}

////数学——难度简单
////两整数相加
////给你两个整数num1和num2，返回两个整数的和
////输入：num1=12，num2=5
////输出：17
////解释：num1是12，num2是5，它们的和是12+5=17,因此返回17
////输入：num1=-10，num2=4
////输出：-6
////解释：num1+num2=-6,因此返回-6
////-100<=num1,num2<=100
//int sum(int num1, int num2)
//{
//	return num1 + num2;
//}
#endif