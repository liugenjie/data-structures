//
//  Stack.h
//  Data Structures
//
//  Created by 刘根杰 on 07/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#define M 1000 // 定义常数，用作堆栈的长度

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack 的顺序存储结构
char stack[M]; // 栈，用数组，数据是单个字符
int top; // 栈顶元素的位置，从 0 开始计
int * pTop = &top;

// Stack 初始化, pTop 须是 top 的指针，x 是初始化的数值
int initial_linear(int * pTop, int x) { // 只能传入指针，操作指针
    *pTop = x;
    return 1;
}

// 是否为空
int empty_linear (int top) {
    return top == -1;
}

// 是否已满
int full_linear (int top) {
    return top == M - 1;
}

// 插入 data 要入栈的数据
int push_linear (char stack[], int * pTop, char data) {
    if(full_linear(top)){
        return -1;
    } else {
        // 栈顶推进一个
        *pTop += 1;
        int a = * pTop;
        stack[a] = data;
        return 1;
    }
}

// 删除 data 要出栈的数据
int delete_linear (char stack[], int * pTop, char data) {
    if (empty_linear(*pTop)) { // 如果栈空，直接返回 0
        return 0;
    } else { // 如果栈不空
        // 先判断 data 是否是最后一个，如果是，top 减去 1
        // 如果 data 是栈中间的一个，那么需要找到这个位置，stack 中的数据要以此挪移。
        return 1;
    }
}

/**
 多栈共享连续空间问题
*/
char stack2[M];
int ltop = -1;
int * pLtop = &ltop;
int rtop = M;
int * pRtop = &rtop;

// 多栈共享连接 入栈  data 是需要入栈的数据 ltop 是栈左侧位置 rtop 是栈右侧位置 i 为l是在左侧插入，为r时在右侧插入
int push_linear_multi (char stack2[], int * pLtop, int * pRtop, char i, char data) {
    if (*pLtop == *pRtop - 1) {  // 栈满了，两边就差一
        return -1;
    } else {
        if (i == 'l') {
            *pLtop += 1;
            int a = *pLtop;
            stack2[a] = data;
        } else {
            *pRtop -= 1;
            int b = *pRtop;
            stack2[b] = data;
        }
        return 1;
    }
}

// 多栈共享连接 出栈  data 是需要出栈的数据 ltop 是栈左侧位置 rtop 是栈右侧位置 i 为l是在左侧出，为r时在右侧出
int pop_linear_multi (char stack2[], int * pLtop, int * pRtop, char i, char data) {
    return 1;
}

#endif /* Stack_h */
