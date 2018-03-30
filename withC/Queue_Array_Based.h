//
//  Queue_Linear.h
//  Data Structures
//
//  Created by 刘根杰 on 07/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#define M 1000 // 队列的最大长度

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 队列 顺序存储 结构定义
char queue[M]; // 数据是单个字符形式
int front = -1; // 对头位置的前一个位置，-1
int * pFront = &front;
int rear = -1; // 对尾位置 -1
int * pRear = &rear;

// 初始化
int queue_linear_initial (int * pFront, int * pRear) {
    *pFront = -1;
    *pRear = -1;
    return 1;
}

// 是否为空
int queue_linear_empty (int front, int rear) {
    return front == rear;
}

// 插入 data 要插入的数据
int * queue_linear_push (int * queue, int * pRear, char data) {
    if (*pRear == M-1) { // rear 到尾部最底处，是假溢出，但也插不进去
        return NULL;
    } else {
        *pRear += 1;
        int a = *pRear;
        queue[a] = data;
        return queue;
    }
}

// 删除 data 要删除的数据
int * queye_linear_pop (int * queue, int * pRear, int * pFront) {
    if (queue_linear_empty(*pRear, *pFront)) { // 要先判断是否空，既临界点的情况
        return 0;
    } else {
        // queue[*pFront] 被删数据，视情况需要，保存到其他地方
        *pFront += 1; // 一般删除都会在前部留出无用空间
    }
    return queue;
}

/**
循环队列
 把队列（数组）设想成头尾相连的循环表，使得数组前部由于删除操作而导致的无用空间尽可能得到重复利用。
 */


#endif /* Queue_h */
