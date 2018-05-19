#include <stdio.h>
#include <string.h>

int wcount(char *string) {
    int answer = 0;
    char *ptr = strtok(string, " \t\v\f\r\n");
    while (ptr) {
        ptr = strtok(0, " \t\v\f\r\n");
        answer++;
    }
    return answer;
}

int main() {
    char string[128];
    fgets(string, 128 stdin);
    printf("%d\n", wcount(string));
    return 0;
}
