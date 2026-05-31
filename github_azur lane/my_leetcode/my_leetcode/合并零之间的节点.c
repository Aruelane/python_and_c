#include<stdio.h>
#include<stdlib.h>
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