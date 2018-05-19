#include <stdio.h>

int wcount(char *s)
{
    int i, k;
    
    for(i=0; i<999; i++)
    {
              if ((s[i-1]==' ')&&(s[i]!=' '))
              {
                             k++;
              }
              
              else if ((i==0)&&(s[i]!=' '))
              {     
                             k++;
              }
              
              else if (s[i]==0)
              {
                            return k;
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
    system("PAUSE");        
    return 0;
}
