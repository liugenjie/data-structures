//
//  Data_Structure.c
//  Data Structures
//
//  Created by 刘根杰 on 06/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#include <stdio.h>
#include "Linear_Lists.h" // 线性顺序表
#include "Linked_Lists.h" // 线性链表
#include "Stack_Linear.h" // 堆栈 顺序存储结构
#include "Stack_Linked.h" // 堆栈 链式存储结构
#include "Queue_Linear.h" // 队列 顺序存储结构
#include "Queue_Linked.h" // 队列 链式存储结构

int main(){
    
    // 线性链表
    LinkList list = create(4);
    list = insertFromFirst(list, "sdf"); // 在链表首位插入一个node
    int l = length(list); // 获取长度
    printf("%d\n", l);
    
    // 堆栈 顺序存储结构
    initial_linear(pTop, -1); // top 初始化为 -1
    push_linear(stack, pTop, 'a');
    printf("%d\n", top);
    
    // 堆栈 链式存储结构
    stack_linked_initial(top_stlink);
    
    // 队列 顺序存储结构
    
    // 队列 链式存储结构
    
    // 练习1
    
    return 1;
}


