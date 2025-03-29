#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }
    else {
        int tmp = x;
        int ndigits = 0;
        while (tmp > 0){
            tmp/=10;
            ndigits++;
        }
        printf("ndigits %d", ndigits);
        int *reverseDigits= (int*)malloc(ndigits*sizeof(int));
        for (int i = 0; i < ndigits; i++){
            reverseDigits[i] = x - (x/10)*10;
            x/=10;
        }
        for (int i = 0; i < ndigits; i++){
            if (reverseDigits[i] != reverseDigits[ndigits - 1 - i]){
                return false;
            } 
        }
        return true;
    }
}