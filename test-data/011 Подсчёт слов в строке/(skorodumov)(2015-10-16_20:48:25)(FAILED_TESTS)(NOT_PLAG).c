#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
   char s[100];
   gets(s);
   printf("%d", wcount(s));
   return 0;
}

int wcount(char *s)
{
    int i,count = 0;
    if (s[0] != ' ') count = 1;
    for (i = 1; i < strlen(s)-1; i++) {
        if (s[i] == ' '  && s[i+1] != ' ') count++;
    }
    return count;
}

