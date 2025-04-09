#include <stdio.h>
#include <stdlib.h>

int compare_integers(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int minOperations(int* nums, int numsSize, int k) {
    int *sort_these = (int*)malloc((numsSize+1)*sizeof(int));
    for (int i = 0; i<numsSize; i++){
        sort_these[i] = nums[i];
    }
    sort_these[numsSize] = k;
    qsort(sort_these, numsSize+1, sizeof(int), compare_integers);
    if (sort_these[0] != k){
        return -1;
    } 
    else{
        int last_int = sort_these[1];
        int count = 0;
        for (int i=2; i < numsSize+1; i++){
            if (sort_these[i] != last_int){
                count++;
                last_int = sort_these[i];
            }
        }
        count = (k<sort_these[1]) ? count+1 : count;
        return count;
    }
}