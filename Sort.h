//
//  Sort.h
//  Data Structures
//
//  Created by 刘根杰 on 08/12/2017.
//  Copyright © 2017 刘根杰. All rights reserved.
//

#ifndef Sort_h
#define Sort_h

#include <stdio.h>

// 选择排序、快速排序、希尔排序、堆排序不是稳定的排序算法
// 冒泡排序、插入排序、归并排序和基数排序都是稳定的排序算法。

void sort_output (int * data, int len, char sort_name[]);

// 插入排序法
// 原始序列是递增序列，需要经过 n-1 次比较，复杂度是 O(n)
// 原始序列是递减序列，需要经过 n(n-1)/2 次比较，复杂度是 O(n^2)
// 是稳定性排序法
void sort_insert (int * data, int len) {
    int i; // 第0个数，第1个数 ...
    int j; // 插入数的循环
    int temp; // 临时折腾数据用
    for (i = 1; i < len; i++) {
        temp = data[i]; // 准备把第 i 个数据通过此法插入到合适的位置
        j = i - 1; // i 是这个数自己，所以要减去 1
        while (j >= 0 && temp < data[j]) {
            data[j+1] = data[j]; // 如果被比较的数字比 temp 大，那么它就应该放到 temp 的后面去
            j--;  // 从 j 往前循环
        }
        data[j+1] =  temp; // 把 temp 放在正确的位置
    }
    sort_output(data, len, "insert sort");
}

// 折半插入排序法
void sort_bininsert (int * data, int len) {
    int i; // 第0个数，第1个数 ...
    int high, low, mid; // 用于折半插入判断
    int j; // 找到位置后用于挪数据
    int temp; // 临时折腾数据用
    for (i = 1; i < len; i++) {
        temp = data[i]; // 准备把第 i 个数据通过此法插入到合适的位置
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (temp < data[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j=i-1; j>=low; j--) { // 找到位置后挪数据，把位于 low 的位置空出来
            data[j+1] = data[j];
        }
        data [low] = temp; // low 所在位置就是 temp 应该在的地方
    }
    sort_output(data, len, "bininsert sort");
}

// 选择排序法
// 若原始序列是递增序列，比较次数是 n(n-1)/2 复杂度是 O(n^2)
// 若原始序列是递减序列，比较次数是 n(n-1)/2 复杂度是 O(n^2)
// 是不稳定性排序法
void sort_select (int * data, int len) {
    int i; // 第0个数，第1个数 ...
    int j; // 用于取最小值时的循环
    int temp; // 用于存放最小值的位置
    int temp1; // 用于存放最小值
    for (i = 0; i < len; i++) {
        temp = i;   // 最小值是这么比较出来的
        for (j=i; j<len; j++) {
            if (data[j] < data[temp]) {
                temp = j;  // 最小值是这么比较出来的
            }
        }
        if (temp != i) { // 最小的不是未排序的第一个时才执行对调
            temp1 = data[temp]; // 把最小值先临时放这里
            data[temp] = data[i]; // 把 i 处的值给有最小值的那个地方
            data[i] = temp1; // 把最小值给 i 的地方
        }
    }
    sort_output(data, len, "select sort");
}

// 泡排序法
// 排序的趟数不是确定的，是一个范围 【1:n-1】之间
// 复杂度是 O(n^2)
// 是稳定性排序法
void sort_bubble (int * data, int len) {
    int n; // 每一趟要循环到的最大位置
    int i; // 每一趟循环标识
    int flag = 1; // 用于标识某一趟中是否对调过元素，0 没有对调过，1 对调过，如果为 0 就意味着顺序都已经排好
    int temp; // 用于存放临时最大值
    n = len - 1; // 第一趟所要循环到的最大位置
    while (n > 0 && flag == 1) {
        flag = 0; // 先初始化为0，希望这一趟中顺序已经是排好的。如果这样 flag 就还是0，那么下一趟 while 循环就不会再进来了。
        for (i = 0; i < n; i++) {
            if (data[i] > data[i+1]) { // 两两比较，如果前面大于后面的，就两两对调
                temp = data[i]; // 把大的，先临时放这里
                data[i] = data[i+1]; // 小的，放前面
                data[i+1] = temp; // 大的，放后面
                flag = 1; // 这一趟对调过，标识下
            }
        }
        n--; // 下一趟的最大位置
    }
    sort_output(data, len, "bubble sort");
}

// 谢尔排序法
// 排序的趟数:  log_2_n
// 复杂度是在 O(nlog_2_n) 与 O(n2) 之间
// 非稳定性排序法
void sort_shell (int * data, int len) {
    int i; // 不同的子循环之间的循环标识
    int j; // 子循环中的循环标识
    int gap = len; // gap
    int flag = 1; // 用于标识子排序中是否对调过元素，0 没有对调过，1 对调过，如果为 0 就意味着这个子排序中的顺序都已经排好
    int temp; // 用于存放临时最大值
    while (gap > 1) {
        gap = gap / 2;
        do {
            flag = 0;
            for (i=1; i<len-gap; i++) {
                j=i+gap;
                if (data[i] > data[j]) {
                    temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                    flag = 1;
                }
            }
        } while (flag!=0);
    }
    sort_output(data, len, "shell sort");
}

// 快速排序法
// 每一次至少可以确定一个元素的最终位置
// 复杂度是在 O(nlog_2_n)
// 不是稳定的排序算法

// 堆积排序法
// 完全二叉树
// 不是稳定的排序算法

// 二路归并排序法 略


// 打印数组中数据
void sort_output (int * data, int len, char sort_name[]) {
    int i;
    char token = 0x0;
    printf("%s: ", sort_name);
    for (i=0; i<len; i++) {
        printf("%c%d", token, data[i]);
        token = ',';
    }
    printf("\n");
}

#endif /* Sort_h */
