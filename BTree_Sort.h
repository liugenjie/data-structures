//
//  BTree_Sort.h
//  Data Structures
//
//  Created by 刘根杰 on 08/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

/*********** 二叉排序树 **********
 二叉排序树或者为空二叉树，或者为具有以下性质的二叉树：
 1 若根结点的左子树不空，则左子树上所有结点的值都小于根结点的值；
 2 若根结点的右子树不空，则右子树上所有结点的值都大于或者等于根结点的值
 3 每一棵子树分别也是二叉排序树
 ****************************/

#ifndef BTree_Sort_h
#define BTree_Sort_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GET_ARRAY_LEN(array,len){len = sizeof(array) / sizeof(array[0]);}

// 二叉排序树 二叉链式存储 结构定义
typedef struct bsnode {
    int data;
    struct bsnode *lchild, *rchild;
}BSTNode, *BSTREE;

// 插入一个数据（逐点s插入法）data 要插入的数据
BSTREE bstree_sort_add (BSTREE T, int data) {
    BSTREE p = (BSTREE)malloc(sizeof(BSTNode)); // 新建一个新结点
    p->data = data; // data 是数字，不用 strcpy 函数
    p->lchild = NULL;
    p->rchild = NULL;
    if (T == NULL) {  // 如果是空树，新结点就是根结点
        T = p;
    } else {
        BSTREE q = T;
        while (1) {
            if (data < q->data ) {
                if (q->lchild == NULL) {
                    q->lchild = p;
                    break; // 跳到 while 之外。
                } else {
                    q = q->lchild;
                }
            } else {
                if (q->rchild == NULL) {
                    q->rchild = p;
                    break;
                } else {
                    q = q->rchild;
                }
            }
        }
        
    }
    return T;
}

// 新建一个二叉排序树  data 需要生成二叉排序树的所有数据
BSTREE bstree_sort_create (int data[]) {
    BSTREE T = NULL;
    int i;
    int n = sizeof(&data) / sizeof(data[0]); // 获取数组的长度, 也可以在宏中定义
    //GET_ARRAY_LEN (&data, n); // 获取数组的长度，GET_ARRAY_LEN 在宏中定义
    for (i = 0; i < n; i ++) {
        T = bstree_sort_add(T, data[i]);
    }
    return T;
}

// 删除一个数据

// 查找一个数据


#endif /* BTree_Sort_h */
