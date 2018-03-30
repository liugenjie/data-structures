//
//  Stack_Linked.h
//  Data Structures
//
//  Created by 刘根杰 on 07/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#ifndef Stack_Linked_h
#define Stack_Linked_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链式 堆栈 结构定义
typedef struct snode {
    char data [100];  // 结点的数据，数据是个字符串形式
    struct snode * link; // 下一个结点的指针
}STNode, *STLink;

STLink top_stlink = NULL; // 栈顶节点

// 初始化 data 需要初始化的 top 数值
STLink stack_linked_initial (STLink top) {
    top = NULL;
    return top;
}

// 是否为空
int stack_linked_empty (STLink top) {
    return top == NULL;
}

// 入栈 data 要入栈的数据
STLink stack_linked_push (STLink top, char data[]) {
    STLink p = (STLink)malloc(sizeof(STNode));
    strcpy(p->data, data);
    p->link = top;
    top = p;
    return top;
}

// 出栈 data 要出栈的数据
STLink stack_linked_pop (STLink top) {
    if (!stack_linked_empty(top)) {
        // char temp[] = top->data 视情况需要保存数据
        STLink p = top;
        top = top->link;
        free (p);
    }
    return top;
}

#endif /* Stack_Linked_h */
