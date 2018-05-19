#include <stdio.h>
#include <string.h>

int wcount2(char *s) {
        int count = 0;
        for (int i = 0; i < strlen(s); i++) {
                if (s[i] != ' ') {
                        count++;
                        while(s[i] != ' ' && i++ < strlen(s)) {}
                }
        }
        return count;
}

int wcount(char *s) {
        int count = 0;
        char *p = strtok(s, " ");
        while (p != NULL) {
                count++;
                p = strtok(NULL, " ");
        }
        return count;
}

int main() {
    char *s = calloc(50, sizeof(char));
    gets(s);
    int out = wcount(s);
    int out2 = wcount(s);
    if (out == out2) {
            int ans = (out + out2) / 2;
            printf("%d\n", ans);
    } 
    free(s);
    return 0;
}