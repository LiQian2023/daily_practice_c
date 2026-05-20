#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//2026.05.20力扣网刷题
//面试题 03.06.动物收容所——设计、队列——简单
//动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。请创建适用于这个系统的数据结构，实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。允许使用Java内置的LinkedList数据结构。
//enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。
//dequeue * 方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1, -1]。
//示例 1：
//输入：
//["AnimalShelf", "enqueue", "enqueue", "dequeueCat", "dequeueDog", "dequeueAny"]
//[[], [[0, 0]], [[1, 0]], [], [], []]
//输出：
//[null, null, null, [0, 0], [-1, -1], [1, 0]]
//示例 2：
//输入：
//["AnimalShelf", "enqueue", "enqueue", "enqueue", "dequeueDog", "dequeueCat", "dequeueAny"]
//[[], [[0, 0]], [[1, 0]], [[2, 1]], [], [], []]
//输出：
//[null, null, null, null, [2, 1], [0, 0], [1, 0]]
//说明:
//收纳所的最大容量为20000




typedef struct {
	int** dogQueue;
	int** catQueue;
	int dogFront;
	int catFront;
	int dogRear;
	int catRear;
	int dog;
	int cat;
	int baseSize;
} AnimalShelf;

int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize);
int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize);

AnimalShelf* animalShelfCreate() {
	AnimalShelf* obj = (AnimalShelf*)calloc(1, sizeof(AnimalShelf));
	assert(obj);
	obj->baseSize = 10;
	obj->catQueue = (int**)calloc(obj->baseSize, sizeof(int*));
	assert(obj->catQueue);
	obj->cat = 0;
	obj->catRear = 0;
	obj->catFront = 0;
	obj->dogQueue = (int**)calloc(obj->baseSize, sizeof(int*));
	assert(obj->dogQueue);
	obj->dog = 0;
	obj->dogFront = 0;
	obj->dogRear = 0;
	return obj;

}

int** Realloc(int** nums, int n, int f, int oldSize, int newSize) {
	int** tmp = (int**)calloc(newSize, sizeof(int*));
	if (!tmp) {
		return NULL;
	}
	for (int i = 0, j = f; i < n; i++) {
		tmp[i] = nums[j];
		j = (j + 1) % oldSize;
	}
	return tmp;
}
void animalShelfEnqueue(AnimalShelf* obj, int* animal, int animalSize) {
	if (obj->cat + 1 == obj->baseSize || obj->dog + 1 == obj->baseSize) {
		int newSize = obj->baseSize * 3 / 2;
		int** tmp = Realloc(obj->catQueue, obj->cat, obj->catFront, obj->baseSize, newSize);
		if (!tmp) {
			perror("realloc(cat)");
			return;
		}
		obj->catFront = 0;
		obj->catRear = obj->cat;
		free(obj->catQueue);
		obj->catQueue = tmp;
		tmp = Realloc(obj->dogQueue, obj->dog, obj->dogFront, obj->baseSize, newSize);
		obj->dogFront = 0;
		obj->dogRear = obj->dog;
		free(obj->dogQueue);
		obj->dogQueue = tmp;
		obj->baseSize = newSize;
	}
	int* node = (int*)calloc(2, sizeof(int));
	assert(node);
	node[0] = animal[0];
	node[1] = animal[1];
	switch (animal[1]) {
		case 0:
			obj->catQueue[obj->catRear] = node;
			obj->cat += 1;
			obj->catRear = (obj->catRear + 1) % obj->baseSize;
			break;
		case 1:
			obj->dogQueue[obj->dogRear] = node;
			obj->dog += 1;
			obj->dogRear = (obj->dogRear + 1) % obj->baseSize;
			break;
		default:
			break;
	}
}

int* animalShelfDequeueAny(AnimalShelf* obj, int* retSize) {
	int* ans = NULL;
	if (obj->dog && obj->cat) {
		if (obj->dogQueue[obj->dogFront][0] < obj->catQueue[obj->catFront][0]) {
			ans = animalShelfDequeueDog(obj, retSize);
		}
		else {
			ans = animalShelfDequeueCat(obj, retSize);
		}
	}
	else if (obj->dog && obj->cat == 0) {
		ans = animalShelfDequeueDog(obj, retSize);
	}
	else if (obj->cat && obj->dog == 0) {
		ans = animalShelfDequeueCat(obj, retSize);
	}
	else {
		ans = (int*)calloc(2, sizeof(int));
		assert(ans);
		ans[0] = -1;
		ans[1] = -1;
		*retSize = 2;
	}
	return ans;
}

int* animalShelfDequeueDog(AnimalShelf* obj, int* retSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*retSize = 2;
	ans[0] = -1;
	ans[1] = -1;
	if (obj->dog) {
		ans[0] = obj->dogQueue[obj->dogFront][0];
		ans[1] = obj->dogQueue[obj->dogFront][1];
		free(obj->dogQueue[obj->dogFront]);
		obj->dogQueue[obj->dogFront] = NULL;
		obj->dogFront = (obj->dogFront + 1) % obj->baseSize;
		obj->dog -= 1;
		return ans;
	}
	return ans;
}

int* animalShelfDequeueCat(AnimalShelf* obj, int* retSize) {
	int* ans = (int*)calloc(2, sizeof(int));
	assert(ans);
	*retSize = 2;
	ans[0] = -1;
	ans[1] = -1;
	if (obj->cat) {
		ans[0] = obj->catQueue[obj->catFront][0];
		ans[1] = obj->catQueue[obj->catFront][1];
		free(obj->catQueue[obj->catFront]);
		obj->catQueue[obj->catFront] = NULL;
		obj->catFront = (obj->catFront + 1) % obj->baseSize;
		obj->cat -= 1;
		return ans;
	}
	return ans;
}

void animalShelfFree(AnimalShelf* obj) {
	free(obj->catQueue);
	obj->catQueue = NULL;
	free(obj->dogQueue);
	obj->dogQueue = NULL;
	free(obj);
	obj = NULL;
}

/**
 * Your AnimalShelf struct will be instantiated and called as such:
 * AnimalShelf* obj = animalShelfCreate();
 * animalShelfEnqueue(obj, animal, animalSize);

 * int* param_2 = animalShelfDequeueAny(obj, retSize);

 * int* param_3 = animalShelfDequeueDog(obj, retSize);

 * int* param_4 = animalShelfDequeueCat(obj, retSize);

 * animalShelfFree(obj);
*/