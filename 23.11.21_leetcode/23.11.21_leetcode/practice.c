#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//leetcode每日练习


////元素的删除与移动——动态分配——后期再做
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