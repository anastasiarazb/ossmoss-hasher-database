#include <stdio.h>
#include <string.h>
int wcount(char *s);
#define MAX 300
int main(int argc, const char * argv[])
{
    char s[MAX];
    int answer;
    fgets(s, MAX, stdin);
    s[strlen(s)-1] = '\0';
    answer = wcount(s);
    printf("%d\n", answer);
}


int wcount(char *s)
{
    int i, count;
    count = 0;
    unsigned long length;
    length = strlen(s);
    s[length] = ' ';
    for (i = 0; i < length; ++i){
       if((s[i] != ' ') && (s[i+1] == ' '))
           count++;
    }
    return (count);
}

