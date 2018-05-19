#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int i, k = 0, f = 0;
    for (i=0;i<strlen(s)-1;i++){
        if (((int)s[i]!=32) && (f==0)){
            k++;
            f = 1;
        }
        if (((int)s[i]==32)&&(f==1))
            f = 0;
    }
    return k;
}

int main()
{
    char s[100];
    gets(s);
    printf("%d", wcount(s));
    return 0;
}
