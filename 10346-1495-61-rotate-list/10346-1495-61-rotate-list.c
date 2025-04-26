/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || head -> next == NULL || k == 0){
        return head;
    }
    // first, make the list circular
    struct ListNode *tmp = head;
    int count = 0;
    while (tmp -> next != NULL){
        tmp = tmp -> next;
        count++;
    }
    count++;
    tmp -> next = head;
    tmp = head;
    int traverse = count - k;
    while(traverse <= 0){
        traverse += count;
    }
    // next, traverse the list (traverse places and cut)
    for (int i = 0; i < traverse - 1; i++){
        tmp = tmp -> next;
    }
    head = tmp -> next;
    tmp -> next = NULL;
    return head;
}