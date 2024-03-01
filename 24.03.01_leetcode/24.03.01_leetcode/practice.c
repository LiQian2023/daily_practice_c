#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

//2024.03.01力扣网刷题
//设计循环双端队列——设计、队列、数组、链表——中等
//设计实现双端队列。
//实现 MyCircularDeque 类 :
//MyCircularDeque(int k) ：构造函数, 双端队列最大为 k 。
//boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
//boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
//boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
//boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
//int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 - 1 。
//int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 - 1 。
//boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
//boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。
//示例 1：
//输入
//["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
//[[3], [1], [2], [3], [4], [], [], [], [4], []]
//输出
//[null, true, true, true, false, 2, true, true, true, 4]
//解释
//MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
//circularDeque.insertLast(1);			        // 返回 true
//circularDeque.insertLast(2);			        // 返回 true
//circularDeque.insertFront(3);			        // 返回 true
//circularDeque.insertFront(4);			        // 已经满了，返回 false
//circularDeque.getRear();  				// 返回 2
//circularDeque.isFull();				        // 返回 true
//circularDeque.deleteLast();			        // 返回 true
//circularDeque.insertFront(4);			        // 返回 true
//circularDeque.getFront();				// 返回 4
//提示：
//1 <= k <= 1000
//0 <= value <= 1000
//insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull  调用次数不大于 2000 次



#define MAXSIZE 1000
typedef struct {
    int data[MAXSIZE];
    int top, last;
    int len, max;
} MyCircularDeque;

bool myCircularDequeIsEmpty(MyCircularDeque* obj);
bool myCircularDequeIsFull(MyCircularDeque* obj);

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* Q = (MyCircularDeque*)calloc(1, sizeof(MyCircularDeque));
    if (!Q)
    {
        perror("myCircularDequeCreate:Q");
        return NULL;
    }
    Q->len = 0;
    Q->max = k;
    Q->top = 0;
    Q->last = k - 1;
    return Q;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (!obj) {
        perror("myCircularDequeInsertFront:obj");
        return false;
    }
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->top = (obj->top + obj->max - 1) % (obj->max);
    obj->len++;
    obj->data[obj->top] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (!obj) {
        perror("myCircularDequeInsertLast:obj");
        return false;
    }
    if (myCircularDequeIsFull(obj)) {
        return false;
    }
    obj->last = ++(obj->last) % (obj->max);
    obj->data[obj->last] = value;
    obj->len++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (!obj) {
        perror("myCircularDequeDeleteFront:obj");
        return false;
    }
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    obj->top = ++(obj->top) % (obj->max);
    obj->len--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (!obj) {
        perror("myCircularDequeDeleteLast:obj");
        return false;
    }
    if (myCircularDequeIsEmpty(obj)) {
        return false;
    }
    obj->last = (obj->last + obj->max - 1) % (obj->max);
    obj->len--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (!obj) {
        perror("myCircularDequeDequeGetFront:obj");
        return -1;
    }
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->data[obj->top];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (!obj) {
        perror("myCircularDequeDequeGetRear:obj");
        return -1;
    }
    if (myCircularDequeIsEmpty(obj))
        return -1;
    return obj->data[obj->last];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (!obj) {
        perror("myCircularDequeIsEmpt:obj");
        return false;
    }
    if (obj->len == 0)
        return true;
    return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (!obj) {
        perror("myCircularDequeIsEmpt:obj");
        return false;
    }
    if (obj->len == obj->max)
        return true;
    return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    if (!obj) {
        perror("myCircularDequeFree:obj");
        return;
    }
    while (!myCircularDequeIsEmpty(obj)) {
        myCircularDequeDeleteFront(obj);
    }
}  