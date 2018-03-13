//
//  Queue_Linked.h
//  Data Structures
//
//  Created by 刘根杰 on 07/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#ifndef Queue_Linked_h
#define Queue_Linked_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 队列 链式存储 结构定义
typedef struct qnode {
    char data[100]; // 结点中的数据，数据是个字符串
    struct qnode * link; // 队列中的下一个结点
} QNode, *QLink;

// 初始化
QLink queue_linked_initial (QLink front, QLink rear) {
    front = NULL;
    rear = NULL;
    return front;
}

// 是否为空
int queue_linked_empty (QLink front) {
    return front == NULL;
}

// 插入 data 要插入的数据
QLink queue_linked_add (QLink front, QLink rear, char data[]) {
    QLink p = (QLink)malloc(sizeof(QNode));
    strcpy(p->data, data);
    p->link = NULL;
    if (front == NULL) { // 要先考虑空队列的情况
        front = p;
    } else {
        rear->link = p;
    }
    rear = p;
    return front;
}

// 删除
QLink queue_linked_delete (QLink front) {
    if (front == NULL) { // 先判断空队列的情况
        return NULL;
    } else {
        QLink p = front;
        //p->data 视情况需要保存
        front = front->link;
        free(p);
    }
    return front;
}

// 销毁: 所有结点都删除，并释放每个结点的存储空间，最终队列成为一个空队列
int queue_linked_destroy (QLink front) {
    while (front != NULL) {
        QLink p = front->link;
        free(front);
        front = p;
    }
    return 1;
}
#endif /* Queue_Linked_h */
