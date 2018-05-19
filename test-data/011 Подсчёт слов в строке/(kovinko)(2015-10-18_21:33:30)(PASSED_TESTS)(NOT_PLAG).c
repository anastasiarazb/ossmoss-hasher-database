#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int i,n=0;
    for(i=0;i<strlen(s);){
        while(i<strlen(s) && s[i]==' ') {
            i++;
        }
        if(i<strlen(s)) n++;
        while(i<strlen(s) && s[i]!=' ') {
            i++;
        }
    }
    return(n);
}
int main(int argc, char **argv)
{
    char str[1000];
    gets(str);
    printf("%d", wcount(str));
    return(0);
}
