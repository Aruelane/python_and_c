#include<stdio.h>
#include<stdlib.h>
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
