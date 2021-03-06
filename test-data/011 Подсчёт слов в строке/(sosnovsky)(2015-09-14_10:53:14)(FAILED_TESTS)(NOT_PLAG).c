#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1000000

int len;

int wcount(char* s) {
    int ret = 0;
    for(int i = 0; i < len - 1; i++) {
        if((s[i] == ' ' || (i == 0 && s[i] != ' ')) && s[i + 1] != ' ') {
            ret++;
//            printf("%d:%d:%d\n", i, s[i], s[i + 1]);
        }
    }
    return ret;
}

int main() {
    char* buf = malloc(BUF_SIZE * sizeof(char));
    len = 0;

    char cur;
    for(int i = 0; i < BUF_SIZE; i++) {
        cur = getchar();
        if(cur != EOF && cur != '\n') {
            buf[i] = cur;
            len++;
        }
        else {
            break;
        }
    }

    printf("%d", wcount(buf));
}
