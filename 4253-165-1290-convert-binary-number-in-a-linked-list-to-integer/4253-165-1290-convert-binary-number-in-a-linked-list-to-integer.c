/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <math.h>
int getDecimalValue(struct ListNode* head) {
    if (head == NULL) {
        return 0;
    }
    else if (head -> next == NULL){
        return head -> val;
    }

    struct ListNode* current = NULL;
    struct ListNode* next = head; 
    struct ListNode* two_next;

    // First, reversing the linked list
    while (next){
        two_next = next -> next;
        next -> next = current;
        current = next;
        next = two_next;
    }
    free(next);
    free(two_next);

    // traversing and multiplying by powers of 2
    int sum = 0;
    int power = 0;
    while (current != NULL) {
        sum += (current -> val)*pow(2, power);
        power++;
        current = current -> next;
    }
    return sum;
}