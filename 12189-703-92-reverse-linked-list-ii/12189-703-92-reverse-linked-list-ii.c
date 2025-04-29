/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (left == right){
        return head;
    }
    if (left == 1){
        // In this case, we have to start reversing from the first node
        struct ListNode *curr = head -> next;
        struct ListNode *prev = head;
        struct ListNode *temp;
        for (int i = 0; i < (right - left); i++){
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        head -> next = curr;
        return prev;
    }
    else {
        // In this case, we have to traverse upto the before node and then start reversing
        struct ListNode *curr = head;
        struct ListNode *prev, *temp, *t, *before;
        for (int i = 0; i < (left - 2); i++){
            curr = curr -> next;
        }
        before = curr;
        prev = curr -> next;
        t = prev;
        curr = curr -> next -> next;
        for (int i = 0; i < (right - left); i++){
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        } 
        before -> next = prev;
        t -> next = curr;
        return head;
    }
}