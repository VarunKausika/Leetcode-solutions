/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head){
        return head;
    }
    while (head -> val == val && head -> next){
        head = head -> next;
    }
    if (head -> next == NULL){
        if (head -> val == val){
            return NULL;
        }
        else{
            return head;
        }
    }
    struct ListNode *prev = head;
    struct ListNode *curr = head -> next;

    while(curr != NULL){
        if (curr -> val == val){
            prev -> next = curr -> next;
            free(curr);
            curr = prev -> next;
        }
        else {
            prev = prev -> next;
            curr = curr -> next;
        }
    }
    return head;
}