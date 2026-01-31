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



//两个数组间的距离值
int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int i, j, count = 0;
    for (i = 0; i < arr1Size; i++) {
        for (j = 0; j < arr2Size; j++) {
            if (abs(arr1[i] - arr2[j]) <= d) {
                break;
            }
        }
        if (j == arr2Size) count++;
    }
    return count;
}
//找出临界点之间的最小和最大距离
struct ListNode {
    int val;
    struct ListNode* next;
};
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* Distace = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    Distace[0] = 100000, Distace[1] = -1;
    struct ListNode* p = head;
    int listlen = 1;
    while (p->next && p->next->next) {
        if ((p->val < p->next->val && p->next->next->val < p->next->val) || (p->val > p->next->val && p->next->next->val > p->next->val)) {
            p = p->next;
            listlen++;
            break;
        }
        p = p->next;
        listlen++;
    }
    int minlen = 0, maxlen = 0;
    while (p->next && p->next->next) {
        if ((p->val < p->next->val && p->next->next->val < p->next->val) || (p->val > p->next->val && p->next->next->val > p->next->val)) {
            listlen++;
            minlen++;
            maxlen++;
            if (minlen < Distace[0]) {
                Distace[0] = minlen;
            }
            Distace[1] = maxlen;
            minlen = 0;
            p = p->next;
        }
        else
        {
            p = p->next;
            minlen++;
            maxlen++;
            listlen++;
        }
    }
    if (listlen < 3 || Distace[1] == -1) {
        Distace[0] = -1;
        return Distace;
    }
    else {
        return Distace;
    }
}
//合并零之间的节点
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* p = head, * q = head->next, * temp;
    int sum;
    while (1)
    {
        while (q->val != 0)
        {
            q = q->next;
        }
        sum = 0;
        while (p->next != q)
        {
            sum += p->next->val;
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum;
        p->next = temp;
        temp->next = q;
        p = q;
        q = q->next;
        if (!q)
        {
            break;
        }
    }
    temp = head;
    head = head->next;
    free(temp);
    p = head;
    while (p) {
        temp = p->next;
        p->next = p->next->next;
        free(temp);
        p = p->next;
    }

    return head;
}




int main(void) {


    
    getchar();
    return 0;
}