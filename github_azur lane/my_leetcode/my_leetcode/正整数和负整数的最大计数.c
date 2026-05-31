#include<stdio.h>
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