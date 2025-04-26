/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    if (!head){
        int *return_arr = (int*)malloc(0);
        return return_arr;
    }

    int count = 0;
    struct ListNode *tmp = head;
    for(;tmp!=NULL;tmp=tmp->next, count++);
    free(tmp);
    *returnSize = count;
    
    struct ListNode *curr = head;
    struct ListNode *mover = head -> next;

    int *return_arr = (int*)malloc((*returnSize)*sizeof(int));
    count = 0;
    while (true){
        if (curr -> next == NULL){
            return_arr[count] = 0;
            break;
        }
        while(mover != NULL){
            if ((mover -> val) > (curr -> val)){
                return_arr[count] = mover -> val;
                curr = curr -> next; 
                if (curr -> next != NULL){
                    mover = curr -> next;                
                }
                count++;
                break;
            }
            else {
                mover = mover -> next;
            }
        }
        if (mover == NULL){
            return_arr[count] = 0;
            curr = curr -> next;
            if (curr -> next != NULL){
                mover = curr -> next;                
            }
            count++;
        }
    }
    return return_arr;
}