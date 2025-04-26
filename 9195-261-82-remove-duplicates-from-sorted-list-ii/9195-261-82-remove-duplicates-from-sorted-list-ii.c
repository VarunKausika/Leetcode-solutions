/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    while(true){
        if (!curr || curr -> next == NULL){
            break;
        }
        // This means that either node and node +1 are same or unique 
        if (curr -> next -> next == NULL){
            if (curr -> next -> val == curr -> val){
                if (prev == NULL){
                    return NULL;
                }
                else {
                    prev -> next == NULL;
                    break;
                }
            }
            else{
                // both are unique
                break;
            }
        }
        if (curr -> val != curr -> next -> val && curr -> next -> val != curr -> next -> next -> val){
            curr = curr -> next;
            prev = curr;
        }
        else if (curr -> val != curr -> next -> val && curr -> next -> val == curr -> next -> next -> val){
            prev = curr;
            struct ListNode *delete = curr -> next;
            int delete_val = delete -> val;
            while (delete != NULL && delete -> val == delete_val){
                delete = delete -> next;
            }
            // delete has moved past all the dupes
            curr -> next = delete;
        }
        else if (curr -> val == curr -> next -> val){
            struct ListNode *delete = curr;
            int delete_val = delete -> val;
            while (delete != NULL && delete -> val == delete_val){
                delete = delete -> next;
            }
            // delete has moved past all the dupes
            if (prev == NULL){
                head = delete;
                curr = delete;
            }
            else {
                prev -> next = delete;
                curr = delete;
            }
        }
    }
    return head;
}

/* there are 3 cases. 
1. node and node + 1 have different values and node + 1 is unique - move node to node + 1
2. node and node + 1 have same values - skip all dupes with this value
3. node and node + 1 have different values and node + 1 is not unique - move node to node + x (skip dupes)
*/