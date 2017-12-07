//
//  Linked_Lists.h
//  exercises
//
//  Created by 刘根杰 on 06/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#ifndef Linked_Lists_h
#define Linked_Lists_h

#include <stdio.h>
#include <stdlib.h> // 使用 malloc 时，需要引用，否则报错
#include <string.h> // 使用 strcpy 等函数时，需要引用，否则报错

typedef struct node{
    char data[100];
    struct node * link;
}LNode, *LinkList;

// read data from screen input
// 从文本中一行一行获取，fopen, fscanf, fputs, fclose
// 从屏幕中由用户手动输入，scanf()

// to create a linked list
LinkList create (int n){
    LinkList p = NULL;
    LinkList r = NULL; // r 是“中介”
    LinkList list = NULL;
    //char d[100] = "sdfs";
    for (int i=0; i<n; i++) {
        // read(a);
        p = (LinkList)malloc(sizeof(LNode)); // 先分配内存，然后赋值
        strcpy(p->data, "sdf"); // 赋值数组只能用 strcpy
        p->link = NULL; // 如果需要生成循环链表，这里应改成 p->link = list，意思是：每生成一个新 node 都令其指向第一个 node
        if (list == NULL) {
            list = p;
        } else {
            r->link = p; // 每次新 node 作为上一个的后继，最好画个图就清楚了。
        }
        r = p; //
    }
    return list;
}

// to get length of linked list
int length (LinkList list) {
    LinkList p = list;
    int n = 0;
    while (p != NULL) {
        p = p->link;
        n++;
    }
    return n;
}

// to insert node at first position
LinkList insertFromFirst (LinkList list, char data[]) {
    LinkList p = (LinkList)malloc(sizeof(LNode));
    strcpy(p->data, data);
    p->link = list;
    list = p;
    return list;
}

// to insert node at certain postion
LinkList insertFromCertain (LinkList list, char data[], LinkList q) {
    LinkList p = (LinkList)malloc(sizeof(LNode));
    strcpy(p->data, data);
    if (list == NULL) { // 如果 list 为空
        list = p;
        p->link = NULL;
    } else { // 如果 list 不为空
        p->link = q->link;
        q->link = p;
    }
    return list;
}

// to delete at certain position (q), 已经指定 q 的前驱
LinkList deleteFromCertain (LinkList list, LinkList r, LinkList q) {
    if (list == q) { // q 是 list 的第一个 node 的情况
        list = q->link; // 不是 list->link = q->link;
    } else {
        r->link = q->link;
    }
    free(q); // 需要释放 q 的内存空间
    return list;
}

// to get pointer according with order number
LinkList getNodeFromOrder (LinkList list, int n) {
    int i=1;
    LinkList p = NULL;
    if (n > length(list)) {
        printf("n is beyond length");
    }
    for (i=1; i<=n; i++) {
        if (i==1) {
            p = list;
        } else {
            p = list->link;
        }
    }
    return p;
}

// to get pointer according with node
LinkList getNodeFromNode (LinkList list, LinkList p) {
    LinkList r = NULL;
    if (p == list) { // p is just the first node
        r = list;
    } else {
        r = list; // to loop from the first node
        while (r->link != p && r->link != NULL) { // 不要忘记加 && r->link != NULL
            r = r->link;
        }
    }
    return r;
}

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

#endif /* Linked_Lists_h */
