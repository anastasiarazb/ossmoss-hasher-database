#include <stdio.h>
 
int main()
{
    char s[100];
    gets(s);
    printf("%d",wcount(s));
}
   
   
int wcount(char *s)
{
    int i,d,k=0;
     d = strlen(s);
    for (i = 1; i < d; i++){
        if ((s[i] == ' ')&&(s[i-1] != ' '))
            k+=1;
    }
    if (s[d-1]!=' ')  k+=1;
    if (d==0) k=0;
   return k;
}