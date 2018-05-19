#include <stdio.h>

int wcount(char *s)
{
    int i=1,n=0;
    if (s[0]==0) return 0;
    if (s[0]!=' ') n++;
    while (s[i]!=0)
    {
          if ((s[i]!=' ') && (s[i-1]==' '))       
             n++;
          i++;   
    }      
    return n;
}

int main ()
{
    char s[255];
    gets (s);
    printf("%d\n", wcount(s));
        return 0;
}
