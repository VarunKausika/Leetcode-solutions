int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize-1;
    if (target > nums[numsSize-1]){
        return numsSize;
    }
    else if (target < nums[0]){
        return 0;
    }
    if (numsSize > 1){
        while (high > low){
            if (target < nums[(high+low)/2]){
                high = (high + low)/2;
            }
            else if (target == nums[(high+low)/2]){
                return (high + low)/2;
            }
            else {
                low = (high + low)/2 + 1;
            }
        }
        return high;
    }
    else {
        if (target <= nums[0]){
            return 0;
        }
        else {
            return 1;
        }
    }
}