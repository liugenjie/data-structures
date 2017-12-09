//
//  BTree.h
//  Data Structures
//
//  Created by 刘根杰 on 08/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#ifndef BTree_h
#define BTree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二叉树 二叉链式存储 结构定义
typedef struct bnode {
    int data;
    struct bnode *lchild, *rchild;
}BTNode, *BTREE;

void print_btree_iterate_result(BTREE queue[]); // 在函数内部使用的函数需要提前声明

// 前序遍历

// 中序遍历

// 后序遍历

// 按层遍历
/** 手工推演过程
 queue[0] = p;  // 0 结点的序列 queue 的序列
 queue[1] = p->lchild; // 1 queue 的序列
 queue[2] = p->rchild; // 2 queue 的序列
 p = queue[1];  // 1 结点的序列
 queue[3] = p->lchild; // 3 queue 的序列
 queue[4] = p->rchild; // 4 queue 的序列
 p = queue[2];  // 2 结点的序列
 queue[5] = p->lchild; // 5 queue 的序列
 queue[6] = p->rchild; // 6 queue 的序列
 用队列来模拟这个过程，把队列的数据结构思想应用到这里
 从这里可以看到，数据结构的概念还需要活学活用，光靠脑子想非晕不可。这也是数据结构这本学科的作用。
 */
void layerOrder (BTREE T) {
    BTREE queue[100]; // 用于存放遍历后的结点数组
    BTREE p; // 临时折腾数据用
    int front = -1; // 队头，pop，用于考量在数组中处理最靠前的一个结点
    int rear = 0; // 队尾，push，用于考量把结点加入数组
    queue[0] = T; // 按层遍历时，第一个必然是根结点
    while (front != rear) { // 如果遍历完成，front 和 rear 将会相同
        p = queue[++front]; // “从队头 pop”，这也能显示出：为什么在“队列”概念中 front 要指定为“队头位置”的前一个
        if (p->lchild != NULL) queue[++rear] = p->lchild; // “从队尾 push”
        if (p->rchild != NULL) queue[++rear] = p->rchild; // “从队尾 push”
    }
    print_btree_iterate_result(queue); // 把遍历后的结点数组中的数据都打印出来
}

// 把遍历后的结点数组中的数据都打印出来
void print_btree_iterate_result (BTREE queue[]) {
    int n = 10;
    int i;
    char token = 0x0;
    for (i = 0; i < n; i++) {
        printf("%c%d", token, queue[i]->data);
        token = ',';
    }
    printf("\n");
}

#endif /* BTree_h */
