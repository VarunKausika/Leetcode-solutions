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
    int *nums_encountered = (int*)malloc(sizeof(int));
    nums_encountered[0] = head -> val;
    int count = 1;
    int i;
    bool repeat_flag;
    struct ListNode *left = head;
    struct ListNode *temp_left = left;
    struct ListNode *right = head -> next;
    while (right != NULL){
        for (i = 0; i < count; i++){
            if(nums_encountered[i] == right -> val){
                repeat_flag = true;
                break;
            }
        }
        if (repeat_flag == true){
            //number in the right has already been encountered
            // we are moving the right pointer by 1 and skipping the repeated one
            left -> next = right -> next;
            free(right);
            right = left -> next;
            repeat_flag = false; 
        }
        else{
            // number in the right has not been encountered, need to append it to list
            // we are also moving left by 1 and right by 1
            nums_encountered = realloc(nums_encountered, (count + 1)*sizeof(int));
            nums_encountered[count] = right -> val;
            count++;
            left = right;
            right = right -> next;
        }
    }
    return temp_left;
}