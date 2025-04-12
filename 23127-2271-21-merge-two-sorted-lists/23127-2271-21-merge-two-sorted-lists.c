/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1){
        return list2;
    }
    else if (!list2){
        return list1;
    }
    struct ListNode *start;
    struct ListNode *erased;
    if (list1 -> val <= list2 -> val){
        start = list1;
        erased = list2;
    }
    else {
        start = list2;
        erased = list1;
    }
    struct ListNode *temp_start = start;
    struct ListNode *next = start -> next;
    while (next) {
        if (erased -> val < next -> val){
            start -> next = erased;
            erased = next;
        }
        start = start -> next;
        next = start -> next;
    }
    start -> next = erased;
    return temp_start;
}