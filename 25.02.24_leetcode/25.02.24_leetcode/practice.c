#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

//2025.02.24力扣网刷题
//设计有序流——设计、数组、哈希表、数据流——简单
//有 n 个(id, value) 对，其中 id 是 1 到 n 之间的一个整数，value 是一个字符串。不存在 id 相同的两个(id, value) 对。
//设计一个流，以 任意 顺序获取 n 个(id, value) 对，并在多次调用时 按 id 递增的顺序 返回一些值。
//实现 OrderedStream 类：
//OrderedStream(int n) 构造一个能接收 n 个值的流，并将当前指针 ptr 设为 1 。
//String[] insert(int id, String value) 向流中存储新的(id, value) 对。存储后：
//如果流存储有 id = ptr 的(id, value) 对，则找出从 id = ptr 开始的 最长 id 连续递增序列 ，并 按顺序 返回与这些 id 关联的值的列表。然后，将 ptr 更新为最后那个  id + 1 。
//否则，返回一个空列表。
//示例：
//输入
//["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
//[[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
//输出
//[null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]
//解释
//OrderedStream os = new OrderedStream(5);
//os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
//os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
//os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
//os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
//os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
//提示：
//1 <= n <= 1000
//1 <= id <= n
//value.length == 5
//value 仅由小写字母组成
//每次调用 insert 都会使用一个唯一的 id
//恰好调用 n 次 insert

typedef struct LinkNode {
	char value[6];
}LN;

typedef struct {
	LN* list;
	int ptr;
	int maxSize;
} OrderedStream;

typedef OrderedStream OS;

void Print(OS* obj) {
	printf("obj->prt = %d\tobj->masSize = %d\n", obj->ptr, obj->maxSize);
	for (int i = obj->ptr; i < obj->maxSize; i++) {
		printf("(obj->list)[%d].value = %s\t", i, (obj->list)[i].value);
	}
	printf("\n");
}
OrderedStream* orderedStreamCreate(int n) {
	OS* obj = (OS*)calloc(1, sizeof(OS));
	assert(obj);
	obj->ptr = 1;
	obj->maxSize = n + 1;
	obj->list = (LN*)calloc(n + 1, sizeof(LN));
	assert(obj->list);
	Print(obj);
	return obj;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int* retSize) {
	strcpy((obj->list)[idKey].value, value);
	int i = obj->ptr;
	while (i < obj->maxSize && ((obj->list)[i].value)[0]) {
		i += 1;
	}
	*retSize = i - obj->ptr;
	char** ans = (char**)calloc(*retSize, sizeof(char*));
	assert(ans);
	for (i = 0; i < *retSize; i++) {
		ans[i] = (char*)calloc(6, sizeof(char));
		assert(ans[i]);
		strcpy(ans[i], (obj->list)[obj->ptr].value);
		obj->ptr += 1;
	}
	return ans;
}

void orderedStreamFree(OrderedStream* obj) {
	free(obj->list);
	free(obj);
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char** param_1 = orderedStreamInsert(obj, idKey, value, retSize);

 * orderedStreamFree(obj);
*/
