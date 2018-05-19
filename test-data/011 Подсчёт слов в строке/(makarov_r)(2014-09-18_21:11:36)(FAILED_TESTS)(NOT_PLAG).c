#include <stdio.h>
#include <string.h>
int wcount(char *s);
#define MAX 300
int main(int argc, const char * argv[])
{
    char s[MAX];
    fgets(s, MAX, stdin);
    printf("%d", wcount(s));
}


int wcount(char *s)
{
    int i, count;
    unsigned long length;
    length = strlen(s);
    s[length] = ' ';
    for (i = 0; i < length; ++i){
       if((s[i] != ' ') && (s[i+1] == ' '))
           ++count;
    }
    return (count);
}