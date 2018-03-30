//
//  List_Doubly_Linked.h
//  Data Structures
//
//  Created by 刘根杰 on 14/03/2018.
//  Copyright © 2018 刘根杰. All rights reserved.
//
//  双链表

#ifndef List_Doubly_Linked_h
#define List_Doubly_Linked_h

#include <stdio.h>
#include <stdlib.h> // 使用 malloc 时，需要引用，否则报错
#include <string.h> // 使用 strcpy 等函数时，需要引用，否则报错

/**
 双向链表的几种形式：
 无头节点的双向链表    list 没有数据
 无头节点的循环双向链表  list 没有数据
 有头节点的循环双向链表  list 有数据
 */

// 双向链表的结构定义
typedef struct dnode {
    char data[100];
    struct dnode * llink, * rlink;
} DNode, * DLinkList;

// 双向链表的插入
// data 是要插入的数据，data1 是要找的位置节点上的数据
DLinkList insertDLinklist (DLinkList list, char data1[], char data[]) {
    // to do 先找到数据是 data1 的节点，获得它的前驱节点和后继节点
    // to do 插入新节点
    return list;
}

// 双向链表的删除
DLinkList deleteDlinklist (DLinkList list, char data[]) {
    // to do 先找到数据是 data 的节点，获得它的前驱节点和后继节点
    // to do 删除该节点
    return list;
}

// 双向链表的删除


#endif /* List_Doubly_Linked_h */
