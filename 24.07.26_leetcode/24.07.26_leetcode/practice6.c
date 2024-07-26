#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
//2024.07.26力扣网刷题
//距离顺序排列矩阵单元格——几何、数学、数组、矩阵、排序——简单
//给定四个整数 rows, cols, rCenter 和 cCenter 。有一个 rows x cols 的矩阵，你在单元格上的坐标是(rCenter, cCenter) 。
//返回矩阵中的所有单元格的坐标，并按与(rCenter, cCenter) 的 距离 从最小到最大的顺序排。你可以按 任何 满足此条件的顺序返回答案。
//单元格(r1, c1) 和(r2, c2) 之间的距离为 | r1 - r2 | +| c1 - c2 | 。
//示例 1：
//输入：rows = 1, cols = 2, rCenter = 0, cCenter = 0
//输出： [[0, 0], [0, 1]]
//解释：从(r0, c0) 到其他单元格的距离为：[0, 1]
//示例 2：
//输入：rows = 2, cols = 2, rCenter = 0, cCenter = 1
//输出： [[0, 1], [0, 0], [1, 1], [1, 0]]
//解释：从(r0, c0) 到其他单元格的距离为：[0, 1, 1, 2]
//[[0, 1], [1, 1], [0, 0], [1, 0]] 也会被视作正确答案。
//示例 3：
//输入：rows = 2, cols = 3, rCenter = 1, cCenter = 2
//输出： [[1, 2], [0, 2], [1, 1], [0, 1], [1, 0], [0, 0]]
//解释：从(r0, c0) 到其他单元格的距离为：[0, 1, 1, 2, 2, 3]
//其他满足题目要求的答案也会被视为正确，例如 [[1, 2], [1, 1], [0, 2], [1, 0], [0, 1], [0, 0]] 。
//提示：
//1 <= rows, cols <= 100
//0 <= rCenter < rows
//0 <= cCenter < cols

typedef struct LinkNode {
	int dx;//与目标点的距离
	short x;//该点横坐标
	short y;//该点纵坐标
	struct LinkNode* next;//桶号相同的下一个结点
}LN;
typedef struct Bucket {
	int count;//桶结点数
	LN* List;//指向桶链表的指针
}Bucket;

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
	int** ans = (int**)calloc(rows * cols, sizeof(int*));
	assert(ans);
	Bucket buck[21] = { 0 };
	int x1 = rCenter, y1 = cCenter;
	int x2 = 0, y2 = 0;
	//获取所有坐标
	for (int i = 0; i < rows * cols; i++) {
		ans[i] = (int*)calloc(2, sizeof(int));
		assert(ans[i]);
		ans[i][0] = x2;
		ans[i][1] = y2;
		y2++;
		if (y2 == cols) {
			y2 = 0;
			x2 += 1;
		}
	}
	//桶排序
	int dx = 0;
	for (int i = 0; i < rows * cols; i++) {
		dx = abs(x1 - ans[i][0]) + abs(y1 - ans[i][1]);
		int key = dx / 10;
		//存储结点数据
		LN* p = (LN*)calloc(1, sizeof(LN));
		assert(p);
		p->dx = dx;
		p->x = ans[i][0];
		p->y = ans[i][1];
		p->next = NULL;
		//将结点插入到桶中
		buck[key].count += 1;
		if (buck[key].count == 1) {
			//申请头结点空间
			buck[key].List = (LN*)calloc(1, sizeof(LN));
			assert(buck[key].List);
			//将结点插入到头结点后
			buck[key].List->next = p;
		}
		else {
			LN* q = buck[key].List;//指向头结点的指针
			LN* l = buck[key].List->next;//指向表头结点的指针
			//遍历链表找到合适的位置
			while (l && l->dx <= p->dx) {
				q = l;
				l = l->next;
			}
			//尾插
			p->next = q->next;
			q->next = p;
		}
	}
	for (int i = 0, key = 0; key < 21 && i < rows * cols;) {
		if (buck[key].count) {
			LN* p = buck[key].List->next;//指向结点的指针
			//删除结点
			buck[key].List->next = p->next;
			p->next = NULL;
			//存入数据
			ans[i][0] = p->x;
			ans[i][1] = p->y;
			buck[key].count -= 1;
			//释放结点内存空间
			free(p);
			//如果结点全部删除
			if (buck[key].count == 0)
				free(buck[key].List);//释放头结点空间
			//移动下标，存储下一个结点数据
			i++;
		}
		else {

			//移动桶
			key++;
		}
	}
	*returnSize = rows * cols;
	*returnColumnSizes = (int*)calloc(rows * cols, sizeof(int));
	for (int i = 0; i < rows * cols; i++)
		(*returnColumnSizes)[i] = 2;
	return ans;
}

void test6() {
	int rows = 4, cols = 9, rCenter = 3, cCenter = 8;
	int returnSize = 0;
	int* returnColumnSizes = 0;
	int** ret = allCellsDistOrder(rows, cols, rCenter, cCenter, &returnSize, &returnColumnSizes);
}
