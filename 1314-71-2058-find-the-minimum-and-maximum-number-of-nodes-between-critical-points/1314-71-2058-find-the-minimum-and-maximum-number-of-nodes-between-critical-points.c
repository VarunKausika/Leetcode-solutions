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
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int *ret_arr = (int*)malloc(2*sizeof(int));
    if (!head || head -> next == NULL || head -> next -> next == NULL){
        ret_arr[0] = -1;
        ret_arr[1] = -1;
        return ret_arr;
    }
    struct ListNode *prev = head;
    struct ListNode *curr = head -> next;
    int first_pos = -1;
    int last_pos = 0;
    int prev_pos = 0;
    int min_dist = -1;
    int pos = 0;
    while (curr -> next != NULL){
        if ((curr -> val) < (prev -> val) && (curr -> val) < (curr -> next -> val) || (curr -> val) > (prev -> val) && (curr -> val) > (curr -> next -> val)){
            //local minimum or local maximum
            if (first_pos == -1){
                first_pos = pos;
                prev_pos = first_pos;
            }
            else{
                int dist = pos - prev_pos;
                if (min_dist == -1){
                    min_dist = dist;
                }
                else {
                    if (dist < min_dist){
                        min_dist = dist;
                    }
                }
                prev_pos = pos;
            }
            last_pos = pos;
        }
        prev = prev -> next;
        curr = curr -> next;
        pos++;
    }
    if (last_pos != first_pos && min_dist != -1){
        ret_arr[0] = min_dist;
        ret_arr[1] = last_pos - first_pos;
    }
    else {
        ret_arr[0] = -1;
        ret_arr[1] = -1;
    }
    return ret_arr;
}