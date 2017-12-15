//
//  Data_Structure.c
//  Data Structures
//
//  Created by 刘根杰 on 06/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#define GET_ARRAY_LEN(array,len){len = sizeof(array) / sizeof(array[0]);}

#include <stdio.h>
#include "Linear_Lists.h" // 线性顺序表
#include "Linked_Lists.h" // 线性链表
#include "Stack_Linear.h" // 堆栈 顺序存储结构
#include "Stack_Linked.h" // 堆栈 链式存储结构
#include "Queue_Linear.h" // 队列 顺序存储结构
#include "Queue_Linked.h" // 队列 链式存储结构
#include "BTree.h" // 二叉树
#include "BTree_Threaded.h" // 线索二叉树
#include "BTree_Sort.h" // 二叉排序树
#include "File.h" // 文件
#include "Sort.h" // 排序
#include "exercise1.h" // 练习1
#include "exercise2.h" // 练习2
#include "exercise3.h" // 练习3
#include "exercise4.h" // 练习4

int * array_test(int * d);

int main(){
    
    // 线性链表
    LinkList list = create(4);
    list = insertFromFirst(list, "sdf"); // 在链表首位插入一个node
    int l = length(list); // 获取长度
    
    // 堆栈 顺序存储结构
    initial_linear(pTop, -1); // top 初始化为 -1
    push_linear(stack, pTop, 'a');
    
    // 堆栈 链式存储结构
    stack_linked_initial(top_stlink);
    
    // 队列 顺序存储结构
    
    // 队列 链式存储结构
    
    // 二叉排序树
    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    int size;
    GET_ARRAY_LEN(data, size);
    BSTREE T = bstree_sort_create(data, size); // 新建一个二叉排序树
    
    // 二叉树遍历
    preOrder(T); // 前序遍历
    inOrder(T); // 中序遍历
    postOrder(T); // 后序遍历
    layerOrder(T); // 按层遍历
    
    // 文件
    
    // 排序
    int data2[] = {49, 38, 97, 76, 65, 13, 27, 50};
    int data2_len;
    GET_ARRAY_LEN(data2, data2_len);
    sort_output(data2, data2_len, "source data"); // 原数据
    sort_insert(data2, data2_len); // 插入排序法
    sort_bininsert(data2, data2_len); // 折半插入排序法
    sort_select(data2, data2_len); // 选择排序法
    sort_bubble(data2, data2_len); // 冒泡排序法
    sort_shell(data2, data2_len); // 希尔排序法
    
    // 练习1
    
    // 练习2
    
    // 练习3
    
    // 练习4
    
    return 1;
}



