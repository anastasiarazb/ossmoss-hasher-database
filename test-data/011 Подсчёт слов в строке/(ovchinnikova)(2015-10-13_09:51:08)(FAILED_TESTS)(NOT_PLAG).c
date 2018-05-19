#include <stdio.h>
 
int main()
{
    char s[100];
    gets(s);
    printf("%d/n",wcount(s));
}
   
   
int wcount(char *s)
{
    int i,d,k=0;
     d = strlen(s);
    for (i = 0; i < d; i++){
        if ((s[i] == ' ')&&(s[i-1] != ' '))
            k+=1;
    }
    if ((k != 0)&&(s[d-1]!=' ')) k+=1;
   return k;
}
