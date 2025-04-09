#include <ctype.h>

int lengthOfLastWord(char* s) {
    int pos = strlen(s)-1;
    bool flag = false;
    int count = 0;

    while (true){
        if (pos == -1){
            return count;
        }
        if (isalpha(s[pos])){
            count++;
            flag = true;
        }
        if (s[pos] == ' ' && flag){
            return count;
        }
        pos--;
    }
}