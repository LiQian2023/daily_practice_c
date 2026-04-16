#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2026.04.16力扣网刷题
//3488. 距离最小相等元素查询——高级工程师、数组、哈希表、二分查找——第441场周赛——中等
//给你一个 环形 数组 nums 和一个数组 queries 。
//对于每个查询 i ，你需要找到以下内容：
//数组 nums 中下标 queries[i] 处的元素与 任意 其他下标 j（满足 nums[j] == nums[queries[i]]）之间的 最小 距离。如果不存在这样的下标 j，则该查询的结果为 - 1 。
//返回一个数组 answer，其大小与 queries 相同，其中 answer[i] 表示查询i的结果。
//示例 1：
//输入： nums = [1, 3, 1, 4, 1, 3, 2], queries = [0, 3, 5]
//输出：[2, -1, 3]
//解释：
//查询 0：下标 queries[0] = 0 处的元素为 nums[0] = 1 。最近的相同值下标为 2，距离为 2。
//查询 1：下标 queries[1] = 3 处的元素为 nums[3] = 4 。不存在其他包含值 4 的下标，因此结果为 - 1。
//查询 2：下标 queries[2] = 5 处的元素为 nums[5] = 3 。最近的相同值下标为 1，距离为 3（沿着循环路径：5 -> 6 -> 0 -> 1）。
//示例 2：
//输入： nums = [1, 2, 3, 4], queries = [0, 1, 2, 3]
//输出：[-1, -1, -1, -1]
//解释：
//数组 nums 中的每个值都是唯一的，因此没有下标与查询的元素值相同。所有查询的结果均为 - 1。
//提示：
//1 <= queries.length <= nums.length <= 10^5
//1 <= nums[i] <= 10^6
//0 <= queries[i] < nums.length

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 方法一：哈希表——空间复杂度超出限制
typedef struct HashNode {
    int key;
    int* value;
    int len;
} HashNode;
typedef struct HashMap {
    int size;
    int count;
    int min;
    HashNode* nodes;
} HashMap;;

HashMap* CreateHashMap(int size) {
    HashMap* hash = (HashMap*)calloc(1, sizeof(HashMap));
    assert(hash);
    hash->size = size;
    hash->nodes = (HashNode*)calloc(size, sizeof(HashNode));
    assert(hash->nodes);
    return hash;
}
void HashRecord(HashMap* hash, int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int key = nums[i] - hash->min;
        if (hash->nodes[key].len) {
            hash->nodes[key].value = (int*)realloc(hash->nodes[key].value, (hash->nodes[key].len + 1) * sizeof(int));
            assert(hash->nodes[key].value);
            hash->nodes[key].value[hash->nodes[key].len] = i;
            hash->nodes[key].len++;
        } else {
            hash->nodes[key].key = key;
            hash->nodes[key].value = (int*)calloc(1, sizeof(int));
            assert(hash->nodes[key].value);
            hash->nodes[key].value[0] = i;
            hash->nodes[key].len = 1;
		}
    }
}
void FreeHash(HashMap** hash) {
    if (*hash) {
		for (int i = 0; i < (*hash)->size; i++) {
            if ((*hash)->nodes[i].len) {
                free((*hash)->nodes[i].value);
				(*hash)->nodes[i].value = NULL;
            }
        }
        free((*hash)->nodes);
		(*hash)->nodes = NULL;
        free(*hash);
        *hash = NULL;
    }
}
int* solveQueries1(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    // 获取哈希表大小
    int max = nums[0], min = nums[0];
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max)
            max = nums[i];
        else if (nums[i] < min)
            min = nums[i];
    }
    int size = max - min + 1;
    // 哈希记录
    HashMap* hash = CreateHashMap(size);
    hash->min = min;
    HashRecord(hash, nums, numsSize);
    // 结果数组
    *returnSize = queriesSize;
    int* ans = (int*)calloc(queriesSize, sizeof(int));
    assert(ans);
	for (int i = 0; i < queriesSize; i++) {
        int key = nums[queries[i]] - hash->min;
        printf("hash->nodes[%d].len = %d\n[", key, hash->nodes[key].len);
        for (int i = 0; i < hash->nodes[key].len; i++) {
            if (i != hash->nodes[key].len - 1)
                printf("%d, ", hash->nodes[key].value[i]);
            else {
                printf("%d", hash->nodes[key].value[i]);
            }
        }
        printf("]\n\n");
        if (hash->nodes[key].len < 2) {
            ans[i] = -1;
        } else {
			for (int left = 0, right = hash->nodes[key].len - 1; left <= right; left++, right--) {
				int leftIndex = hash->nodes[key].value[left];
				int rightIndex = hash->nodes[key].value[right];
				if (leftIndex != queries[i]) {
					int leftDist = abs(leftIndex - queries[i]);
                    if (ans[i] == 0) {
                        ans[i] = leftDist;
                        ans[i] = ans[i] < numsSize - leftDist ? ans[i] : numsSize - leftDist;
                    }

                    else {
                        ans[i] = leftDist < ans[i] ? leftDist : ans[i];
						ans[i] = ans[i] < numsSize - leftDist ? ans[i] : numsSize - leftDist;
                    }
                }
				if (rightIndex != queries[i]) {
                    int rightDist = abs(rightIndex - queries[i]);
                    if (ans[i] == 0) {
                        ans[i] = rightDist;
                        ans[i] = ans[i] < numsSize - rightDist ? ans[i] : numsSize - rightDist;
                    }

                    else {
                        ans[i] = rightDist < ans[i] ? rightDist : ans[i];
                        ans[i] = ans[i] < numsSize - rightDist ? ans[i] : numsSize - rightDist;
                    }
                }
            }
        }
    }
    FreeHash(&hash);
    return ans;
}

// 方法二：双指针——时间复杂度超
int getMinDist(int a, int b, int minDist) {
    a = a < b ? a : b;
    if (a != 0 && minDist == -1) {
        minDist = a;
    }
    return a != 0 ? (minDist < a ? minDist : a) : minDist;
}
int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    int* ans = (int*)calloc(queriesSize, sizeof(int));
    assert(ans);
    for (int i = 0; i < queriesSize; i++) {
        int minDist = -1;
        int target = queries[i];
        int left = (target + numsSize - 1) % numsSize;
        for (int j = 0; j < (numsSize - 1) / 2 && nums[left] != nums[target]; j++) {
            left = (left + numsSize - 1) % numsSize;
        }
        if (nums[left] == nums[target]) {
            minDist = getMinDist(abs(left - target), numsSize - abs(left - target), minDist);
        }
        int right = (target + 1) % numsSize;
        for (int j = 0; j < (numsSize - 1) / 2 && nums[right] != nums[target]; j++) {
            right = (right + 1) % numsSize;
        }
        if (nums[right] == nums[target]) {
            minDist = getMinDist(abs(right - target), numsSize - abs(right - target), minDist);
        }
        ans[i] = minDist;
    }
    *returnSize = queriesSize;
    return ans;
}


typedef struct Hash{
    bool flag;
    int len;
    int pi;
    int num;
    int* index;
}Hash;
int getKey(int len, int num, Hash* hash) {
    int key = num % len;
    while (hash[key].num != num && hash[key].len != 0) {
        key = (key + 1) % len;
    }
    return key;
}
void Free(Hash** h, int len) {
    if (*h == NULL) {
        return;
    }
    for (int i = 0; i < (*h)->len; i++) {
        if ((*h)->flag) {
            free((*h)->index);
            (*h)->index = NULL;
        }
    }
    free(*h);
    *h = NULL;
}
int Min(int a, int b) {
    return a < b ? a : b;
}
int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    Hash* hash = (Hash*)calloc(numsSize, sizeof(Hash));
    assert(hash);
    for (int i = 0; i < numsSize; i++) {
        int key = getKey(numsSize, nums[i], hash);
        hash[key].flag = false;
        hash[key].len += 1;
        hash[key].num = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        int key = getKey(numsSize, nums[i], hash);
        if (hash[key].flag == false) {
            hash[key].index = (int*)calloc(hash[key].len, sizeof(int));
            assert(hash[key].index);
            hash[key].flag = true;
        }
        hash[key].index[hash[key].pi] = i;
        hash[key].pi += 1;
    }
    int* dist = (int*)calloc(numsSize, sizeof(int));
    assert(dist);
    for (int i = 0; i < numsSize; i++) {
        if (hash[i].flag) {
            for (int j = 0; j < hash[i].len; j++) {
                int index = hash[i].index[j];
                int pre = hash[i].index[(j + hash[i].len - 1) % hash[i].len];
                int cur = hash[i].index[(j + 1) % hash[i].len];
                dist[index] = Min((index - pre + numsSize) % numsSize, (cur - index + numsSize) % numsSize);
            }
        }
    }
    Free(&hash, numsSize);
    int* ans = (int*)calloc(queriesSize, sizeof(int));
    assert(ans);
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = dist[queries[i]];
        if (ans[i] == 0) {
            ans[i] = -1;
        }
    }
    free(dist);
    return ans;
}