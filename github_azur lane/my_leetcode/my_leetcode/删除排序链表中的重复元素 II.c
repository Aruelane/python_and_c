#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head)
        return head;
    struct ListNode* p = head, * q;
    int* arr = (int*)malloc(sizeof(int) * 201);
    int i;
    for (i = 0; i < 201; i++) {
        arr[i] = 0;
    }
    while (p) {
        if (arr[p->val + 100] == 0) {
            arr[p->val + 100] = 1;
        }
        else if (arr[p->val + 100] == 1) {
            arr[p->val + 100] = 2;
        }
        p = p->next;
    }
    p = head, q = head;
    int flag = 0;
    for (i = 0; i < 201; i++) {
        if (arr[i] == 1) {
            p->val = i - 100;
            p = p->next;
            flag = 1;
        }
    }
    if (flag == 0)return NULL;
    while (q && q->next != p) {
        q = q->next;
    }
    if (q) {
        q->next = NULL;
    }
    return head;
}