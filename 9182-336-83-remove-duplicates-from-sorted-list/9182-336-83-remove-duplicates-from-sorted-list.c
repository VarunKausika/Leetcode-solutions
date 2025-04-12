/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head || head -> next == NULL){
        return head;
    }
    struct ListNode *curr = head;
    struct ListNode *next;
    while (curr -> next != NULL){
        if (curr -> next -> val == curr -> val){
            next = curr -> next;
            curr -> next = next -> next;
            free(next);
        }
        else {
            curr = curr -> next;
        }
    }
    return head;
}