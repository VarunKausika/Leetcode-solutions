/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }
    struct ListNode* current = NULL;
    struct ListNode* next = head; 
    struct ListNode* two_next;
    while (next){
        two_next = next -> next;
        next -> next = current;
        current = next;
        next = two_next;
    }
    
    return current;
}