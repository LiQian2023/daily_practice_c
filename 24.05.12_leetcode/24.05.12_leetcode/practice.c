#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.05.12力扣网刷题
//破冰游戏——数学、递归——简单
//社团共有 num 位成员参与破冰游戏，编号为 0 ~ num-1。成员们按照编号顺序围绕圆桌而坐。
//社长抽取一个数字 target，从 0 号成员起开始计数，
//排在第 target 位的成员离开圆桌，且成员离开后从下一个成员开始计数。
//请返回游戏结束时最后一位成员的编号。
//示例 1：
//输入：num = 7, target = 4
//输出：1
//示例 2：
//输入：num = 12, target = 5
//输出：0
//提示：
//1 <= num <= 10 ^ 5
//1 <= target <= 10 ^ 6

//法一：模拟——超时
int iceBreakingGame1(int num, int target) {
	bool* arr = (bool*)calloc(num, sizeof(bool));
	assert(arr);
	int len = num;//剩余成员数
	int count = 0;//计数
	int i = 0;//成员下标
	while (len > 1) {
		//成员未被删除，且计数达到target-1
		if (arr[i] == false && count == target - 1) {
			arr[i] = true;//删除成员
			count = 0;//计数归零
			len--;//剩余成员数减1
		}
		//成员未被删除，且计数未达到target-1
		else if (arr[i] == false && count != target - 1) {
			count++;//计数
		}
		i = (i + 1) % num;
	}
	for (i = 0; i < num; i++)
		if (arr[i] == false)
			break;
	return i;
}
//方法二：循环链表——超时
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LN, * LL;
void Init(LL* L) {
	*L = (LN*)calloc(1, sizeof(LN));//创建头结点
	assert(*L);
	(*L)->data = -1;
	(*L)->next = NULL;
}
void TailInsert(LL* L, int num) {
	assert(L);
	LN* l = *L, * s = NULL;//队尾指针与新结点指针
	int i = 0;
	while (num) {
		s = (LN*)calloc(1, sizeof(LN));
		assert(s);
		s->data = i;//存储结点对应下标
		s->next = l->next;//结点尾插入链表
		l->next = s;
		l = s;//队尾指针指向表尾结点
		i++;
		num--;
	}
	l->next = (*L)->next;//循环链表
}
void Delete(LL* L, LN* p) {
	LN* q = p->next;
	p->data = q->data;//复制后继结点的数据
	p->next = q->next;//删除结点
	q->next = NULL;
	free(q);//释放结点
}
int iceBreakingGame2(int num, int target) {
	LL L;//创建链表
	Init(&L);//初始化链表
	TailInsert(&L, num);
	int len = num;
	int count = 0;
	LN* p = L->next;//表头结点
	while (len > 1) {
		if (count == target - 1) {
			Delete(&L, p);
			len--;
			count = 0;
		}
		else {
			count++;//计数
			p = p->next;//移动指针
		}
	}
	return p->data;
}

int iceBreakingGame(int num, int target) {
	if (num == 1)
		return 0;
	int x = iceBreakingGame(num - 1, target);
	return (target % num + x) % num;
}

void test() {
	int num = 0, target = 0;
	while (scanf("%d%d", &num, &target) == 2) {
		printf("%d\n", iceBreakingGame(num, target));
	}
}
void test2() {
	printf("%d\n", 106922 % 70866);
}
int main() {
	test2();
	return 0;
}