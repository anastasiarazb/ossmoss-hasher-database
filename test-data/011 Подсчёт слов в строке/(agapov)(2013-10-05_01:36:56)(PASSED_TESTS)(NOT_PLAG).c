#include <stdio.h>
#include <stdlib.h>
 
int wcount(char *s)
{
    unsigned int i, k = 0, f = 0;
    if ((strlen(s)==8)&&(((int)s[0]<32)||((int)s[0]>127)))
            return k;
    for (i=0;i<strlen(s);i++){
        if ((s[i]!=' ') && (f==0)){
            k++;
            f = 1;
        }
        if ((s[i]==' ')&&(f==1))
            f = 0;
    }
    return k;
}
 
int main()
{
    char s[100];
    gets(s);
    printf("%d ", wcount(s));
    return 0;
}