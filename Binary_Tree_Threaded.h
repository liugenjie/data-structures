//
//  BTree_threaded.h
//  Data Structures
//
//  Created by 刘根杰 on 08/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

/***********  线索二叉树 **************
 利用链接点的空的左指针域存放该结点的直接前驱的地址，空的右指针域存放该结点直接后继的地址；而非空的指针域仍然存放结点的左孩子或右孩子的地址。
 直接前驱和直接后继，均指各种遍历中的前驱和后继。
 *************************/

#ifndef BTree_threaded_h
#define BTree_threaded_h

#include <stdio.h>

// 线索二叉树 二叉链式存储+线索判断 结构定义
// lbit 为 1 则 lchild 是左孩子指针，为 0 则 lchild 是前驱指针；rbit 为 1 则 rchild 是右孩子指针，为 0 则 rchild 是后继指针；
typedef struct lbnode {
    char data[100];
    struct lbnode *lchild, *rchild;
    int *lbit, *rbit;
}TBTNode, *TBTREE;

#endif /* BTree_threaded_h */
