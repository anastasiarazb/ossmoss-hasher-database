
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
int wcount(char* s) {
    int k = 0, answer = 0;
    while (*s) {
        if (!isspace(*s)) {
            k++;
        } else {
            if (k > 0) {
               answer++;
            }
            k = 0;
        }
        s++;
    }
    return answer;
}



int main() {
        char* s = malloc(N * sizeof(char));
        fgets(s, N, stdin);
        printf("%d\n", wcount(s));
        free(s);
	return 0;
}
