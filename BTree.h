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

void print_btree_iterate_result(BTREE queue[], char order[]); // 在函数内部使用的函数需要提前声明

// 前序遍历
void preOrder (BTREE T) {
    BTREE queue[20] = {NULL}; // 用于存放遍历后的结点数组
    int queueNo = -1; // queue 的序列
    BTREE p = T; // 临时折腾数据用，从根结点开始处理
    BTREE stack[20]; // 用于处理前序遍历逻辑
    int top = -1; // 堆栈初始位置
    if (T != NULL) { // 边界处理
        do {
            while (p != NULL) {  // 先通过循环把根、左侧的一系列子树的根、和这些子树的根对应的左结点，都压入堆栈中
                queue[++queueNo] = p; // 遍历成功一个，记录到 queue 中
                stack[++top] = p;
                p = p->lchild;
            }
            p = stack[top--]; // 从栈顶弹出一个，然后 top 位置减去一
            p = p->rchild; // p 给成它的右结点，对这个结点再同样的逻辑再来一遍
        } while (p != NULL || top != -1);
    }
    
    print_btree_iterate_result(queue, "preOrder"); // 把遍历后的结点数组中的数据都打印出来
}

// 中序遍历
/** 推演过程
 使用堆栈
 1 若 p 指向的结点非空，则将 p 指向的结点进栈，然后将 p 指向左子树的根
 2 若 p 指向的结点为空，则从堆栈中退出栈顶元素送 p，记录p，然后将 p 指向右子树的根。
 重复上述过程，直到 p 为空，并且堆栈也为空。
 先通过循环把根、左侧的一系列子树的根、和这些子树的根对应的左结点，都压入堆栈中
 从堆栈中弹出栈顶元素，以此同理循环子树中的右侧，并压入堆栈中
 */
void inOrder (BTREE T) {
    BTREE queue[20] = {NULL}; // 用于存放遍历后的结点数组
    int queueNo = -1; // queue 的序列
    BTREE p = T; // 临时折腾数据用，从根结点开始处理
    BTREE stack[20]; // 用于处理中序遍历逻辑
    int top = -1; // 堆栈初始位置
    if (T != NULL) { // 边界处理
        do {
            while (p != NULL) {  // 先通过循环把根、左侧的一系列子树的根、和这些子树的根对应的左结点，都压入堆栈中
                stack[++top] = p;
                p = p->lchild;
            }
            p = stack[top--]; // 从栈顶弹出一个，然后 top 位置减去一
            queue[++queueNo] = p; // 遍历成功一个，记录到 queue 中
            p = p->rchild; // p 给成它的右结点，对这个结点再同样的逻辑再来一遍
        } while (p != NULL || top != -1);
    }
    
    print_btree_iterate_result(queue, "inOrder"); // 把遍历后的结点数组中的数据都打印出来
}

// 后序遍历
void postOrder (BTREE T) {
    BTREE queue[20] = {NULL}; // 用于存放遍历后的结点数组
    int queueNo = -1; // queue 的序列
    BTREE p = T; // 临时折腾数据用，从根结点开始处理
    BTREE stack[20]; // 用于处理后序遍历逻辑
    int stack2[20]; // 记录结点被处理的状态
    int top = -1; // 堆栈初始位置
    int flag; // 0 该结点暂不访问 1 该结点可以访问，显示结点被处理的状态
    if (T != NULL) { // 边界处理
        do {
            while (p != NULL) {  // 先通过循环把根、左侧的一系列子树的根、和这些子树的根对应的左结点，都压入堆栈 stack 中
                stack[++top] = p;
                stack2[top] = 0; //
                p = p->lchild;
            }
            p = stack[top]; // 从栈顶弹出一个
            flag = stack2[top--]; // 标识，然后 top 位置减去一
            if (flag == 0) {
                stack[++top] = p;
                stack2[top] = 1; 
                p = p->rchild; // p 给成它的右结点
            } else {
                queue[++queueNo] = p; // 遍历成功一个，记录到 queue 中
                p = NULL; //
            }
        } while (p != NULL || top != -1);
    }
    
    print_btree_iterate_result(queue, "postOrder"); // 把遍历后的结点数组中的数据都打印出来
}

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
    BTREE queue[20] = {NULL}; // 用于存放遍历后的结点数组
    BTREE p; // 临时折腾数据用
    int front = -1; // 队头，pop，用于考量在数组中处理最靠前的一个结点
    int rear = 0; // 队尾，push，用于考量把结点加入数组
    queue[0] = T; // 按层遍历时，第一个必然是根结点
    while (front != rear) { // 如果遍历完成，front 和 rear 将会相同
        p = queue[++front]; // “从队头 pop”，这也能显示出：为什么在“队列”概念中 front 要指定为“队头位置”的前一个
        if (p->lchild != NULL) queue[++rear] = p->lchild; // “从队尾 push”
        if (p->rchild != NULL) queue[++rear] = p->rchild; // “从队尾 push”
    }
    
    print_btree_iterate_result(queue, "layerOrder"); // 把遍历后的结点数组中的数据都打印出来
}

// 把遍历后的结点数组中的数据都打印出来
void print_btree_iterate_result (BTREE * queue, char order[]) {  // 参数也可以定义成 BTREE queue[]。不会报错。
    int i = 0;
    char token = 0x0;
    printf("%s: ", order);
    while (queue[i] != NULL) {
        printf("%c%d", token, queue[i]->data);
        token = ',';
        i++;
    }
    printf("\n");
}

#endif /* BTree_h */
