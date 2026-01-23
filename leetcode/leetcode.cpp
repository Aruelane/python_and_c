#include<stdio.h>
#include<math.h>
#include <cstdlib>
#include <algorithm>

//正整数和负整数的最大计数
int maximumCount(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;
    int m, neg, pos;

    // 如果数组全是正数或负数，直接返回数组大小
    if (nums[0] > 0 || nums[numsSize - 1] < 0)
        return numsSize;

    // 二分查找负数的边界
    while (low <= high) {
        m = (low + high) / 2;
        if (nums[m] < 0 && nums[m + 1] >= 0) {
            break;
        }
        else if (nums[m] < 0) {
            low = m + 1;
        }
        else {
            high = m - 1;
        }
    }
    neg = m + 1;

    // 二分查找正数的边界
    low = m + 1;
    high = numsSize - 1;
    while (low <= high) {
        m = (low + high) / 2;
        if (nums[m - 1] <= 0 && nums[m] > 0) {
            break;
        }
        else if (nums[m] == 0) {
            low = m + 1;
        }
        else {
            high = m - 1;
        }
    }
    pos = numsSize - m;

    // 根据特殊情况判断返回值
    if (nums[neg - 1] == 0 && nums[numsSize - 1] > 0) {
        return pos;
    }
    if (nums[neg - 1] < 0 && nums[pos - 1] == 0) {
        return neg;
    }
    if (nums[neg - 1] == 0 && nums[pos - 1] == 0) {
        return 0;
    }

    // 返回正负数中较大的数量
    return pos > neg ? pos : neg;
}
//与对应负数同时存在的最大正整数
int findMaxK(int* nums, int numsSize) {
    int* arr_pos = (int*)malloc(sizeof(int) * 1001);
    int* arr_neg = (int*)malloc(sizeof(int) * 1001);
    int i;
    for (i = 0; i < 1001; i++) {
        arr_neg[i] = 0;
        arr_pos[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            arr_pos[nums[i]] = 1;
        }
        else {
            arr_neg[-nums[i]] = 1;
        }
    }
    for (i = 1000; i >= 0; i--) {
        if (arr_neg[i] == 1 && arr_pos[i] == 1) {
            return i;
        }
    }
    return -1;
}


//二进制链表转整数
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    struct ListNode* p = head;
    int i = 0, sum = 0, len = 0;
    while (p) {
        p = p->next;
        len++;
    }
    p = head;
    while (p) {
        sum += (int)pow(2.0, (float)(len - i - 1)) * p->val;
        p = p->next;
        i++;
    }
    return sum;
}










int main(void) {


    
    getchar();
    return 0;
}