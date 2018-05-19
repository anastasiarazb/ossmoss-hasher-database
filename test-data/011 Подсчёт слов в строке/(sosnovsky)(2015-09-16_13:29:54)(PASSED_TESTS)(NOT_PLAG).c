#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1000000

int len;

int wcount(char* s) {
    int ret = 0;

    for(int i = 0; i < len; i++) {
        if((i - 1 < 0 || s[i - 1] == ' ') && (s[i] != ' ')) {
            ret++;
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

    printf("%d\n", wcount(buf));

    /*for(int i = 0; i < len; i++) {
        printf("%d ", buf[i]);
    }*/

    free(buf);
}
