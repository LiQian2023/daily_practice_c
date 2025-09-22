#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2025.09.22力扣网刷题
//区域和检索 - 数组不可变——设计、数组、前缀和——简单
//给定一个整数数组  nums，处理以下类型的多个查询 :
//计算索引 left 和 right （包含 left 和 right）之间的 nums 元素的 和 ，其中 left <= right
//实现 NumArray 类：
//NumArray(int[] nums) 使用数组 nums 初始化对象
//int sumRange(int i, int j) 返回数组 nums 中索引 left 和 right 之间的元素的 总和 ，包含 left 和 right 两点（也就是 nums[left] + nums[left + 1] + ... + nums[right] )
//示例 1：
//输入：
//["NumArray", "sumRange", "sumRange", "sumRange"]
//[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// [5, 0, 3, -5, 2, -1]],[5,5],[0,2],[2,5],[0,5]
//输出：
//[null, 1, -1, -3]
//解释：
//NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);[0,-2,-2,1,-4,-2,-3],1,-1,-3
// [0,5,5,8,3,5,4],-1,8,-1,4
//numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
//numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
//numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
//提示：
//1 <= nums.length <= 10^4
//- 10^5 <= nums[i] <= 10^5
//0 <= i <= j < nums.length
//最多调用 10^4 次 sumRange 方法

#if 0
// 方法一：暴力求解
typedef struct {
    int* nums;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* numarray = (NumArray*)calloc(1, sizeof(NumArray));
    assert(numarray);
    numarray->nums = (int*)calloc(numsSize, sizeof(int));
    assert(numarray->nums);
    for (int i = 0; i < numsSize; i++) {
        numarray->nums[i] = nums[i];
    }
    return numarray;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) {
        sum += obj->nums[i];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    obj->nums = NULL;
    free(obj);
    obj = NULL;
}
#endif

// 方法二：前缀和
typedef struct {
    int* presum;
    int len;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* numarray = (NumArray*)calloc(1, sizeof(NumArray));
    assert(numarray);
    numarray->len = numsSize + 1;
    numarray->presum = (int*)calloc(numarray->len, sizeof(int));
    assert(numarray->presum);
    for (int i = 0; i < numsSize; i++) {
        (numarray->presum)[i + 1] = (numarray->presum)[i] + nums[i];
    }
    return numarray;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->presum[right + 1] - obj->presum[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->presum);
    obj->presum = NULL;
    free(obj);
    obj = NULL;
}