#include <stdio.h>

int wcount(char *s)
{
        int i, k = 0, n = strlen(s);

        for(i=0; i<n; i++)
        {
                if ((i==0)&&(s[i]!=' '))
                { 
                        k++;
                }
                else if ((s[i-1]==' ')&&(s[i]!= ' '))
                {
                        k++;
                }
        }
        return k;
}
             
int main(int argc, char *argv[])
{
    int a;
    
    char s[999];
    
    gets(s);
    
    a = wcount(s);
    
    printf("%d", a);         
    return 0;
}
