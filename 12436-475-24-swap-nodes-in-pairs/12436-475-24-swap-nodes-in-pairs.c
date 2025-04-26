/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || head -> next == NULL){
        return head;
    }
    struct ListNode *prev = head;
    struct ListNode *curr = head -> next;
    struct ListNode *before_box = NULL;
    struct ListNode *after_box = head -> next -> next;
    while (true){
        if (before_box != NULL){
            before_box -> next = curr;
        }
        else {
            head = curr;
        }
        after_box = curr -> next;
        curr -> next = prev;
        prev -> next = after_box;
        before_box = prev;
        prev = prev -> next;
        if (prev == NULL || prev -> next == NULL){
            break;
        }
        else{
            curr = prev -> next;
        }
    }
    return head;
}