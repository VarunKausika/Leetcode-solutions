/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // if linked list is 0 or 1 elements long there are no cycles
    if (!head || head -> next == NULL){
        return false;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (true) {
        slow = slow -> next;
        fast = fast -> next;
        // fast has reached end of list, no cycles
        if (fast == NULL){
            return false;
        }
        fast = fast -> next;
        // fast has reached end of list, no cycles
        if (fast == NULL){
            return false;
        }
        // fast moves by 2, slow moves by 1. If there is a cycle, eventually slow should meet fast
        if (slow == fast){
            return true;
        }
    }
}   