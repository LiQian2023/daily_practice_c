#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//2025.03.19力扣网刷题
//转换二维数组——数组、哈希表——中等
//给你一个整数数组 nums 。请你创建一个满足以下条件的二维数组：
//二维数组应该 只 包含数组 nums 中的元素。
//二维数组中的每一行都包含 不同 的整数。
//二维数组的行数应尽可能 少 。
//返回结果数组。如果存在多种答案，则返回其中任何一种。
//请注意，二维数组的每一行上可以存在不同数量的元素。
//示例 1：
//输入：nums = [1, 3, 4, 1, 2, 3, 1]
//输出： [[1, 3, 4, 2], [1, 3], [1]]
//解释：根据题目要求可以创建包含以下几行元素的二维数组：
//- 1, 3, 4, 2
//- 1, 3
//- 1
//nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
//可以证明无法创建少于三行且符合题目要求的二维数组。
//示例 2：
//输入：nums = [1, 2, 3, 4]
//输出： [[4, 3, 2, 1]]
//解释：nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
//提示：
//1 <= nums.length <= 200
//1 <= nums[i] <= nums.length

typedef struct HashNode {
    int val;   // 数值
    int count; // 次数
} HN;
typedef struct Hash {
    HN* list;
    int n;
    int max;
} Hash;
Hash* CreateHash(int* nums, int numsSize) {
    Hash* h = (Hash*)calloc(1, sizeof(Hash));
    assert(h);
    h->list = (HN*)calloc(201, sizeof(HN));
    assert(h->list);
    for (int i = 0; i < numsSize; i++) {
        int key = nums[i];
        // 记录数字个数
        if (h->list[key].count == 0) {
            h->list[key].val = nums[i];
            h->n += 1;
        }
        h->list[key].count += 1;
        // 记录数字出现最多次数
        if (h->list[key].count > h->max) {
            h->max = h->list[key].count;
        }
    }
    return h;
}
int** Remove_Duplicates(Hash* h) {
    int** h_set = (int**)calloc(h->n, sizeof(int*));
    assert(h_set);
    for (int i = 0; i < h->n; i++) {
        h_set[i] = (int*)calloc(2, sizeof(int));
        assert(h_set[i]);
    }
    for (int i = 0, j = 0; i < h->n; i++) {
        for (j; j < 201; j++) {
            if (h->list[j].count) {
                h_set[i][0] = h->list[j].val;   // 当前值
                h_set[i][1] = h->list[j].count; // 当前值出现的次数
                j += 1;
                break;
            }
        }
    }
    return h_set;
}
void Destroy_Hash(Hash** h) {
    free((*h)->list);
    (*h)->list = NULL;
    free(*h);
    *h = NULL;
}
void Destroy_H_Set(int*** h_set, int size) {
    for (int i = 0; i < size; i++) {
        free((*h_set)[i]);
        (*h_set)[i] = NULL;
    }
    free(*h_set);
    *h_set = NULL;
}
int** findMatrix(int* nums, int numsSize, int* returnSize,
    int** returnColumnSizes) {
    Hash* h = CreateHash(nums, numsSize);
    // 记录二维数组的行空间个数
    *returnSize = h->max;
    printf("*returnSize = %d\n", *returnSize);
    // 记录不同数字的数量
    int n = h->n;
    // 去重哈希
    int** h_set = Remove_Duplicates(h);
    int size = h->n; // 去重哈希元素个数
    // 完成去重后，释放无用空间
    Destroy_Hash(&h);
    for (int i = 0; i < size; i++) {
        printf("h_set[%d][0] = %d\th_set[%d][1] = %d\n", i, h_set[i][0], i,
            h_set[i][1]);
    }
    // 申请二维数组空间
    int** ans = (int**)calloc(*returnSize, sizeof(int*));
    assert(ans);
    // 申请一维数组空间
    *returnColumnSizes = (int*)calloc(*returnSize, sizeof(int));
    assert(*returnColumnSizes);
    for (int i = 0; i < *returnSize; i++) {
        // 申请一维数组空间
        ans[i] = (int*)calloc(n, sizeof(int));
        assert(ans[i]);
        // 记录一维数组空间大小
        (*returnColumnSizes)[i] = n;
        int flag = 0;
        for (int j = 0, z = 0; j < size; j++) {
            if (h_set[j][1]) {
                ans[i][z] = h_set[j][0];
                z += 1;
                h_set[j][1] -= 1;
                if (h_set[j][1] == 0) {
                    flag += 1;
                }
            }
        }
        if (flag) {
            n -= flag;
        }
    }
    Destroy_H_Set(&h_set, size);
    return ans;
}

void test() {
    int arr[] = { 5,6,7,10,14,16,20,21,23,25,27,30,34,36,41,46,47,53,54,55,60,62,63,64,65,70,73,74,78,82,83,84,90,91,92,94,95,99,101,104,111,115,117,118,119,120,122,128,133,137,138,142,143,144,145,146,148,149,151,152,153,156,159,161,162,165,169,170,171,172,176,178,179,181,182,185,190,191,193,195,196,0 };
    int arr2[] = { 145,118,7,191,165,20,156,36,185,172,74,30,27,200,196,142,78,53,41,34,21,181,178,162,151,137,128,117,111,92,91,84,83,63,62,46,25,10,195,193,190,182,179,176,171,170,169,161,159,153,152,149,148,146,144,143,138,133,122,120,119,115,104,101,99,95,94,90,82,73,70,65,64,60,55,54,47,23,16,14,6,5 };
}