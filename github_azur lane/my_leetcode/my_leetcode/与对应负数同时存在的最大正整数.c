#include<stdio.h>
#include<stdlib.h>
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