#include <stdlib.h>
//  Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    long long number1 = 0;
    long long number2 = 0;
    long long multiplier = 1;
    struct ListNode* current = l1;

    do{
        number1 += (current->val)*multiplier;
        multiplier *= 10;
        current = (current->next);
    }while(current != NULL);

    struct ListNode* current2 = l2;
    long long multiplier2 = 1;
    do{
        number2 += (current2->val)*multiplier2;
        multiplier2 *= 10;
        current2 = (current2->next);
    }while(current2 != NULL);

    long long sum = number1 + number2;
    struct ListNode *head = NULL, *tail = NULL;
    if(sum == 0) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = sum;
        node->next = NULL;
        head = node;
    } else {
        while(sum){
            struct ListNode *node = malloc(sizeof(struct ListNode));
            node->val = sum % 10;
            node->next = NULL;
            if (!head) head = tail = node;
            else { tail->next = node; tail = node; }
            sum /= 10;
        }
    }  
    return head;
}