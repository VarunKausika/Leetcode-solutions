int minimumPairRemoval(int* nums, int numsSize) {
    if (numsSize == 0 || numsSize == 1){
        return 0;
    }

    int min = 2001;
    int end = numsSize;
    int first, ind, i;
    int count = 0;
    bool not_asc_flag = false;
    while (true){
        for (i = 1; i < end; i++){
            if (nums[i] < nums[i-1]){
                not_asc_flag = true;
                break;
            }
        }
        if (not_asc_flag == false){
            return count;
        }
        else {
            not_asc_flag = false;
        }
        min = nums[end-1] + nums[end-2];
        ind = end - 2;
        for(i=end-2; i > 0; i--){
            if (nums[i] + nums[i-1] <= min){
                min = nums[i] + nums[i-1];
                ind = i-1;
            }
        }
        nums[ind] = min;
        count++;
        for (i = ind+2; i < end; i++){
            nums[i-1] = nums[i];
        }
        end--;
        min = nums[end-1] + nums[end-2];
    }
}