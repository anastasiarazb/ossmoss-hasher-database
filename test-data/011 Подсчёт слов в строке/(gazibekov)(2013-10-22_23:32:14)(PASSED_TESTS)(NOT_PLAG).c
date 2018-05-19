#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
    int n = 0, i;
    for(i = 0; i < strlen(s); i++)
        if(s[i] != ' '){
            n++;
            while ((s[i] != ' ') && (s[i] != '\0'))
                i++;
        }
    return n;
}

int main()
{
    int i;
    char *s = (char*) malloc(50*sizeof(char));
    gets(s);
    i = wcount(s);
    printf("%d\n", i);
    free(s);;
    return 0;
}