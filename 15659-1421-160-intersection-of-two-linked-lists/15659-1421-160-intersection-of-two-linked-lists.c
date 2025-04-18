/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //----------------
    // Empty lists cannot be intersected
    if (!headA || !headB){
        return NULL;
    }
    //----------------
    struct ListNode *A = headA;
    struct ListNode *B = headB;
    struct ListNode *start_A = headA;
    struct ListNode *start_B = headB;

    while (start_A -> next != NULL || start_B -> next != NULL){
        if (A -> next == NULL){
            start_B = start_B -> next;
            A = start_A;
            B = start_B;
            continue;
        }
        if (B -> next == NULL){
            start_A = start_A -> next;
            // printf("startA %d", start_A -> val);
            A = start_A;
            B = start_B;
            continue;
        }
        if (A == B){
            return A;
        }
        A = A -> next;
        B = B -> next;
    }
    // last elements can still be same
    if (start_A == start_B){
        return start_A;
    }
    return NULL;
}