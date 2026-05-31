#include<stdio.h>
#include<math.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

int getDecimalValue(struct ListNode* head) {
    struct ListNode* p = head;
    int i = 0, sum = 0, len = 0;
    while (p) {
        p = p->next;
        len++;
    }
    p = head;
    while (p) {
        sum += (int)pow(2.0, (double)(len - i - 1)) * p->val;
        p = p->next;
        i++;
    }
    return sum;
}
