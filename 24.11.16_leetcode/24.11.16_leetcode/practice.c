#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//2024.11.16力扣网刷题
//最大数值——位运算、脑筋急转弯、数学——简单
//编写一个方法，找出两个数字a和b中最大的那一个。不得使用if - else或其他比较运算符。
//示例：
//输入： a = 1, b = 2
//输出： 2
#include<math.h>
int maximum1(int a, int b) {
	return fmax(a, b);
}

int maximum(int a, int b) {
	//分别提取a与b的符号位
	int sign_a = a >> 31;
	int sign_b = b >> 31;
	//提取差值的符号位:a < b 符号位为1，a > b 符号位为0
	int sign = !(sign_a ^ sign_b) && ((a - b) >> 31) & 1;
	//当a > b 时，sign = 0, a - (a - b) * sign == a - (a - b) * 0 = a
	//当 a < b 时，sign = 1，a - b = -(b - a),a - (a - b) == a + (b - a) = b
	return a * (1 - sign) + b * sign;
}



//void test1(int a, int* pa, int** ppa) {
//	printf("&a = %p\n",&a);
//	printf("pa = %p\n", pa);
//	printf("&pa = %p\n", &pa);
//	printf("ppa = %p\n", ppa);
//	printf("&ppa = %p\n\n", &ppa);
//}
//
//int main() {
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//	printf("main函数中的输出：\n");
//	printf("&a = %p\n", &a);
//	printf("pa = %p\n", pa);
//	printf("&pa = %p\n", &pa);
//	printf("ppa = %p\n", ppa);
//	printf("&ppa = %p\n\n", &ppa);
//	printf("传值与传址传参的输出：\n");
//	test1(a, pa, ppa);
//	return 0;
//}

//typedef struct LinkNode {
//	int val;
//	struct LinkNode* next;
//}LinkNode, * LinkList;
//void Print(LinkList l) {
//	LinkNode* p = l;
//	while (p) {
//		printf("p->val = %d\n", p->val);
//		p = p->next;
//	}
//}
////创建无头结点的链表
//void Creat(LinkList* l) {
//	assert(l);
//	//插入的新结点
//	LinkNode* q = *l;
//	int x = 0;
//	while (scanf("%d", &x) == 1) {
//		if (q == NULL) {
//			q = (LinkNode*)calloc(1, sizeof(LinkNode));
//			assert(q);
//			q->val = x;
//			q->next = NULL;
//			*l = q;
//		}
//		else {
//			LinkNode* p = (LinkNode*)calloc(1, sizeof(LinkNode));
//			assert(p);
//			p->val = x;
//			p->next = q->next;
//			q->next = p;
//			q = p;
//		}
//	}
//	getchar();
//	printf("创建完成\n");
//}
////这里是二级指针
//void Delete1(LinkList* l) {
//	LinkNode* p = *l;
//	int n = 0;
//	printf("请输入需要头删的结点数：");
//	scanf("%d", &n);
//	while (n) {
//		*l = p->next;
//		p->next = NULL;
//		free(p);
//		p = *l;
//		n -= 1;
//	}
//	printf("删除完成\n");
//}
////这里是一级指针
//void Delete2(LinkList l) {
//	LinkNode* p = l;
//	int n = 0;
//	printf("请输入需要头删的结点数：");
//	scanf("%d", &n);
//	while (n) {
//		l = p->next;
//		p->next = NULL;
//		free(p);
//		p = l;
//		n -= 1;
//	}
//	printf("删除完成\n");
//	Print(l);
//}
////这里是一级指针
//void Delete3(LinkList l) {
//	int n = 0;
//	printf("请输入需要尾删的结点数：");
//	scanf("%d", &n);
//	while (n) {
//		LinkNode* p = l;
//		LinkNode* q = l->next;
//		while (q && q->next) {
//			p = q;
//			q = q->next;
//		}
//		p->next = q->next;
//		free(q);
//		n -= 1;
//	}
//	printf("删除完成\n");
//	Print(l);
//}
//void Destroy(LinkList* l) {
//	LinkNode* p = *l;
//	while (p) {
//		*l= p->next;
//		p->next = NULL;
//		free(p);
//		p = *l;
//	}
//	printf("链表已销毁\n");
//}
//int main() {
//	LinkList l1 = NULL;
//	LinkList l2 = NULL;
//	Creat(&l1);
//	Print(l1);
//	Delete1(&l1);
//	Print(l1);
//	Creat(&l2);
//	Print(l2);
//	Delete3(l2);
//	Print(l2);
//	Destroy(&l1);
//	Destroy(&l2);
//	return 0;
//}