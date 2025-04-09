/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    int *new_digits = (int*)malloc(digitsSize*sizeof(int));
    new_digits = digits;
    if (new_digits[digitsSize-1] == 9){
        int count = 1;
        while (new_digits[digitsSize-count]==9){
            new_digits[digitsSize-count] = 0;
            if (count == digitsSize){
                break;
            }
            count++;
        }
        if (new_digits[0] == 0){
            *returnSize = digitsSize+1;
            new_digits = realloc(new_digits, (*returnSize)*sizeof(int));
            new_digits[digitsSize] = 0;
            new_digits[0] = 1;
        }
        else {
            new_digits[digitsSize-count]++;
        }
    }
    else {
        new_digits[digitsSize-1]++;
    }
    return new_digits;
}