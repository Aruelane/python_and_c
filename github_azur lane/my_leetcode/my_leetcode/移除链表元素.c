#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p = head, * temp;
    if (head == NULL)return head;
    while (head != NULL && head->val == val) {
        temp = head;
        head = head->next;
        free(temp);
    }
    if (!head)return head;
    p = head;
    while (p->next) {
        if (p->next->val == val) {
            p->next = p->next->next;
        }
        else {
            p = p->next;
        }
    }
    return head;
}