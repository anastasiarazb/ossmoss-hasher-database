#include <string.h>
#include <stdio.h>

  int wcount(char *s)
  {
    int n,i,k,m=0;


    k=strlen(s);
    n=0;

    if (s[0]>='a' && s[0]<='z')
      n=n+1;
    for (i=1; i< k-1;i++) 
    {
    if ((s[i]==' ') && (s[i+1]!=' '))
      n=n+1;
    }

    for (i=0; i<k; i++) 
    { 
      if (s[i]>='a' && s[i]<='z') 
      { 
      m++;
      }
    }
    if (m==0)  
      n=0;
      
  return n;
  }


int main () 
{

  char ctr[100000]; 
  printf("%d\n", wcount(gets(ctr)));
  return 0;
}